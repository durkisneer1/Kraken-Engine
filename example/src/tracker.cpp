#include "../include/Tracker.hpp"
#include <iostream>


Tracker::Tracker(kn::RenderWindow& window, std::shared_ptr<kn::Texture> texture)
: window(window), texture(texture), rect(texture->getRect()), position(WIN_SIZE / 2.0f) {}

void Tracker::update(double deltaTime, kn::math::Vector2 target) {
    position = kn::math::lerpVec(position, target, speed * deltaTime);
    rect.setCenter(position);
    window.blit(texture, rect);
}