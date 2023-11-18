#pragma once

#include <DurkGame.hpp>


class Wall : public dk::CharacterSprite {
public:
    Wall(dk::RenderWindow& window, dk::Texture& texture);
    ~Wall() = default;

    void process(double deltaTime) override;
};
