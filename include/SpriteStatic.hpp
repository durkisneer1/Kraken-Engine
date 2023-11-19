#pragma once

#include "SpriteNode.hpp"


namespace dk {
    class StaticSprite : public SpriteNode {
    public:
        StaticSprite(dk::RenderWindow& window, dk::Texture& texture);
        ~StaticSprite() = default;
    };
}