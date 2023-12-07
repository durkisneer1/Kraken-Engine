#pragma once

#include <KrakenEngine.hpp>
#include <memory>


class Tracker {
public:
    Tracker(kn::RenderWindow& window, std::shared_ptr<kn::Texture> texture);
    void update(double deltaTime, kn::math::Vector2 target);

private:
    kn::RenderWindow& window;
    std::shared_ptr<kn::Texture> texture;
    kn::Rect rect;

    kn::math::Vector2 position;

    float speed = 10.0f;
};