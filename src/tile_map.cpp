#include <algorithm>
#include <fstream>
#include <pugixml/pugixml.hpp>
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
    if (getTexture(map); !texture)
        return;

    const int mapWidth = std::stoi(map.attribute("width").value());
    const int tileWidth = std::stoi(map.attribute("tilewidth").value());
    const int tileHeight = std::stoi(map.attribute("tileheight").value());
    const int srcMapWidth = static_cast<int>(texture->getSize().x) / tileWidth;

    for (const auto& child : map.children())
    {
        if (std::string(child.name()) != "layer")
            continue;

        std::stringstream ss(child.child("data").child_value());
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

            const int srcX = (tileId % srcMapWidth) * tileWidth;
            const int srcY = (tileId / srcMapWidth) * tileHeight;
            const int destX = (tileCounter % mapWidth) * tileWidth;
            const int destY = (tileCounter / mapWidth) * tileHeight;

            tiles.emplace_back(
                Tile{{srcX, srcY, tileWidth, tileHeight}, {destX, destY, tileWidth, tileHeight}});

            tileCounter++;
        }

        layerHash[child.attribute("name").value()] = Layer{std::move(tiles)};
    }
}

TileMap::~TileMap()
{
    delete texture;
    texture = nullptr;
}

void TileMap::drawMap() const
{
    for (const auto& [name, layer] : layerHash)
        drawLayer(name);
}

void TileMap::getTexture(const pugi::xml_node& map)
{
    const std::string tsxPath = dirPath + map.child("tileset").attribute("source").value();

    pugi::xml_document doc;
    if (!doc.load_file(tsxPath.c_str()))
    {
        ERROR("Failed to load " + tsxPath)
        return;
    }

    texture =
        new Texture(dirPath + doc.child("tileset").child("image").attribute("source").value());
}

const Layer& TileMap::getLayer(const std::string& name) const
{
    if (const auto it = layerHash.find(name); it != layerHash.end())
        return it->second;

    throw std::runtime_error("Layer " + name + " not found");
}

void TileMap::drawLayer(const std::string& name) const
{
    if (const auto it = layerHash.find(name); it != layerHash.end())
    {
        for (const Tile& tile : it->second.tiles)
            window::blit(*texture, tile.rect, tile.crop);
    }
    else
        throw std::runtime_error("Layer " + name + " not found");
}

} // namespace kn