#pragma once

#include <DurkGame.hpp>


class Wall : public dk::Character {
public:
    Wall(dk::RenderWindow& window, dk::Texture& texture);
    ~Wall() = default;

    void process(double deltaTime) override;
};
