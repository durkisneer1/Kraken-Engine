#pragma once

#include <SDL.h>
#include <memory>
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

        static const std::vector<std::unique_ptr<SpriteNode>>& getSpriteNodes();
        static const std::vector<std::unique_ptr<SpriteNode>>& getCharacterSprites();
        static const std::vector<std::unique_ptr<SpriteNode>>& getPhysicsSprites();
        static const std::vector<std::unique_ptr<SpriteNode>>& getStaticSprites();

        virtual void process(double deltaTime) = 0;

    protected:
        dk::RenderWindow& window;
        dk::Texture& texture;

        dk::Rect rect;
        dk::math::Vector2 position;

        static std::vector<std::unique_ptr<SpriteNode>> spriteNodes;
        static std::vector<std::unique_ptr<SpriteNode>> characterSprites;
        static std::vector<std::unique_ptr<SpriteNode>> physicsSprites;
        static std::vector<std::unique_ptr<SpriteNode>> staticSprites;

        void addCharacterSprite(std::unique_ptr<SpriteNode> sprite);
        void addPhysicsSprite(std::unique_ptr<SpriteNode> sprite);
        void addStaticSprite(std::unique_ptr<SpriteNode> sprite);
        void draw();
    };
}