#pragma once

#include <SDL.h>
#include "Rect.hpp"
#include "Texture.hpp"
#include "Math.hpp"
#include "RenderWindow.hpp"


namespace dk {
    class SpriteNode {
    public:
        SpriteNode(dk::RenderWindow& window, dk::Texture& texture);
        ~SpriteNode() = default;

        dk::math::Vector2 getPosition() const;
        dk::Rect getRect() const;

        virtual void process(double deltaTime) = 0;

    protected:
        dk::RenderWindow& window;
        dk::Texture& texture;

        dk::Rect rect;
        dk::math::Vector2 position;

        void draw();
    };
}