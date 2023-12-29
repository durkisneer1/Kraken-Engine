#include "../include/player.hpp"
#include <iostream>


Player::Player(kn::RenderWindow& window, std::shared_ptr<kn::Texture> texture)
: kn::Sprite(window, texture) {
    position = kn::SCREEN_SIZE / 4.0f;
    rect.setCenter(position);
}

void Player::update(double deltaTime, const std::vector<std::shared_ptr<kn::Sprite>>& tiles) {
    if (onGround) {
        if (kn::input::getKeysPressed()[KNK_space]) {
            velocity.y = -200;
            onGround = false;
        }
    } else {
        velocity.y += kn::GRAVITY * deltaTime;
    }
    
    direction = kn::input::getVector(moveLeft, moveRight);
    velocity.x = direction.x * speed;
    moveAndCollide(deltaTime, tiles);

    window.blit(texture, crop, rect);
}
