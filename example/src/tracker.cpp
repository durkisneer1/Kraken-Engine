#include "../include/Tracker.hpp"
#include <iostream>


Tracker::Tracker(dk::RenderWindow& window, dk::Texture& texture)
: window(window), texture(texture), rect(texture.getRect()) {
    position = WIN_SIZE / 2.0f;
}

void Tracker::process(double deltaTime) {
    position = dk::math::lerpVec(position, dk::input::getMousePos(), speed * deltaTime);
    rect.setCenter(position);
    window.blit(texture, rect);
}