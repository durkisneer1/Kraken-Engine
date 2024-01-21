#pragma once

#include <memory>
#include <string>
#include <vector>

#include "tmxlite/Map.hpp"

#include "Cache.hpp"
#include "Entity.hpp"

namespace kn
{

/**
 * @brief A tmx layer tile.
 */
struct Tile
{
    std::shared_ptr<Texture> texture;
    Rect crop;
    Rect rect;
};

/**
 * @brief A class that represents a Tiled map.
 *
 * @warning This class is currently only compatible with orthogonal maps and tile layers (no
 * objects).
 */
class TileMap final
{
  public:
    /**
     * @brief Constructs a tile map from a TMX file.
     *
     * @param tmxPath The path to the TMX file.
     */
    TileMap(const std::string& tmxPath);
    ~TileMap() = default;

    /**
     * @brief Draw the tile map layers.
     */
    void draw();

  private:
    tmx::Map map;

    std::vector<Tile> tileVec = {};
    std::map<int, std::shared_ptr<Texture>> tileSetMap = {};
};

} // namespace kn
