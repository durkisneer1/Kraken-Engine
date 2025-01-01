#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include <pugixml.hpp>

#include "Texture.hpp"

namespace kn
{

struct Layer;
struct Rect;

struct Tile
{
    /**
     * @brief The layer the tile belongs to.
     */
    std::shared_ptr<Layer> layer;
    /**
     * @brief The position of the tile in its tileset.
     */
    Rect crop;
    /**
     * @brief The position of the tile in the tile map.
     */
    Rect rect;
    /**
     * @brief An accurate bounding box for the tile.
     */
    Rect collider;
};

struct Layer
{
    /**
     * @brief Whether the layer is visible when calling ``TileMap::drawMap``.
     */
    bool isVisible;
    /**
     * @brief The name of the layer within the tmx file.
     */
    std::string name;
    /**
     * @brief A collection of tiles that belong to the layer.
     */
    std::vector<Tile> tiles;
};

class TileMap final
{
  public:
    TileMap() = default;
    ~TileMap();

    /**
     * @brief Load a Tiled tmx file.
     *
     * @param filePath The path to the Tiled tmx file.
     * @param borderSize The size of the border around the tiles.
     * The border must be on all sides of the tiles.
     */
    [[maybe_unused]] bool loadTMX(const std::string& filePath, int borderSize = 0);

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
