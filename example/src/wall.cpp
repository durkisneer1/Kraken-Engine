#include "../include/wall.hpp"


Wall::Wall(dk::RenderWindow& window, dk::Texture& texture)
: dk::Character(window, texture) {
    position = { WIN_SIZE.x / 4, WIN_SIZE.y / 2 };
    rect.setCenter(position);
}

void Wall::process(double deltaTime) {
    draw();
}