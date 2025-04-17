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

Layer::Layer(Type type, bool isVisible, const std::string& name,
             const std::shared_ptr<Texture>& tileSetTexture)
    : type(type), isVisible(isVisible), name(name), tileSetTexture(tileSetTexture)
{
}

void Layer::draw() const
{
    for (const auto& tile : tiles)
    {
        if (tile.antiDiagonalFlip)
        {
            tileSetTexture->angle = 90.0;
            tileSetTexture->flip.h = tile.verticalFlip;
            tileSetTexture->flip.v = !tile.horizontalFlip;
        }
        else
        {
            tileSetTexture->angle = tile.angle;
            tileSetTexture->flip.h = tile.horizontalFlip;
            tileSetTexture->flip.v = tile.verticalFlip;
        }

        window::blit(*tileSetTexture, tile.rect, tile.crop);
    }
}

TileMap::TileMap(const std::string& filePath, const int borderSize)
{
    if (!loadTMX(filePath, borderSize))
        throw Exception("Failed to load tile map");
}

bool TileMap::loadTMX(const std::string& filePath, const int borderSize)
{
    if (!layerVec.empty())
        layerVec.clear();

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

    const auto tileSetTexture = std::make_shared<Texture>();
    if (!tileSetTexture->loadFromFile(texturePath))
        return false;

    SDL_Surface* surface = IMG_Load(texturePath.c_str());

    const int mapWidth = std::stoi(map.attribute("width").value());
    const int tileWidth = std::stoi(map.attribute("tilewidth").value());
    const int tileHeight = std::stoi(map.attribute("tileheight").value());
    const int tileSetWidth =
        static_cast<int>(tileSetTexture->getSize().x) / (tileWidth + 2 * borderSize);

    if (!layerVec.empty())
        layerVec.clear();

    for (const auto& child : map.children())
    {
        std::string childName = child.name();
        if (childName == "tileset")
            continue;

        std::string layerName = child.attribute("name").value();
        const auto layerVisibility = std::string(child.attribute("visible").value());
        const bool isVisible = layerVisibility.empty() || layerVisibility != "0";
        std::vector<Tile> tiles;
        std::shared_ptr<Layer> layerPtr = nullptr;

        if (childName == "layer")
        {
            std::string dataContent = child.child("data").child_value();
            dataContent.erase(std::remove(dataContent.begin(), dataContent.end(), '\n'),
                              dataContent.end());
            dataContent.erase(std::remove(dataContent.begin(), dataContent.end(), '\r'),
                              dataContent.end());

            std::stringstream ss(dataContent);
            std::string value;
            layerPtr =
                std::make_shared<Layer>(Layer(Layer::TILE, isVisible, layerName, tileSetTexture));

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

                tiles.push_back({layerPtr, tileSrcRect, tileDstRect,
                                 getFittedRect(surface, tileSrcRect, tileDstRect.topLeft()),
                                 horizontalFlip, verticalFlip, antiDiagonalFlip, 0.0});

                tileCounter++;
            }
            layerPtr->tiles = std::move(tiles);
        }
        else if (childName == "objectgroup")
        {
            layerPtr =
                std::make_shared<Layer>(Layer(Layer::OBJECT, isVisible, layerName, tileSetTexture));

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

                tiles.push_back({layerPtr, objectSrcRect, objectDstRect,
                                 getFittedRect(surface, objectSrcRect, objectDstRect.topLeft()),
                                 horizontalFlip, verticalFlip, false, static_cast<double>(angle)});
            }
            layerPtr->tiles = std::move(tiles);
        }
        layerVec.push_back(layerPtr);
    }

    SDL_FreeSurface(surface);

    return true;
}

void TileMap::drawMap() const
{
    if (layerVec.empty())
        return;

    for (const auto& layer : layerVec)
    {
        if (!layer->isVisible)
            continue;

        layer->draw();
    }
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

    const auto texDir = dirPath + doc.child("tileset").child("image").attribute("source").value();
    return texDir;
}

const Layer* TileMap::getLayer(const std::string& name, Layer::Type type) const
{
    for (const auto& layer : layerVec)
    {
        if (layer->name == name && layer->type == type)
            return layer.get();
    }

    return nullptr;
}

const std::vector<std::shared_ptr<Layer>>& TileMap::getLayers() const { return layerVec; }

std::vector<Tile> TileMap::getTileCollection(const std::vector<const Layer*>& layers)
{
    std::vector<Tile> tiles;
    if (layers.empty())
        return tiles;

    for (const auto& layer : layers)
    {
        const auto& layerTiles = layer->tiles;
        tiles.insert(tiles.end(), layerTiles.begin(), layerTiles.end());
    }

    return tiles;
}

Rect TileMap::getFittedRect(const SDL_Surface* surface, const Rect& srcRect,
                            const math::Vec2& position)
{
    const SDL_Rect rectInt = srcRect;

    int top = rectInt.h;
    int bottom = 0;
    int left = rectInt.w;
    int right = 0;

    const auto* pixels = static_cast<uint8_t*>(surface->pixels);
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