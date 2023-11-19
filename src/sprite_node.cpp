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

    const std::vector<std::unique_ptr<SpriteNode>>& SpriteNode::getSpriteNodes() {
        return spriteNodes;
    }

    const std::vector<std::unique_ptr<SpriteNode>>& SpriteNode::getCharacterSprites() {
        return characterSprites;
    }

    const std::vector<std::unique_ptr<SpriteNode>>& SpriteNode::getPhysicsSprites() {
        return physicsSprites;
    }

    const std::vector<std::unique_ptr<SpriteNode>>& SpriteNode::getStaticSprites() {
        return staticSprites;
    }

    void SpriteNode::addCharacterSprite(std::unique_ptr<SpriteNode> sprite) {
        spriteNodes.push_back(std::move(sprite));
        characterSprites.push_back(std::move(sprite));
    }

    void SpriteNode::addPhysicsSprite(std::unique_ptr<SpriteNode> sprite) {
        spriteNodes.push_back(std::move(sprite));
        physicsSprites.push_back(std::move(sprite));
    }

    void SpriteNode::addStaticSprite(std::unique_ptr<SpriteNode> sprite) {
        spriteNodes.push_back(std::move(sprite));
        staticSprites.push_back(std::move(sprite));
    }

    void SpriteNode::draw() {
        texture.blit(rect);
    }

    std::vector<std::unique_ptr<SpriteNode>> SpriteNode::spriteNodes;
    std::vector<std::unique_ptr<SpriteNode>> SpriteNode::characterSprites;
    std::vector<std::unique_ptr<SpriteNode>> SpriteNode::physicsSprites;
    std::vector<std::unique_ptr<SpriteNode>> SpriteNode::staticSprites;
}