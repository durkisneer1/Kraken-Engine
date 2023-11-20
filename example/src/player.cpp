#include "../include/player.hpp"
#include <iostream>


Player::Player(dk::RenderWindow& window, dk::Texture& texture)
: dk::CharacterSprite(window, texture) {
    position = { WIN_SIZE.x / 2, WIN_SIZE.y / 2 };
}

void Player::process(double deltaTime) {
    velocity.y += GRAVITY * deltaTime;
    dk::math::Vector2 direction = dk::input::getVector(moveLeft, moveRight);
    velocity.x = direction.x * speed;
    position += velocity * deltaTime;

    rect.setCenter(position);
    texture.blit(rect);
}
