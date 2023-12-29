#pragma once

#include <memory>
#include <string>

#include "Texture.hpp"


namespace kn {

/// @brief A tmx layer tile.
struct Tile {
    Tile(std::shared_ptr<Texture> texture, Rect crop, Rect rect)
    : texture(texture), crop(crop), rect(rect) {}
    ~Tile() = default;

    std::shared_ptr<Texture> texture;
    Rect crop;
    Rect rect;
};

/// @brief A tmx object tile.
/// @details This is used for objects and can be assigned to a Sprite type.
/// @note This is not yet complete.
struct Object final : public Tile {
    Object(std::shared_ptr<Texture> texture, Rect crop, Rect rect, std::string name, std::string type)
    : Tile(texture, crop, rect), name(name), type(type) {}
    ~Object() = default;
    
    std::string name;
    std::string type;
};

}
