#include "../include/Sprite.hpp"


namespace kn {
    namespace sprite {
        Sprite::Sprite(RenderWindow& window, std::shared_ptr<Texture> texture)
        : window(window), texture(texture), rect(texture->getRect()) {}

        math::Vec2 Sprite::getPosition() const {
            return position;
        }

        Rect Sprite::getRect() const {
            return rect;
        }

        template <typename T>
        void Sprite::moveAndCollide(double deltaTime, std::shared_ptr<Group<T>> group) {
            onGround = false;
            onCeiling = false;

            position += (velocity * deltaTime);
            rect.x = position.x - rect.w / 2.0f;

            for (const auto& sprite : group->getSprites()) {
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

            position.y += (velocity.y * deltaTime);
            rect.y = position.y - rect.h / 2.0f;

            for (const auto& sprite : group->getSprites()) {
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

        template <typename T>
        void Group<T>::add(std::shared_ptr<T> sprite) {
            sprites.push_back(sprite);
        }
        
        template <typename T>
        void Group<T>::empty() {
            sprites.clear();
        }

        template <typename T>
        const std::vector<std::shared_ptr<T>>& Group<T>::getSprites() const {
            return sprites;
        }
    }   
}