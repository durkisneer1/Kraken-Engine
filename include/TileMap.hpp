#pragma once

#include <memory>
#include <pugixml/pugixml.hpp>
#include <string>
#include <unordered_map>
#include <vector>

#include "Rect.hpp"
#include "Texture.hpp"

namespace kn
{

struct Layer;

/**
 * @brief Container for source and destination Rects
 */
struct Tile
{
    std::shared_ptr<Layer> layer;
    Rect crop;
    Rect rect;
    Rect collider;
};

/**
 * @brief Container for a layer of tiles
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

    /**
     * @brief Get a collection of tiles from the tile map.
     *
     * @param layerNames The names of the layers to get tiles from.
     */
    [[nodiscard]] std::vector<Tile>
    getTileCollection(const std::vector<std::string>& layerNames) const;

  private:
    std::string dirPath;
    Texture* texture = nullptr;

    std::vector<std::string> layerNames;
    std::unordered_map<std::string, Layer> layerHash;

    std::string getTexturePath(const pugi::xml_node& map);

    static Rect getFittedRect(const SDL_Surface* surface, const Rect& srcRect,
                              const math::Vec2& position);
};

} // namespace kn
