#pragma once

#include <SDL.h>
#include <memory>
#include "Rect.hpp"
#include "Texture.hpp"
#include "Math.hpp"
#include "RenderWindow.hpp"


namespace kn {
    class Sprite {
    public:
        Sprite(kn::RenderWindow& window, kn::Texture& texture);
        ~Sprite() = default;

        kn::math::Vector2 getPosition() const;
        kn::Rect getRect() const;

        static const std::vector<std::unique_ptr<kn::Sprite>>& getSprites();
        static void addSprite(std::unique_ptr<kn::Sprite> sprite);

        virtual void process(double deltaTime) = 0;

    protected:
        kn::RenderWindow& window;
        kn::Texture& texture;
        kn::Rect rect;
        
        kn::math::Vector2 position;
        kn::math::Vector2 direction;
        kn::math::Vector2 velocity;
        bool onGround = false;
        bool onCeiling = false;

        void moveAndCollide(double deltaTime);

    private:
        static std::vector<std::unique_ptr<kn::Sprite>> sprites;

        void rectHorizontalCollision();
        void rectVerticalCollision();
    };
}