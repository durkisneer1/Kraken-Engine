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
    {
        std::cout << "Failed to load " + filePath << std::endl;
        return;
    }

    const size_t lastSlashPos = filePath.find_last_of('/');
    dirPath = (lastSlashPos != std::string::npos) ? filePath.substr(0, lastSlashPos + 1) : "";

    const auto map = doc.child("map");
    if (!getTexture(map))
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
            if (value.empty() || value.find_first_not_of("123456789") != std::string::npos)
            {
                tileCounter++;
                continue;
            }

            const int tileId = std::stoi(value) - 1;

            const int srcX = (tileId % srcMapWidth) * tileWidth;
            const int srcY = (tileId / srcMapWidth) * tileHeight;
            const int destX = (tileCounter % mapWidth) * tileWidth;
            const int destY = (tileCounter / mapWidth) * tileHeight;

            tiles.emplace_back(
                Tile{{srcX, srcY, tileWidth, tileHeight}, {destX, destY, tileWidth, tileHeight}});

            tileCounter++;
        }

        layers.emplace_back(Layer{child.attribute("name").value(), std::move(tiles)});
    }
}

TileMap::~TileMap()
{
    delete texture;
    texture = nullptr;
}

bool TileMap::getTexture(const pugi::xml_node& map)
{
    const std::string tsxPath = dirPath + map.child("tileset").attribute("source").value();

    pugi::xml_document doc;
    if (!doc.load_file(tsxPath.c_str()))
    {
        ERROR("Failed to load " + tsxPath);
        return false;
    }

    texture =
        new Texture(dirPath + doc.child("tileset").child("image").attribute("source").value());
    return true;
}

const Layer& TileMap::getLayer(const std::string& name) const
{
    for (const auto& layer : layers)
        if (layer.name == name)
            return layer;

    ERROR("Layer " + name + " not found");
    return Layer();
}

Texture* TileMap::getTexture() const { return texture; }

} // namespace kn