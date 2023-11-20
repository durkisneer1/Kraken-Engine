#include "../include/player.hpp"
#include <iostream>


Player::Player(dk::RenderWindow& window, dk::Texture& texture)
: dk::Sprite(window, texture) {
    position = { WIN_SIZE.x / 2, WIN_SIZE.y / 2 };
}

void Player::process(double deltaTime) {
    if (onGround) {
        if (window.getKeysPressed()[DKK_space]) {
            velocity.y = -400;
            onGround = false;
        }
    } else {
        velocity.y += GRAVITY * deltaTime;
    }
    
    direction = dk::input::getVector(moveLeft, moveRight);
    velocity.x = direction.x * speed;

    position.x += velocity.x * deltaTime;
    rect.x = position.x - rect.w / 2;
    rectHorizontalCollision();
    position.y += velocity.y * deltaTime;
    rect.y = position.y - rect.h / 2;
    rectVerticalCollision();

    draw();
}

void Player::rectHorizontalCollision() {
    for (const auto& sprite : dk::Sprite::getSprites()) {
        if (sprite.get() != this) {
            if (rect.collideRect(sprite->getRect())) {
                if (velocity.x > 0) {
                    rect.setRight(sprite->getRect().getLeft());
                } else if (velocity.x < 0) {
                    rect.setLeft(sprite->getRect().getRight());
                }
                velocity.x = 0;
                position = rect.getCenter();
            }
        }
    }
}

void Player::rectVerticalCollision() {
    for (const auto& sprite : dk::Sprite::getSprites()) {
        if (sprite.get() != this) {
            if (rect.collideRect(sprite->getRect())) {
                if (velocity.y > 0) {
                    rect.setBottom(sprite->getRect().getTop());
                    onGround = true;
                } else if (velocity.y < 0) {
                    rect.setTop(sprite->getRect().getBottom());
                    onCeiling = true;
                }
                velocity.y = 0;
                position = rect.getCenter();
            }
        }
    }
}
