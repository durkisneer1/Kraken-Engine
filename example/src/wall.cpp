#include "../include/wall.hpp"
#include <iostream>


Wall::Wall(dk::RenderWindow& window, dk::Texture& texture, dk::math::Vector2 position)
: dk::StaticSprite(window, texture) {
    this->position = position;
}

void Wall::process(double deltaTime) {
    rect.setBottomLeft(position);
    draw();
}