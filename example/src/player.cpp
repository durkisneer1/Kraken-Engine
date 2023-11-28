#include "../include/player.hpp"
#include <iostream>


Player::Player(dk::RenderWindow& window, dk::Texture& texture)
: dk::Sprite(window, texture) {
    position = { WIN_SIZE.x / 2, WIN_SIZE.y / 2 };
}

void Player::process(double deltaTime) {
    if (onGround) {
        if (dk::input::getKeysPressed()[DKK_space]) {
            velocity.y = -350;
            onGround = false;
        } else {}
    } else {
        velocity.y += GRAVITY * deltaTime;
    }
    
    direction = dk::input::getVector(moveLeft, moveRight);
    velocity.x = direction.x * speed;
    moveAndCollide(deltaTime);
    
    rect.clamp();
    position = rect.getCenter();

    texture.drawAtEx(rect, 45, false, false);
}
