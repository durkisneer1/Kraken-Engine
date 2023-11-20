#include "../include/wall.hpp"
#include <iostream>


Wall::Wall(dk::RenderWindow& window, dk::Texture& texture, dk::math::Vector2 position)
: dk::CharacterSprite(window, texture) {
    this->position = position;
    rect.setBottomLeft(position);
}

void Wall::process(double deltaTime) {
    texture.blit(rect);
}