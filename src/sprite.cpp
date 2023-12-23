#include "../include/Sprite.hpp"


namespace kn {

Sprite::Sprite(RenderWindow& window, std::shared_ptr<Texture> texture)
: window(window), texture(texture), rect(texture->getRect()) {}

math::Vec2 Sprite::getPosition() const {
    return position;
}

Rect Sprite::getRect() const {
    return rect;
}

}