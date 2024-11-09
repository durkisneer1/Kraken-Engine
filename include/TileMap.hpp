#pragma once

#include <pugixml/pugixml.hpp>
#include <string>
#include <unordered_map>
#include <vector>

#include "Rect.hpp"
#include "Texture.hpp"

namespace kn
{

/**
 * @brief Container for source and destination Rects
 */
struct Tile
{
    Rect crop;
    Rect rect;
};

/**
 * @brief Container for tile map layer tiles
 */
struct Layer
{
    std::vector<Tile> tiles;
};

/**
 * @brief Object that parses Tiled tmx files and contains tile map layers
 */
class TileMap final
{
  public:
    /**
     * @brief Load a Tiled tmx file.
     *
     * @param filePath The path to the Tiled tmx file.
     */
    explicit TileMap(const std::string& filePath);
    ~TileMap();

    /**
     * @brief Get a layer from the loaded tile map.
     *
     * @param name The name of the layer.
     */
    [[nodiscard]] const Layer* getLayer(const std::string& name) const;

    /**
     * @brief Draw a layer from the tile map.
     *
     * @param name The name of the layer.
     */
    void drawLayer(const std::string& name) const;

    /**
     * @brief Draw all layers of the tile map.
     */
    void drawMap() const;

  private:
    std::string dirPath;
    Texture* texture = nullptr;
    std::unordered_map<std::string, Layer> layerHash;

    void getTexture(const pugi::xml_node& map);
    void parse();
};

} // namespace kn
