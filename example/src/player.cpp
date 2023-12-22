#include "../include/player.hpp"
#include <iostream>


Player::Player(kn::RenderWindow& window, std::shared_ptr<kn::Texture> texture)
: kn::sprite::Sprite(window, texture) {
    position = kn::SCREEN_SIZE / 2.0f;
}

template <typename T>
void Player::update(double deltaTime, const kn::sprite::Group<T>& group) {
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
    moveAndCollide(deltaTime, group);
    
    rect.clamp();
    position = rect.getCenter();

    window.blitEx(texture, rect, 0.0, false, false);
}
