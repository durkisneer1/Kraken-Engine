#include "../include/player.hpp"
#include <iostream>


Player::Player(dk::RenderWindow& window, dk::Texture& texture)
: dk::Sprite(window, texture) {
    position = { WIN_SIZE.x / 2, WIN_SIZE.y / 2 };
}

void Player::process(double deltaTime) {
    if (onGround) {
        if (window.getKeysPressed()[DKK_space]) {
            velocity.y = -GRAVITY / 2;
            onGround = false;
        }
    } else {
        velocity.y += GRAVITY * deltaTime;
    }
    
    direction = dk::input::getVector(moveLeft, moveRight);
    velocity.x = direction.x * speed;

    moveAndCollide(deltaTime);
    rect.clamp();
    position = rect.getCenter();

    draw();
}
