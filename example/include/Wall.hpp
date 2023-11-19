#pragma once

#include <DurkGame.hpp>


class Wall : public dk::StaticSprite {
public:
    Wall(dk::RenderWindow& window, dk::Texture& texture, dk::math::Vector2 position);
    ~Wall() = default;

    void process(double deltaTime) override;
};
