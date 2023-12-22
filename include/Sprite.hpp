#pragma once

#include <memory>
#include <vector>
#include <string>

#include <SDL.h>

#include "Rect.hpp"
#include "Texture.hpp"
#include "Math.hpp"
#include "RenderWindow.hpp"


namespace kn {
    namespace sprite {
        template <typename T>
        class Group;

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
            /// @note This function is not thread-safe.
            template <typename T>
            void moveAndCollide(double deltaTime, std::shared_ptr<Group<T>> group);
        };

        /// @brief A container for sprites.
        /// @tparam T The type of sprite.
        /// @warning Not working yet.
        template <typename T>
        class Group final {  // FIXME
        public:
            Group() = default;
            ~Group() { empty(); }

            /// @brief Add a sprite to the group.
            /// @param sprite The sprite to add.
            void add(std::shared_ptr<T> sprite);

            /// @brief Empty all sprites from group.
            void empty();

            /// @brief Get the vector list of sprites.
            /// @return The vector list of sprites.
            const std::vector<std::shared_ptr<T>>& getSprites() const;
        
        private:
            std::vector<std::shared_ptr<T>> sprites;
        };
    }
}
