#pragma once

#include <memory>
#include <string>

#include "Texture.hpp"

namespace kn
{

/**
 * @brief A tmx layer tile.
 */
struct Tile
{
    /**
     * @brief Create a tile.
     *
     * @param texture A texture pointer.
     * @param crop The rectangle to crop from.
     * @param rect The rectangle to draw to.
     */
    Tile(std::shared_ptr<Texture> texture, Rect crop, Rect rect)
        : texture(texture), crop(crop), rect(rect) {}
    ~Tile() = default;

    std::shared_ptr<Texture> texture;
    Rect crop;
    Rect rect;
};

/**
 * @brief A tmx object tile.
 *
 * @warning This struct type is not fully implemented yet.
 */
struct Object final : public Tile
{
    /** 
     * @brief Create an object tile.
     * 
     * @param texture A texture pointer.
     * @param crop The rectangle to crop from.
     * @param rect The rectangle to draw to.
     * @param name The name of the object.
     * @param type The type of the object.
     */
    Object(std::shared_ptr<Texture> texture, Rect crop, Rect rect, const std::string &name, const std::string &type)
        : Tile(texture, crop, rect), name(name), type(type) {}
    ~Object() = default;

    std::string name;
    std::string type;
};

}
