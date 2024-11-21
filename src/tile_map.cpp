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
    if (getTexture(map); !texture)
        return;

    const int mapWidth = std::stoi(map.attribute("width").value());
    const int tileWidth = std::stoi(map.attribute("tilewidth").value());
    const int tileHeight = std::stoi(map.attribute("tileheight").value());
    const int tileSetWidth = static_cast<int>(texture->getSize().x) / tileWidth;

    for (const auto& child : map.children())
    {
        if (std::string(child.name()) != "layer")
            continue;

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

            tiles.emplace_back(
                Tile{{srcX, srcY, tileWidth, tileHeight}, {destX, destY, tileWidth, tileHeight}});

            tileCounter++;
        }

        std::string layerName = child.attribute("name").value();
        layerNames.push_back(layerName);
        layerHash[layerName] = std::move(tiles);
    }
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

void TileMap::getTexture(const pugi::xml_node& map)
{
    const std::string tsxPath = dirPath + map.child("tileset").attribute("source").value();

    pugi::xml_document doc;
    if (!doc.load_file(tsxPath.c_str()))
    {
        ERROR("Failed to load " + tsxPath)
        return;
    }

    texture = new Texture();
    if (!texture->loadFromFile(dirPath +
                               doc.child("tileset").child("image").attribute("source").value()))
    {
        ERROR("Failed to load texture from file: " + dirPath +
              doc.child("tileset").child("image").attribute("source").value());
    }
}

const std::vector<Tile>* TileMap::getLayer(const std::string& name) const
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

    for (const Tile& tile : it->second)
        window::blit(*texture, tile.rect, tile.crop);
}

} // namespace kn