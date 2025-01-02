#include "Rect.hpp"
#include "Math.hpp"

namespace kn
{
math::Vec2 Rect::getSize() const { return {w, h}; }

void Rect::setSize(const math::Vec2& size)
{
    w = static_cast<float>(size.x);
    h = static_cast<float>(size.y);
}

bool Rect::collidePoint(const math::Vec2& pos) const
{
    return pos.x >= x && pos.x <= x + w && pos.y >= y && pos.y <= y + h;
}

bool Rect::collideRect(const Rect& rect) const
{
    return x < rect.x + rect.w && x + w > rect.x && y < rect.y + rect.h && y + h > rect.y;
}

void Rect::clamp(const math::Vec2& min, const math::Vec2& max)
{
    if (max.x - min.x < this->w || max.y - min.y < this->h)
        return;

    setPoint(TOP_LEFT, clampVec(getPoint(TOP_LEFT), min, max));
    setPoint(BOTTOM_RIGHT, clampVec(getPoint(BOTTOM_RIGHT), min, max));
}

void Rect::clamp(const Rect& rect) { clamp(rect.getPoint(TOP_LEFT), rect.getPoint(BOTTOM_RIGHT)); }

void Rect::setSide(const Side side, const float value)
{
    switch (side)
    {
    case LEFT:
        this->x = value;
        break;
    case RIGHT:
        this->x = value - w;
        break;
    case TOP:
        this->y = value;
        break;
    case BOTTOM:
        this->y = value - h;
        break;
    }
}

float Rect::getSide(const Side side) const
{
    switch (side)
    {
    case LEFT:
        return x;
    case RIGHT:
        return x + w;
    case TOP:
        return y;
    case BOTTOM:
        return y + h;
    default:
        return 0.f;
    }
}

void Rect::setPoint(const Anchor anchor, const math::Vec2& pos)
{
    switch (anchor)
    {
    case TOP_LEFT:
        x = static_cast<float>(pos.x);
        y = static_cast<float>(pos.y);
        break;
    case TOP_MID:
        x = static_cast<float>(pos.x) - w / 2.f;
        y = static_cast<float>(pos.y);
        break;
    case TOP_RIGHT:
        x = static_cast<float>(pos.x) - w;
        y = static_cast<float>(pos.y);
        break;
    case LEFT_MID:
        x = static_cast<float>(pos.x);
        y = static_cast<float>(pos.y) - h / 2.f;
        break;
    case CENTER:
        x = static_cast<float>(pos.x) - w / 2.f;
        y = static_cast<float>(pos.y) - h / 2.f;
        break;
    case RIGHT_MID:
        x = static_cast<float>(pos.x) - w;
        y = static_cast<float>(pos.y) - h / 2.f;
        break;
    case BOTTOM_LEFT:
        x = static_cast<float>(pos.x);
        y = static_cast<float>(pos.y) - h;
        break;
    case BOTTOM_MID:
        x = static_cast<float>(pos.x) - w / 2.f;
        y = static_cast<float>(pos.y) - h;
        break;
    case BOTTOM_RIGHT:
        x = static_cast<float>(pos.x) - w;
        y = static_cast<float>(pos.y) - h;
        break;
    }
}

math::Vec2 Rect::getPoint(const Anchor anchor) const
{
    switch (anchor)
    {
    case TOP_LEFT:
        return {x, y};
    case TOP_MID:
        return {x + w / 2.f, y};
    case TOP_RIGHT:
        return {x + w, y};
    case LEFT_MID:
        return {x, y + h / 2.f};
    case CENTER:
        return {x + w / 2.f, y + h / 2.f};
    case RIGHT_MID:
        return {x + w, y + h / 2.f};
    case BOTTOM_LEFT:
        return {x, y + h};
    case BOTTOM_MID:
        return {x + w / 2.f, y + h};
    case BOTTOM_RIGHT:
        return {x + w, y + h};
    default:
        return {x, y};
    }
}
} // namespace kn
