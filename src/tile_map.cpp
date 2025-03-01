#include <SDL_image.h>
#include <algorithm>
#include <fstream>
#include <sstream>

#include "ErrorLogger.hpp"
#include "Rect.hpp"
#include "TileMap.hpp"
#include "Window.hpp"

namespace kn
{
TileMap::TileMap(const std::string& filePath, const int borderSize)
{
    if (!loadTMX(filePath, borderSize))
        throw Exception("Failed to load tile map");
}

bool TileMap::loadTMX(const std::string& filePath, const int borderSize)
{
    if (tileSetTexture)
    {
        tileSetTexture.reset();
        tileSetTexture = nullptr;
        layerNames.clear();
        layerHash.clear();
    }

    pugi::xml_document doc;
    if (!doc.load_file(filePath.c_str()))
    {
        ERROR("Failed to load " + filePath)
        return false;
    }

    const size_t lastSlashPos = filePath.find_last_of('/');
    dirPath = lastSlashPos != std::string::npos ? filePath.substr(0, lastSlashPos + 1) : "";

    const auto map = doc.child("map");

    std::string texturePath = getTexturePath(map);
    if (texturePath.empty())
    {
        ERROR("Failed to get texture path")
        return false;
    }

    if (!tileSetTexture->loadFromFile(texturePath))
        return false;

    SDL_Surface* surface = IMG_Load(texturePath.c_str());

    const int mapWidth = std::stoi(map.attribute("width").value());
    const int tileWidth = std::stoi(map.attribute("tilewidth").value());
    const int tileHeight = std::stoi(map.attribute("tileheight").value());
    const int tileSetWidth =
        static_cast<int>(tileSetTexture->getSize().x) / (tileWidth + 2 * borderSize);

    if (!layerNames.empty())
        layerNames.clear();
    if (!layerHash.empty())
        layerHash.clear();

    for (const auto& child : map.children())
    {
        std::string childName = child.name();
        if (childName == "tileset")
            continue;

        std::string layerName = child.attribute("name").value();
        layerNames.push_back(layerName);
        const auto layerVisibility = std::string(child.attribute("visible").value());
        const bool isVisible = layerVisibility.empty() || layerVisibility != "0";
        layerHash[layerName] = {isVisible, layerName, {}};
        const auto layerPtr = std::make_shared<Layer>(layerHash.at(layerName));

        if (childName == "layer")
        {
            std::string dataContent = child.child("data").child_value();
            dataContent.erase(std::remove(dataContent.begin(), dataContent.end(), '\n'),
                              dataContent.end());
            dataContent.erase(std::remove(dataContent.begin(), dataContent.end(), '\r'),
                              dataContent.end());

            std::stringstream ss(dataContent);
            std::string value;
            std::vector<Tile> tiles;

            int tileCounter = 0;
            while (std::getline(ss, value, ','))
            {
                if (value.empty() || !std::all_of(value.begin(), value.end(), ::isdigit))
                {
                    tileCounter++;
                    continue;
                }

                const uint32_t rawId = std::stoul(value);
                constexpr uint32_t FLIP_HORIZONTAL_FLAG = 0x80000000;
                constexpr uint32_t FLIP_VERTICAL_FLAG = 0x40000000;
                constexpr uint32_t FLIP_DIAGONAL_FLAG = 0x20000000;

                const bool horizontalFlip = (rawId & FLIP_HORIZONTAL_FLAG) != 0;
                const bool verticalFlip = (rawId & FLIP_VERTICAL_FLAG) != 0;
                const bool antiDiagonalFlip = (rawId & FLIP_DIAGONAL_FLAG) != 0;

                const int tileId = static_cast<int>(rawId & 0x0FFFFFFF) - 1;
                if (tileId < 0)
                {
                    tileCounter++;
                    continue;
                }

                const int srcX = tileId % tileSetWidth * (tileWidth + 2 * borderSize) + borderSize;
                const int srcY = tileId / tileSetWidth * (tileHeight + 2 * borderSize) + borderSize;
                const int destX = tileCounter % mapWidth * tileWidth;
                const int destY = tileCounter / mapWidth * tileHeight;

                const Rect tileSrcRect = {srcX, srcY, tileWidth, tileHeight};
                const Rect tileDstRect = {destX, destY, tileWidth, tileHeight};

                tiles.emplace_back(Tile{layerPtr, tileSrcRect, tileDstRect,
                                        getFittedRect(surface, tileSrcRect, tileDstRect.topLeft()),
                                        horizontalFlip, verticalFlip, antiDiagonalFlip, 0.0});

                tileCounter++;
            }

            layerHash.at(layerName).tiles = std::move(tiles);
        }
        else if (childName == "objectgroup")
        {
            std::vector<Tile> objects;

            for (const auto& object : child.children())
            {
                const int width = std::stoi(object.attribute("width").value());
                const int height = std::stoi(object.attribute("height").value());
                const std::string rotation = object.attribute("rotation").value();
                const int angle = rotation.empty() ? 0 : std::stoi(rotation);

                const uint32_t rawId = std::stoul(object.attribute("gid").value());
                constexpr uint32_t FLIP_HORIZONTAL_FLAG = 0x80000000;
                constexpr uint32_t FLIP_VERTICAL_FLAG = 0x40000000;

                const bool horizontalFlip = (rawId & FLIP_HORIZONTAL_FLAG) != 0;
                const bool verticalFlip = (rawId & FLIP_VERTICAL_FLAG) != 0;

                const int tileId = static_cast<int>(rawId & 0x0FFFFFFF) - 1;

                const int srcX = tileId % tileSetWidth * (width + 2 * borderSize) + borderSize;
                const int srcY = tileId / tileSetWidth * (height + 2 * borderSize) + borderSize;
                const float destX = std::stof(object.attribute("x").value());
                const float destY = std::stof(object.attribute("y").value());

                const Rect objectSrcRect{srcX, srcY, tileWidth, tileHeight};
                Rect objectDstRect;
                objectDstRect.size({tileWidth, tileHeight});

                switch (angle)
                {
                case 90:
                    objectDstRect.topLeft({destX, destY});
                    break;
                case 180:
                    objectDstRect.topRight({destX, destY});
                    break;
                case -90:
                    objectDstRect.bottomRight({destX, destY});
                    break;
                default:
                    objectDstRect.bottomLeft({destX, destY}); // 0 degrees
                }

                objects.emplace_back(
                    Tile{layerPtr, objectSrcRect, objectDstRect,
                         getFittedRect(surface, objectSrcRect, objectDstRect.topLeft()),
                         horizontalFlip, verticalFlip, false, static_cast<double>(angle)});
            }

            layerHash.at(layerName).tiles = std::move(objects);
        }
    }

    SDL_FreeSurface(surface);

    return true;
}

void TileMap::drawMap() const
{
    for (const auto& name : layerNames)
        if (layerHash.at(name).isVisible)
            drawLayer(name);
}

std::string TileMap::getTexturePath(const pugi::xml_node& map)
{
    const std::string tsxPath = dirPath + map.child("tileset").attribute("source").value();

    pugi::xml_document doc;
    if (!doc.load_file(tsxPath.c_str()))
    {
        ERROR("Failed to load " + tsxPath)
        return "";
    }

    tileSetTexture = std::make_unique<Texture>();
    const auto texDir = dirPath + doc.child("tileset").child("image").attribute("source").value();
    return texDir;
}

const Layer* TileMap::getLayer(const std::string& name) const
{
    if (const auto it = layerHash.find(name); it != layerHash.end())
        return &it->second;

    return nullptr;
}

const std::vector<std::string>& TileMap::getLayerNames() const { return layerNames; }

void TileMap::drawLayer(const std::string& name) const
{
    const auto it = layerHash.find(name);

    if (it == layerHash.end())
        return;

    for (const Tile& tile : it->second.tiles)
    {
        tileSetTexture->angle = 0.0;
        tileSetTexture->flip = {false, false};

        if (tile.antiDiagonalFlip)
        {
            tileSetTexture->angle = 90.0;
            tileSetTexture->flip.x = tile.verticalFlip;
            tileSetTexture->flip.y = !tile.horizontalFlip;
        }
        else
        {
            tileSetTexture->angle = tile.angle;
            tileSetTexture->flip.x = tile.horizontalFlip;
            tileSetTexture->flip.y = tile.verticalFlip;
        }

        window::blit(*tileSetTexture, tile.rect, tile.crop);
    }
}

std::vector<Tile> TileMap::getTileCollection(const std::vector<std::string>& layerNames) const
{
    if (layerNames.empty())
        return {};

    std::vector<Tile> tiles;
    for (const auto& layerName : layerNames)
    {
        if (layerHash.find(layerName) == layerHash.end())
        {
            WARN("Layer name not found in tile map")
            continue;
        }

        tiles.insert(tiles.end(), layerHash.at(layerName).tiles.begin(),
                     layerHash.at(layerName).tiles.end());
    }

    return tiles;
}

Rect TileMap::getFittedRect(const SDL_Surface* surface, const Rect& srcRect,
                            const math::Vec2& position)
{
    const SDL_Rect rectInt{static_cast<int>(srcRect.x), static_cast<int>(srcRect.y),
                           static_cast<int>(srcRect.w), static_cast<int>(srcRect.h)};

    int top = rectInt.h;
    int bottom = 0;
    int left = rectInt.w;
    int right = 0;

    const Uint8* pixels = static_cast<Uint8*>(surface->pixels);
    const int pitch = surface->pitch;
    const int bytesPerPixel = surface->format->BytesPerPixel;

    for (int y = rectInt.y; y < rectInt.y + rectInt.h; y++)
        for (int x = rectInt.x; x < rectInt.x + rectInt.w; x++)
        {
            const Uint8* pixel = pixels + y * pitch + x * bytesPerPixel;
            if (pixel[3] == 0)
                continue;

            top = std::min(top, y - rectInt.y);
            bottom = std::max(bottom, y - rectInt.y);
            left = std::min(left, x - rectInt.x);
            right = std::max(right, x - rectInt.x);
        }

    return {static_cast<int>(position.x + left), static_cast<int>(position.y + top),
            right - left + 1, bottom - top + 1};
}

} // namespace kn