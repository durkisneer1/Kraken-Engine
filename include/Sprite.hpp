#pragma once

#include <SDL.h>
#include <memory>
#include "Rect.hpp"
#include "Texture.hpp"
#include "Math.hpp"
#include "RenderWindow.hpp"


namespace dk {
    class Sprite {
    public:
        Sprite(dk::RenderWindow& window, dk::Texture& texture);
        ~Sprite() = default;

        dk::math::Vector2 getPosition() const;
        dk::Rect getRect() const;

        static const std::vector<std::unique_ptr<dk::Sprite>>& getSprites();
        static void addSprite(std::unique_ptr<dk::Sprite> sprite);

        virtual void process(double deltaTime) = 0;

    protected:
        dk::RenderWindow& window;
        dk::Texture& texture;

        dk::Rect rect;
        dk::math::Vector2 position;
        dk::math::Vector2 direction;
        dk::math::Vector2 velocity;
        bool onGround = false;
        bool onCeiling = false;

        static std::vector<std::unique_ptr<dk::Sprite>> sprites;

        void moveAndCollide(double deltaTime);

    private:
        void rectHorizontalCollision();
        void rectVerticalCollision();
    };
}