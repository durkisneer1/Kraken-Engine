#include "../include/SpriteNode.hpp"


namespace dk {
    SpriteNode::SpriteNode(dk::RenderWindow& window, dk::Texture& texture)
    : window(window), texture(texture) {
        rect = texture.getRect();
    }

    dk::math::Vector2 SpriteNode::getPosition() const {
        return position;
    }

    dk::Rect SpriteNode::getRect() const {
        return rect;
    }

    void SpriteNode::draw() {
        texture.blit(rect);
    }
}