#pragma once

#include <DurkGame.hpp>


class Tracker {
public:
    Tracker(dk::RenderWindow& window, dk::Texture& texture);
    void process(double deltaTime);

private:
    dk::RenderWindow& window;
    dk::Texture& texture;
    dk::Rect rect;

    dk::math::Vector2 position;

    float speed = 10.0f;
};