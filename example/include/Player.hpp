#pragma once

#include <KrakenEngine.hpp>

class Player final
{
  public:
    explicit Player(const kn::Layer* collisionLayer);
    ~Player() = default;

    void update(double dt);

  private:
    void handleCollision(int axis);

    kn::AnimationController animController;
    bool facingRight = true;

    kn::Rect rect;
    kn::math::Vec2 velocity;
    const kn::Layer* collisionLayer;
    bool onGround = false;
    float moveSpeed = 45.0f;
};
