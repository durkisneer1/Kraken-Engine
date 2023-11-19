#include "../include/SpriteStatic.hpp"
#include <memory>


namespace dk {
    StaticSprite::StaticSprite(dk::RenderWindow& window, dk::Texture& texture)
    : SpriteNode(window, texture) {
        addStaticSprite(std::make_unique<StaticSprite>(this));
    }
}
