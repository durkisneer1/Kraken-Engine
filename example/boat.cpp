#include "Boat.hpp"
#include <iostream>

Boat::Boat()
    : texture("../example/assets/boat.png"), rect(texture.getRect()), pos(kn::window::getSize() / 2)
{
    rect.setCenter(pos);
}

void Boat::update(double dt)
{
    auto mousePos = kn::input::getMousePos();

    double newAngle = kn::math::angleOfDifference(pos, mousePos) - 90;
    turnAngle = kn::math::lerp(lastAngle, newAngle, dt * 2);
    lastAngle = turnAngle;

    if (firstClick)
    {
        pos = kn::math::lerpVec(pos, destination, dt);
        rect.setCenter(pos);
    }

    render();
}

void Boat::setDestination(const kn::math::Vec2& newDest)
{
    destination = newDest;
    firstClick = true;
}

void Boat::render() { kn::window::blitEx(texture, rect, {}, turnAngle); }
