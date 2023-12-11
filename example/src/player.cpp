#include "../include/player.hpp"
#include <iostream>


Player::Player(kn::RenderWindow& window, std::shared_ptr<kn::Texture> texture)
: kn::Sprite(window, texture) {
    position = WIN_SIZE / 2.0f;
}

void Player::process(double deltaTime) {
    if (onGround) {
        if (kn::input::getKeysPressed()[KNK_space]) {
            velocity.y = -340;
            onGround = false;
        }
    } else {
        velocity.y += GRAVITY * deltaTime;
    }
    
    direction = kn::input::getVector(moveLeft, moveRight);
    velocity.x = direction.x * speed;
    moveAndCollide(deltaTime);
    
    rect.clamp();
    position = rect.getCenter();

    window.blitEx(texture, rect, 0.0, false, false);
}
