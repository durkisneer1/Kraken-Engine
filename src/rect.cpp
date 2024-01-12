#include "Rect.hpp"

namespace kn
{

math::Vec2 Rect::getPos() { return {x, y}; }

math::Vec2 Rect::getSize() { return {w, h}; }

void Rect::setSize(const math::Vec2& size)
{
    w = size.x;
    h = size.y;
}

bool Rect::collidePoint(const math::Vec2& pos)
{
    return (pos.x >= x && pos.x <= x + w && pos.y >= y && pos.y <= y + h);
}

bool Rect::collideRect(const Rect& rect)
{
    return (x < rect.x + rect.w && x + w > rect.x && y < rect.y + rect.h && y + h > rect.y);
}

void Rect::clamp(const math::Vec2& min, const math::Vec2& max)
{
    if ((max.x - min.x < this->w) || (max.y - min.y < this->h))
        return;
    setTopLeft(clampVec(getTopLeft(), min, max));
    setBottomRight(clampVec(getBottomRight(), min, max));
}

void Rect::setCenter(const math::Vec2& pos)
{
    x = pos.x - w / 2;
    y = pos.y - h / 2;
}

void Rect::setLeft(float x) { this->x = x; }

void Rect::setRight(float x) { this->x = x - w; }

void Rect::setTop(float y) { this->y = y; }

void Rect::setBottom(float y) { this->y = y - h; }

void Rect::setTopLeft(const math::Vec2& pos)
{
    x = pos.x;
    y = pos.y;
}

void Rect::setTopMid(const math::Vec2& pos)
{
    x = pos.x - w / 2;
    y = pos.y;
}

void Rect::setTopRight(const math::Vec2& pos)
{
    x = pos.x - w;
    y = pos.y;
}

void Rect::setBottomLeft(const math::Vec2& pos)
{
    x = pos.x;
    y = pos.y - h;
}

void Rect::setBottomMid(const math::Vec2& pos)
{
    x = pos.x - w / 2;
    y = pos.y - h;
}

void Rect::setBottomRight(const math::Vec2& pos)
{
    x = pos.x - w;
    y = pos.y - h;
}

void Rect::setLeftMid(const math::Vec2& pos)
{
    x = pos.x;
    y = pos.y - h / 2;
}

void Rect::setRightMid(const math::Vec2& pos)
{
    x = pos.x - w;
    y = pos.y - h / 2;
}

math::Vec2 Rect::getCenter() { return {x + w / 2, y + h / 2}; }

float Rect::getLeft() { return x; }

float Rect::getRight() { return x + w; }

float Rect::getTop() { return y; }

float Rect::getBottom() { return y + h; }

math::Vec2 Rect::getTopLeft() { return {x, y}; }

math::Vec2 Rect::getTopMid() { return {x + w / 2, y}; }

math::Vec2 Rect::getTopRight() { return {x + w, y}; }

math::Vec2 Rect::getBottomLeft() { return {x, y + h}; }

math::Vec2 Rect::getBottomMid() { return {x + w / 2, y + h}; }

math::Vec2 Rect::getBottomRight() { return {x + w, y + h}; }

math::Vec2 Rect::getLeftMid() { return {x, y + h / 2}; }

math::Vec2 Rect::getRightMid() { return {x + w, y + h / 2}; }

} // namespace kn
