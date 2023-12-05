#include "../include/wall.hpp"
#include <iostream>


Wall::Wall(kn::RenderWindow& window, kn::Texture& texture, kn::math::Vector2 position)
: kn::Sprite(window, texture) {
    this->position = position;
    rect.setBottomLeft(position);
}

void Wall::process(double deltaTime) {
    window.blit(texture, rect);
}