#pragma once

#include <memory>
#include <vector>
#include <string>

#include "tmxlite/Map.hpp"

#include "RenderWindow.hpp"
#include "TileTypes.hpp"
#include "TextureCache.hpp"
#include "Entity.hpp"

namespace kn
{

/**
 * @brief A class that represents a Tiled map.
 */
class TileMap final
{
public:
    /**
     * @brief Constructs a tile map from a TMX file.
     *
     * @param textureCache The texture cache to use.
     * @param tmxPath The path to the TMX file.
     */
    TileMap(TextureCache &textureCache, const std::string &tmxPath);
    ~TileMap() = default;

    /**
     * @brief Draw the tile map.
     */
    void drawTiles();

    /**
     * @brief Draw the objects in the tile map.
     */
    void drawObjects();

    /**
     * @brief Draw the tile map and objects.
     */
    void drawAll();

    /**
     * @brief Get the tile map objects vector.
     *
     * @return The tile map objects vector.
     */
    const std::vector<Object> &getObjects() const;

private:
    RenderWindow &window = RenderWindow::getInstance();
    tmx::Map m_map;

    std::vector<Tile> tileVec;
    std::vector<Object> objectVec;
    std::map<int, std::shared_ptr<Texture>> tileSetMap;
};

}
