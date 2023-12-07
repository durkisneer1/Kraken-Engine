#pragma once

#include <KrakenEngine.hpp>
#include <memory>


class Wall : public kn::Sprite {
public:
    Wall(kn::RenderWindow& window, std::shared_ptr<kn::Texture> texture, kn::math::Vector2 position);
    ~Wall() = default;

    void process(double deltaTime) override;
};
