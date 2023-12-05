#pragma once

#include <KrakenEngine.hpp>


class Wall : public kn::Sprite {
public:
    Wall(kn::RenderWindow& window, kn::Texture& texture, kn::math::Vector2 position);
    ~Wall() = default;

    void process(double deltaTime) override;
};
