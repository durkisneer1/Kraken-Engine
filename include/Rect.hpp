#pragma once

#include <SDL.h>

namespace kn
{
namespace math
{
class Vec2;
} // namespace math

struct Rect : SDL_FRect
{
    Rect() = default;

    /**
     * @brief Construct a new rectangle.
     *
     * @param x The x ordinate of its top left.
     * @param y The y ordinate of its top left.
     * @param w The width.
     * @param h The height.
     */
    template <typename T>
    Rect(T x, T y, T w, T h)
        : SDL_FRect{static_cast<float>(x), static_cast<float>(y), static_cast<float>(w),
                    static_cast<float>(h)}
    {
    }

    /**
     * @brief Construct a new rectangle.
     *
     * @param pos The position of its top left.
     * @param size The size.
     */
    Rect(const math::Vec2& pos, const math::Vec2& size);

    /**
     * @brief Construct a new rectangle.
     *
     * @param pos The position of its top left.
     * @param w The width.
     * @param h The height.
     */
    template <typename T>
    Rect(const math::Vec2& pos, T w, T h)
        : SDL_FRect{static_cast<float>(pos.x), static_cast<float>(pos.y), static_cast<float>(w),
                    static_cast<float>(h)}
    {
    }

    /**
     * @brief Construct a new rectangle.
     *
     * @param x The x ordinate of its top left.
     * @param y The y ordinate of its top left.
     * @param size The size.
     */
    template <typename T>
    Rect(T x, T y, const math::Vec2& size)
        : SDL_FRect{static_cast<float>(x), static_cast<float>(y), static_cast<float>(size.x),
                    static_cast<float>(size.y)}
    {
    }

    /**
     * @brief Check if the rectangle collides with a point.
     *
     * @param pos The point to check.
     *
     * @return Whether the rectangle collides with a point.
     */
    [[nodiscard]] bool collidePoint(const math::Vec2& pos) const;

    /**
     * @brief Check if the rectangle collides with another rectangle.
     *
     * @param rect The rectangle to check.
     *
     * @return Whether the rectangle collides with another rectangle.
     */
    [[nodiscard]] bool collideRect(const Rect& rect) const;

    /**
     * @brief Clamp the rectangle within two points.
     *
     * @param min The minimum value.
     * @param max The maximum value.
     */
    void clamp(const math::Vec2& min, const math::Vec2& max);

    /**
     * @brief Clamp the rectangle within another rectangle.
     *
     * @param rect The rectangle to clamp within.
     */
    void clamp(const Rect& rect);

    operator SDL_Rect() const
    {
        return {static_cast<int>(x), static_cast<int>(y), static_cast<int>(w), static_cast<int>(h)};
    }

    // Setters
    void size(const math::Vec2& size);
    void left(float x);
    void right(float x);
    void top(float y);
    void bottom(float y);
    void topLeft(const math::Vec2& pos);
    void topMid(const math::Vec2& pos);
    void topRight(const math::Vec2& pos);
    void leftMid(const math::Vec2& pos);
    void center(const math::Vec2& pos);
    void rightMid(const math::Vec2& pos);
    void bottomLeft(const math::Vec2& pos);
    void bottomMid(const math::Vec2& pos);
    void bottomRight(const math::Vec2& pos);

    // Getters
    [[nodiscard]] math::Vec2 size() const;
    [[nodiscard]] float left() const;
    [[nodiscard]] float right() const;
    [[nodiscard]] float top() const;
    [[nodiscard]] float bottom() const;
    [[nodiscard]] math::Vec2 topLeft() const;
    [[nodiscard]] math::Vec2 topMid() const;
    [[nodiscard]] math::Vec2 topRight() const;
    [[nodiscard]] math::Vec2 leftMid() const;
    [[nodiscard]] math::Vec2 center() const;
    [[nodiscard]] math::Vec2 rightMid() const;
    [[nodiscard]] math::Vec2 bottomLeft() const;
    [[nodiscard]] math::Vec2 bottomMid() const;
    [[nodiscard]] math::Vec2 bottomRight() const;
};
} // namespace kn
