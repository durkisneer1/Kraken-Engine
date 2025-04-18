#include "Rect.hpp"
#include "Math.hpp"

namespace kn
{
Rect::Rect(const math::Vec2& pos, const math::Vec2& size)
    : SDL_FRect{static_cast<float>(pos.x), static_cast<float>(pos.y), static_cast<float>(size.x),
                static_cast<float>(size.y)}
{
}

bool Rect::collidePoint(const math::Vec2& pos) const
{
    return pos.x >= x && pos.x <= x + w && pos.y >= y && pos.y <= y + h;
}

bool Rect::collideRect(const Rect& rect) const { return SDL_HasIntersectionF(this, &rect); }

void Rect::clamp(const math::Vec2& min, const math::Vec2& max)
{
    if (max.x - min.x < this->w || max.y - min.y < this->h)
        return;

    topLeft(clampVec(topLeft(), min, max));
    bottomRight(clampVec(bottomRight(), min, max));
}

void Rect::clamp(const Rect& rect) { clamp(rect.topLeft(), rect.bottomRight()); }

void Rect::scaleBy(const float factor)
{
    if (factor < 0.f || factor == 1.f)
        return;

    w *= factor;
    h *= factor;
}

// Setters
void Rect::size(const math::Vec2& size)
{
    w = static_cast<float>(size.x);
    h = static_cast<float>(size.y);
}
void Rect::left(const float x) { this->x = x; }
void Rect::right(const float x) { this->x = x - w; }
void Rect::top(const float y) { this->y = y; }
void Rect::bottom(const float y) { this->y = y - h; }
void Rect::topLeft(const math::Vec2& pos)
{
    x = static_cast<float>(pos.x);
    y = static_cast<float>(pos.y);
}
void Rect::topMid(const math::Vec2& pos)
{
    x = static_cast<float>(pos.x) - w / 2.f;
    y = static_cast<float>(pos.y);
}
void Rect::topRight(const math::Vec2& pos)
{
    x = static_cast<float>(pos.x) - w;
    y = static_cast<float>(pos.y);
}
void Rect::leftMid(const math::Vec2& pos)
{
    x = static_cast<float>(pos.x);
    y = static_cast<float>(pos.y) - h / 2.f;
}
void Rect::center(const math::Vec2& pos)
{
    x = static_cast<float>(pos.x) - w / 2.f;
    y = static_cast<float>(pos.y) - h / 2.f;
}
void Rect::rightMid(const math::Vec2& pos)
{
    x = static_cast<float>(pos.x) - w;
    y = static_cast<float>(pos.y) - h / 2.f;
}
void Rect::bottomLeft(const math::Vec2& pos)
{
    x = static_cast<float>(pos.x);
    y = static_cast<float>(pos.y) - h;
}
void Rect::bottomMid(const math::Vec2& pos)
{
    x = static_cast<float>(pos.x) - w / 2.f;
    y = static_cast<float>(pos.y) - h;
}
void Rect::bottomRight(const math::Vec2& pos)
{
    x = static_cast<float>(pos.x) - w;
    y = static_cast<float>(pos.y) - h;
}

// Getters
math::Vec2 Rect::size() const { return {w, h}; }
float Rect::left() const { return x; }
float Rect::right() const { return x + w; }
float Rect::top() const { return y; }
float Rect::bottom() const { return y + h; }
math::Vec2 Rect::topLeft() const { return {x, y}; }
math::Vec2 Rect::topMid() const { return {x + w / 2.f, y}; }
math::Vec2 Rect::topRight() const { return {x + w, y}; }
math::Vec2 Rect::leftMid() const { return {x, y + h / 2.f}; }
math::Vec2 Rect::center() const { return {x + w / 2.f, y + h / 2.f}; }
math::Vec2 Rect::rightMid() const { return {x + w, y + h / 2.f}; }
math::Vec2 Rect::bottomLeft() const { return {x, y + h}; }
math::Vec2 Rect::bottomMid() const { return {x + w / 2.f, y + h}; }
math::Vec2 Rect::bottomRight() const { return {x + w, y + h}; }

} // namespace kn
