#pragma once

#include <KrakenEngine.hpp>
#include <unordered_map>

enum AnimState
{
    IDLE,
    WALK
};

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
    AnimState animState = IDLE;
    std::unordered_map<AnimState, kn::Texture> animMap;

    kn::Rect rect;
    kn::math::Vec2 velocity;
    const kn::Layer* collisionLayer;
    bool onGround = false;
    float moveSpeed = 45.0f;
};