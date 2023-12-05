#include "../include/Tracker.hpp"
#include <iostream>


Tracker::Tracker(kn::RenderWindow& window, kn::Texture& texture)
: window(window), texture(texture), rect(texture.getRect()) {
    position = WIN_SIZE / 2.0f;
}

void Tracker::process(double deltaTime) {
    position = kn::math::lerpVec(position, kn::input::getMousePos(), speed * deltaTime);
    rect.setCenter(position);
    window.blit(texture, rect);
}