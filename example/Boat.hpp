#pragma once

#include <KrakenEngine.hpp>

class Boat
{
  public:
    Boat();

    void update(double dt);

    void setDestination(const kn::math::Vec2& newDest);

  private:
    void render();

    kn::Texture texture;
    kn::Rect rect;
    kn::math::Vec2 pos;
    kn::math::Vec2 destination;
    float turnAngle = 0.0f;
    float lastAngle = 0.0f;
    float speed = 20;
    bool firstClick = false;
};
