#pragma once

#include <memory>
#include <vector>

#include <SDL.h>

#include "Rect.hpp"
#include "Texture.hpp"
#include "Math.hpp"
#include "RenderWindow.hpp"


namespace kn {

/// @brief A container for a sprite.
class Sprite {
public:
    /// @brief Create a sprite.
    /// @param window The renderer context.
    /// @param texture The texture of the sprite.
    Sprite(RenderWindow& window, std::shared_ptr<Texture> texture);
    ~Sprite() = default;

    /// @brief Get the position of the sprite.
    /// @return The position of the sprite.
    math::Vec2 getPosition() const;

    /// @brief Get the rect of the sprite.
    /// @return The rect of the sprite.
    Rect getRect() const;

protected:
    RenderWindow& window;
    std::shared_ptr<Texture> texture;
    Rect rect;
    
    math::Vec2 position;
    math::Vec2 direction;
    math::Vec2 velocity;
    bool onGround = false;
    bool onCeiling = false;

    /// @brief Move the sprite while checking for collisions.
    /// @param deltaTime The time since the last frame.
    /// @param others The other sprites to check for collisions with.
    /// @note This function is not thread-safe.
    template <typename T>
    void moveAndCollide(double deltaTime, const std::vector<std::shared_ptr<T>>& others) {
        onGround = false;
        onCeiling = false;

        position += (velocity * deltaTime);
        rect.x = position.x - rect.w / 2.0f;

        for (const auto& sprite : others) {
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

        for (const auto& sprite : others) {
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
    };
};

}
