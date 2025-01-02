#pragma once

#include <SDL.h>

namespace kn
{
namespace math
{
class Vec2;
} // namespace math

enum Anchor
{
    TOP_LEFT,
    TOP_MID,
    TOP_RIGHT,
    LEFT_MID,
    CENTER,
    RIGHT_MID,
    BOTTOM_LEFT,
    BOTTOM_MID,
    BOTTOM_RIGHT
};

enum Side
{
    LEFT,
    RIGHT,
    TOP,
    BOTTOM
};

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
     * @brief Get the size of the rectangle.
     *
     * @return The size of the rectangle.
     */
    [[nodiscard]] math::Vec2 getSize() const;

    /**
     * @brief Set the size of the rectangle.
     *
     * @param size The new size.
     */
    void setSize(const math::Vec2& size);

    /**
     * @brief Set the position of a side of the rect.
     *
     * @param side The side to set.
     * @param value The new position.
     */
    void setSide(Side side, float value);

    /**
     * @brief Get the position of a side of the rect.
     *
     * @param side The side to get.
     *
     * @return The position of the side.
     */
    [[nodiscard]] float getSide(Side side) const;

    /**
     * @brief Set the position of a point on the rect.
     *
     * @param anchor The anchor point.
     * @param pos The new position.
     */
    void setPoint(Anchor anchor, const math::Vec2& pos);

    /**
     * @brief Get the position of a point on the rect.
     *
     * @param anchor The anchor point.
     *
     * @return The position of the point.
     */
    [[nodiscard]] math::Vec2 getPoint(Anchor anchor) const;

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
};
} // namespace kn
