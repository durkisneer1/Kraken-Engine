#include "../include/SpriteNode.hpp"


namespace dk {
    SpriteNode::SpriteNode(dk::RenderWindow& window, dk::Texture& texture)
    : window(window), texture(texture) {
        rect = texture.getRect();
        spriteNodes.push_back(this);
    }

    dk::math::Vector2 SpriteNode::getPosition() const {
        return position;
    }

    dk::Rect SpriteNode::getRect() const {
        return rect;
    }

    const std::vector<SpriteNode*>& SpriteNode::getSpriteNodes() {
        return spriteNodes;
    }

    const std::vector<SpriteNode*>& SpriteNode::getCharacterSprites() {
        return characterSprites;
    }

    const std::vector<SpriteNode*>& SpriteNode::getPhysicsSprites() {
        return physicsSprites;
    }

    const std::vector<SpriteNode*>& SpriteNode::getStaticSprites() {
        return staticSprites;
    }

    void SpriteNode::draw() {
        texture.blit(rect);
    }

    std::vector<SpriteNode*> SpriteNode::spriteNodes;
    std::vector<SpriteNode*> SpriteNode::characterSprites;
    std::vector<SpriteNode*> SpriteNode::physicsSprites;
    std::vector<SpriteNode*> SpriteNode::staticSprites;
}