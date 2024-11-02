#include "Rect.hpp"
#include "Math.hpp"

namespace kn
{
math::Vec2 Rect::getPos() { return {x, y}; }

math::Vec2 Rect::getSize() { return {w, h}; }

Rect::Rect(const float x, const float y, const float w, const float h) : SDL_FRect{x, y, w, h} {}

Rect::Rect(const int x, const int y, const int w, const int h)
    : SDL_FRect{static_cast<float>(x), static_cast<float>(y), static_cast<float>(w),
                static_cast<float>(h)}
{
}

void Rect::setSize(const math::Vec2& size)
{
    w = static_cast<float>(size.x);
    h = static_cast<float>(size.y);
}

bool Rect::collidePoint(const math::Vec2& pos) const
{
    return (pos.x >= x && pos.x <= x + w && pos.y >= y && pos.y <= y + h);
}

bool Rect::collideRect(const Rect& rect) const
{
    return x < rect.x + rect.w && x + w > rect.x && y < rect.y + rect.h && y + h > rect.y;
}

void Rect::clamp(const math::Vec2& min, const math::Vec2& max)
{
    if (max.x - min.x < this->w || max.y - min.y < this->h)
        return;
    setTopLeft(clampVec(getTopLeft(), min, max));
    setBottomRight(clampVec(getBottomRight(), min, max));
}

void Rect::setCenter(const math::Vec2& pos)
{
    x = static_cast<float>(pos.x - w / 2);
    y = static_cast<float>(pos.y - h / 2);
}

void Rect::setLeft(const float x) { this->x = x; }

void Rect::setRight(const float x) { this->x = x - w; }

void Rect::setTop(const float y) { this->y = y; }

void Rect::setBottom(const float y) { this->y = y - h; }

void Rect::setTopLeft(const math::Vec2& pos)
{
    x = static_cast<float>(pos.x);
    y = static_cast<float>(pos.y);
}

void Rect::setTopMid(const math::Vec2& pos)
{
    x = static_cast<float>(pos.x - w / 2);
    y = static_cast<float>(pos.y);
}

void Rect::setTopRight(const math::Vec2& pos)
{
    x = static_cast<float>(pos.x - w);
    y = static_cast<float>(pos.y);
}

void Rect::setBottomLeft(const math::Vec2& pos)
{
    x = static_cast<float>(pos.x);
    y = static_cast<float>(pos.y - h);
}

void Rect::setBottomMid(const math::Vec2& pos)
{
    x = static_cast<float>(pos.x - w / 2);
    y = static_cast<float>(pos.y - h);
}

void Rect::setBottomRight(const math::Vec2& pos)
{
    x = static_cast<float>(pos.x - w);
    y = static_cast<float>(pos.y - h);
}

void Rect::setLeftMid(const math::Vec2& pos)
{
    x = static_cast<float>(pos.x);
    y = static_cast<float>(pos.y - h / 2);
}

void Rect::setRightMid(const math::Vec2& pos)
{
    x = static_cast<float>(pos.x - w);
    y = static_cast<float>(pos.y - h / 2.f);
}

math::Vec2 Rect::getCenter() const { return {x + w / 2, y + h / 2}; }

float Rect::getLeft() const { return x; }

float Rect::getRight() const { return x + w; }

float Rect::getTop() const { return y; }

float Rect::getBottom() const { return y + h; }

math::Vec2 Rect::getTopLeft() const { return {x, y}; }

math::Vec2 Rect::getTopMid() const { return {x + w / 2, y}; }

math::Vec2 Rect::getTopRight() const { return {x + w, y}; }

math::Vec2 Rect::getBottomLeft() const { return {x, y + h}; }

math::Vec2 Rect::getBottomMid() const { return {x + w / 2, y + h}; }

math::Vec2 Rect::getBottomRight() const { return {x + w, y + h}; }

math::Vec2 Rect::getLeftMid() const { return {x, y + h / 2}; }

math::Vec2 Rect::getRightMid() const { return {x + w, y + h / 2}; }
} // namespace kn
