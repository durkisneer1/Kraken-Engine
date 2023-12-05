#include "../include/Sprite.hpp"


namespace dk {
    Sprite::Sprite(dk::RenderWindow& window, dk::Texture& texture)
    : window(window), texture(texture), rect(texture.getRect()) {}

    dk::math::Vector2 Sprite::getPosition() const {
        return position;
    }

    dk::Rect Sprite::getRect() const {
        return rect;
    }

    const std::vector<std::unique_ptr<dk::Sprite>>& Sprite::getSprites() {
        return sprites;
    }

    void Sprite::addSprite(std::unique_ptr<dk::Sprite> sprite) {
        sprites.push_back(std::move(sprite));
    }

    void Sprite::moveAndCollide(double deltaTime) {
        position += (velocity * deltaTime);
        rect.x = position.x - rect.w / 2.0f;
        rectHorizontalCollision();

        position.y += (velocity.y * deltaTime);
        rect.y = position.y - rect.h / 2.0f;
        rectVerticalCollision();
    }

    void Sprite::rectHorizontalCollision() {
        for (const auto& sprite : dk::Sprite::getSprites()) {
            if (sprite.get() != this) {
                if (rect.collideRect(sprite->getRect())) {
                    if (velocity.x > 0) {
                        rect.setRight(sprite->getRect().getLeft());
                    } else if (velocity.x < 0) {
                        rect.setLeft(sprite->getRect().getRight());
                    } else {}

                    velocity.x = 0;
                    position = rect.getCenter();
                } else {}
            } else {}
        }
    }

    void Sprite::rectVerticalCollision() {
        onGround = false;
        onCeiling = false;
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

    std::vector<std::unique_ptr<dk::Sprite>> Sprite::sprites;
}