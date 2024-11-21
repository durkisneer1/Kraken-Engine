#pragma once

#include <KrakenEngine.hpp>

class Player final
{
  public:
    explicit Player(const std::vector<kn::Tile>* collisionLayer);
    ~Player() = default;

    void update(double dt);

  private:
    void handleCollision(int axis);

    kn::AnimationController animController;
    bool facingRight = true;

    kn::Rect rect;
    kn::math::Vec2 velocity;
    const std::vector<kn::Tile>* collisionLayer;
    bool onGround = false;
    float moveSpeed = 45.0f;
};
