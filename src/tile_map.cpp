#include <SDL_image.h>
#include <algorithm>
#include <fstream>
#include <sstream>

#include "ErrorLogger.hpp"
#include "TileMap.hpp"
#include "Window.hpp"

namespace kn
{
TileMap::TileMap(const std::string& filePath)
{
    pugi::xml_document doc;
    if (!doc.load_file(filePath.c_str()))
        throw std::runtime_error("Failed to load " + filePath);

    const size_t lastSlashPos = filePath.find_last_of('/');
    dirPath = (lastSlashPos != std::string::npos) ? filePath.substr(0, lastSlashPos + 1) : "";

    const auto map = doc.child("map");

    std::string texturePath = getTexturePath(map);
    if (texturePath.empty())
        ERROR("Failed to get texture path");
    texture = new Texture();
    if (!texture->loadFromFile(texturePath))
    {
        delete texture;
        texture = nullptr;
        return;
    }
    SDL_Surface* surface = IMG_Load(texturePath.c_str());

    const int mapWidth = std::stoi(map.attribute("width").value());
    const int tileWidth = std::stoi(map.attribute("tilewidth").value());
    const int tileHeight = std::stoi(map.attribute("tileheight").value());
    const int tileSetWidth = static_cast<int>(texture->getSize().x) / tileWidth;

    for (const auto& child : map.children())
    {
        if (std::string(child.name()) != "layer")
            continue;

        std::string layerName = child.attribute("name").value();
        layerNames.push_back(layerName);
        layerHash[layerName] = {layerName, {}};
        const auto layerPtr = std::make_shared<Layer>(layerHash.at(layerName));

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

            const int tileId = std::stoi(value) - 1;
            if (tileId < 0)
            {
                tileCounter++;
                continue;
            }

            const int srcX = (tileId % tileSetWidth) * tileWidth;
            const int srcY = (tileId / tileSetWidth) * tileHeight;
            const int destX = (tileCounter % mapWidth) * tileWidth;
            const int destY = (tileCounter / mapWidth) * tileHeight;

            Rect tileSrcRect = {srcX, srcY, tileWidth, tileHeight};
            Rect tileDstRect = {destX, destY, tileWidth, tileHeight};

            tiles.emplace_back(Tile{layerPtr, tileSrcRect, tileDstRect,
                                    getFittedRect(surface, tileSrcRect, tileDstRect.getTopLeft())});

            tileCounter++;
        }

        layerHash.at(layerName).tiles = std::move(tiles);
    }

    SDL_FreeSurface(surface);
}

TileMap::~TileMap()
{
    delete texture;
    texture = nullptr;
}

void TileMap::drawMap() const
{
    for (const auto& name : layerNames)
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

    texture = new Texture();
    const auto texDir = dirPath + doc.child("tileset").child("image").attribute("source").value();
    return texDir;
}

const Layer* TileMap::getLayer(const std::string& name) const
{
    if (const auto it = layerHash.find(name); it != layerHash.end())
        return &it->second;

    throw std::runtime_error("Layer " + name + " not found");
}

void TileMap::drawLayer(const std::string& name) const
{
    const auto it = layerHash.find(name);

    if (it == layerHash.end())
        throw std::runtime_error("Layer " + name + " not found");

    for (const Tile& tile : it->second.tiles)
        window::blit(*texture, tile.rect, tile.crop);
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
    {
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
    }

    return {static_cast<int>(position.x + left), static_cast<int>(position.y + top),
            right - left + 1, bottom - top + 1};
}

} // namespace kn