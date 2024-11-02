#pragma once

#include <KrakenEngine.hpp>

class Player
{
  public:
    explicit Player(const kn::Layer* collisionLayer);
    ~Player() = default;

    void update(double dt);

  private:
    void handleCollision(int axis);

    kn::Texture texture;
    kn::Rect rect;
    kn::math::Vec2 velocity;
    const kn::Layer* collisionLayer;
    bool onGround = false;
    float moveSpeed = 45.0f;
};