#pragma once

#include <KrakenEngine.hpp>
#include <memory>


class Wall : public kn::sprite::Sprite {
public:
    Wall(kn::RenderWindow& window, std::shared_ptr<kn::Texture> texture, kn::math::Vec2 position);
    ~Wall() = default;

    void update();
};
