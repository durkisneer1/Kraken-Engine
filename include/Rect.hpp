#pragma once

#include <SDL.h>

namespace kn
{
namespace math
{
class Vec2;
} // namespace math
/**
 * @brief A 2D rectangle.
 */
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
     * @brief Get the position of the rectangle.
     *
     * @return The position of the rectangle.
     */
    [[nodiscard]] math::Vec2 getPos() const;

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

    void setLeft(float x);
    void setRight(float x);
    void setTop(float y);
    void setBottom(float y);
    void setTopLeft(const math::Vec2& pos);
    void setTopMid(const math::Vec2& pos);
    void setTopRight(const math::Vec2& pos);
    void setLeftMid(const math::Vec2& pos);
    void setCenter(const math::Vec2& pos);
    void setRightMid(const math::Vec2& pos);
    void setBottomLeft(const math::Vec2& pos);
    void setBottomMid(const math::Vec2& pos);
    void setBottomRight(const math::Vec2& pos);

    [[nodiscard]] float getLeft() const;
    [[nodiscard]] float getRight() const;
    [[nodiscard]] float getTop() const;
    [[nodiscard]] float getBottom() const;
    [[nodiscard]] math::Vec2 getTopLeft() const;
    [[nodiscard]] math::Vec2 getTopMid() const;
    [[nodiscard]] math::Vec2 getTopRight() const;
    [[nodiscard]] math::Vec2 getLeftMid() const;
    [[nodiscard]] math::Vec2 getCenter() const;
    [[nodiscard]] math::Vec2 getRightMid() const;
    [[nodiscard]] math::Vec2 getBottomLeft() const;
    [[nodiscard]] math::Vec2 getBottomMid() const;
    [[nodiscard]] math::Vec2 getBottomRight() const;
};
} // namespace kn
