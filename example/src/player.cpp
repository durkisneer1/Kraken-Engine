#include "../include/player.hpp"
#include <iostream>


Player::Player(dk::RenderWindow& window, dk::Texture& texture)
: dk::Sprite(window, texture) {
    position = WIN_SIZE / 2.0f;
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

    window.blit(texture, rect);
}
