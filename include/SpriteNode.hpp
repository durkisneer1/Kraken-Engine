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

        static const std::vector<SpriteNode*>& getSpriteNodes();
        static const std::vector<SpriteNode*>& getCharacterSprites();
        static const std::vector<SpriteNode*>& getPhysicsSprites();
        static const std::vector<SpriteNode*>& getStaticSprites();

        virtual void process(double deltaTime) = 0;

    protected:
        dk::RenderWindow& window;
        dk::Texture& texture;

        dk::Rect rect;
        dk::math::Vector2 position;

        static std::vector<SpriteNode*> spriteNodes;
        static std::vector<SpriteNode*> characterSprites;
        static std::vector<SpriteNode*> physicsSprites;
        static std::vector<SpriteNode*> staticSprites;

        void draw();
    };
}