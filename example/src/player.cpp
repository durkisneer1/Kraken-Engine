#include "../include/player.hpp"
#include <iostream>


Player::Player(kn::RenderWindow& window, std::shared_ptr<kn::Texture> texture)
: kn::Sprite(window, texture) {
    position = kn::SCREEN_SIZE / 2.0f;
}

void Player::update(double deltaTime, const std::vector<std::shared_ptr<Wall>>& walls) {
    if (onGround) {
        if (kn::input::getKeysPressed()[KNK_space]) {
            velocity.y = -85;
            onGround = false;
        }
    } else {
        velocity.y += kn::GRAVITY * deltaTime;
    }
    
    direction = kn::input::getVector(moveLeft, moveRight);
    velocity.x = direction.x * speed;
    moveAndCollide(deltaTime, walls);
    
    rect.clamp();
    position = rect.getCenter();

    window.blit(texture, rect);
}
