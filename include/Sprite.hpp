#pragma once

#include <SDL.h>
#include <memory>
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
        Sprite(kn::RenderWindow& window, std::shared_ptr<kn::Texture> texture);
        ~Sprite() = default;

        /// @brief Get the position of the sprite.
        /// @return The position of the sprite.
        kn::math::Vector2 getPosition() const;

        /// @brief Get the rect of the sprite.
        /// @return The rect of the sprite.
        kn::Rect getRect() const;

        /// @brief Get the list of all sprites.
        /// @return The list of all sprites.
        static const std::vector<std::unique_ptr<kn::Sprite>>& getSprites();

        /// @brief Add a sprite to the list of all sprites.
        /// @param sprite The sprite to add.
        static void addSprite(std::unique_ptr<kn::Sprite> sprite);

        /// @brief Mandatory function to be implemented by the user for updating the sprite.
        /// @param deltaTime The time since the last frame.
        virtual void process(double deltaTime) = 0;

    protected:
        kn::RenderWindow& window;
        std::shared_ptr<kn::Texture> texture;
        kn::Rect rect;
        
        kn::math::Vector2 position;
        kn::math::Vector2 direction;
        kn::math::Vector2 velocity;
        bool onGround = false;
        bool onCeiling = false;

        /// @brief Move the sprite while checking for collisions.
        /// @param deltaTime The time since the last frame.
        /// @note This function is not thread-safe.
        void moveAndCollide(double deltaTime);

    private:
        static std::vector<std::unique_ptr<kn::Sprite>> sprites;

        void rectHorizontalCollision();
        void rectVerticalCollision();
    };
}
