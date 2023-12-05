#pragma once

#include <KrakenEngine.hpp>


class Tracker {
public:
    Tracker(kn::RenderWindow& window, kn::Texture& texture);
    void process(double deltaTime);

private:
    kn::RenderWindow& window;
    kn::Texture& texture;
    kn::Rect rect;

    kn::math::Vector2 position;

    float speed = 10.0f;
};