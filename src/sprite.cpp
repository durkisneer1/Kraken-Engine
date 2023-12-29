#include <iostream>

#include "../include/Sprite.hpp"


namespace kn {

Sprite::Sprite(RenderWindow& window, std::shared_ptr<Texture> texture)
: window(window), texture(texture), rect(texture->getRect()) {
    crop.w = rect.w;
    crop.h = rect.h;
}

std::shared_ptr<Texture> Sprite::getTexture() const {
    return texture;
}

}
