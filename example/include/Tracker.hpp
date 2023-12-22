#pragma once

#include <KrakenEngine.hpp>
#include <memory>


class Tracker {
public:
    Tracker(kn::RenderWindow& window, std::shared_ptr<kn::Texture> texture);
    void update(double deltaTime, kn::math::Vec2 target);

private:
    kn::RenderWindow& window;
    std::shared_ptr<kn::Texture> texture;
    kn::Rect rect;

    kn::math::Vec2 position;

    float speed = 10.0f;
};