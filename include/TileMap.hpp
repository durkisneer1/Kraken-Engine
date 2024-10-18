#pragma once

#include <pugixml/pugixml.hpp>
#include <string>
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
 * @brief Container for tile map layer names and tiles
 */
struct Layer
{
    std::string name;
    std::vector<Tile> tiles;
};

/**
 * @brief Object that parses Tiled tmx files and contains tile map layers
 */
class TileMap final
{
  public:
    /**
     * @brief Load a Tiled tmx file
     *
     * @param filePath The directory to the Tiled tmx file
     */
    explicit TileMap(const std::string& filePath);
    ~TileMap();

    /**
     * @brief Get a layer from the loaded tile map
     *
     * @param name The name of the layer
     */
    [[nodiscard]] const Layer& getLayer(const std::string& name) const;

    /**
     * @brief Get a pointer to the texture used for the tile set
     */
    [[nodiscard]] Texture* getTexture() const;

  private:
    std::string dirPath;
    Texture* texture;
    std::vector<Layer> layers;

    bool getTexture(const pugi::xml_node& map);
    void parse();
};

} // namespace kn
