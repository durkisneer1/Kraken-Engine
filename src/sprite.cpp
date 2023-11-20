#include "../include/Sprite.hpp"


namespace dk {
    Sprite::Sprite(dk::RenderWindow& window, dk::Texture& texture)
    : window(window), texture(texture) {
        rect = texture.getRect();
    }

    dk::math::Vector2 Sprite::getPosition() const {
        return position;
    }

    dk::Rect Sprite::getRect() const {
        return rect;
    }

    const std::vector<std::unique_ptr<dk::Sprite>>& Sprite::getSprites() {
        return sprites;
    }

    void Sprite::addSprite(std::unique_ptr<dk::Sprite> sprite) {
        sprites.push_back(std::move(sprite));
    }

    void Sprite::draw() {
        texture.blit(rect);
    }

    std::vector<std::unique_ptr<dk::Sprite>> Sprite::sprites;
}