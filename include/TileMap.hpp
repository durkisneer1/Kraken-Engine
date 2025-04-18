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
struct Group;
struct Rect;

struct Tile
{
    /**
     * @brief The layer the tile belongs to.
     */
    std::shared_ptr<Layer> layer;
    /**
     * @brief The area of the tile in its tileset.
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

    bool horizontalFlip;
    bool verticalFlip;
    bool antiDiagonalFlip;
    double angle;
};

class Layer
{
  public:
    /**
     * @brief The type of tiles the layer contains.
     */
    enum Type
    {
        OBJECT,
        TILE,
    } const type;
    /**
     * @brief Whether the layer is visible when calling ``TileMap::drawMap``.
     */
    const bool isVisible;
    /**
     * @brief The name of the layer in the tmx file.
     */
    const std::string name;
    /**
     * @brief A collection of tiles that belong to the layer.
     */
    std::vector<Tile> tiles;

    Layer() = default;
    Layer(Type type, bool isVisible, const std::string& name,
          const std::shared_ptr<Texture>& tileSetTexture);
    ~Layer() = default;

    /**
     * @brief Draw the layer.
     */
    void draw() const;

  private:
    const std::shared_ptr<Texture> tileSetTexture;
};

class TileMap final
{
  public:
    /**
     * @brief Load a Tiled tmx file.
     *
     * @param filePath The path to the Tiled tmx file.
     * @param borderSize The size of the border around the tiles.
     * The border must be on all sides of the tiles.
     */
    explicit TileMap(const std::string& filePath, int borderSize = 0);

    TileMap() = default;
    ~TileMap() = default;

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
    [[nodiscard]] const Layer* getLayer(const std::string& name,
                                        Layer::Type type = Layer::TILE) const;

    /**
     * @brief Get all the layers in the tile map.
     */
    [[nodiscard]] const std::vector<std::shared_ptr<Layer>>& getLayers() const;

    /**
     * @brief Draw all layers of the tile map.
     */
    void drawMap() const;

    /**
     * @brief Get a collection of tiles from different layers of the tile map.
     *
     * @param layers The layer pointers to grab tiles from.
     */
    [[nodiscard]] static std::vector<Tile>
    getTileCollection(const std::vector<const Layer*>& layers);

  private:
    std::string dirPath;

    std::vector<std::shared_ptr<Layer>> layerVec;

    std::string getTexturePath(const pugi::xml_node& map);

    static Rect getFittedRect(const SDL_Surface* surface, const Rect& srcRect,
                              const math::Vec2& position);
};

} // namespace kn
