#include "../include/player.hpp"


Player::Player(dk::RenderWindow& window, dk::Texture& texture)
: dk::CharacterSprite(window, texture) {
    position = { WIN_SIZE.x / 2, WIN_SIZE.y / 2 };
}

void Player::process(double deltaTime) {
    dk::math::Vector2 direction = dk::input::getVector(moveUp, moveLeft, moveDown, moveRight);
    velocity = direction * speed * deltaTime;
    moveAndSlide();

    rect.clamp();
    position = rect.getCenter();

    draw();
}
