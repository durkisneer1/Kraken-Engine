#include "../include/wall.hpp"
#include <iostream>


Wall::Wall(kn::RenderWindow& window, std::shared_ptr<kn::Texture> texture, kn::math::Vec2 position)
: kn::Sprite(window, texture) {
    this->position = position;
    rect.setBottomLeft(position);
}

void Wall::update() {
    window.blit(texture, rect);
}