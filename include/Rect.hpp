#pragma once

#include <SDL.h>

#include "Math.hpp"
#include "Globals.hpp"

namespace kn
{

/**
 * @brief A 2D rectangle.
 */
struct Rect : public SDL_FRect
{
    Rect() = default;

    /**
     * @brief Construct a new rectangle.
     *
     * @param x The x position.
     * @param y The y position.
     * @param w The width.
     * @param h The height.
     */
    Rect(float x, float y, float w, float h) : SDL_FRect{x, y, w, h} {}
    Rect(int x, int y, int w, int h) : SDL_FRect{(float)x, (float)y, (float)w, (float)h} {}

    /**
     * @brief Get the position of the rectangle.
     *
     * @return The position of the rectangle.
     */
    math::Vec2 getPos();

    /**
     * @brief Get the size of the rectangle.
     *
     * @return The size of the rectangle.
     */
    math::Vec2 getSize();

    /**
     * @brief Set the size of the rectangle.
     *
     * @param size The new size.
     */
    void setSize(const math::Vec2 &size);

    /**
     * @brief Check if the rectangle collides with a point.
     *
     * @param pos The point to check.
     *
     * @return Whether the rectangle collides with a point.
     */
    bool collidePoint(const math::Vec2 &pos);

    /**
     * @brief Check if the rectangle collides with another rectangle.
     *
     * @param rect The rectangle to check.
     *
     * @return Whether the rectangle collides with another rectangle.
     */
    bool collideRect(const Rect &rect);

    /**
     * @brief Clamp the rectangle.
     *
     * @param min The minimum value.
     * @param max The maximum value.
     */
    void clamp(const math::Vec2 &min = {}, const math::Vec2 &max = SCREEN_SIZE);

    void setCenter(const math::Vec2 &pos);
    void setLeft(float x);
    void setRight(float x);
    void setTop(float y);
    void setBottom(float y);
    void setTopLeft(const math::Vec2 &pos);
    void setTopMid(const math::Vec2 &pos);
    void setTopRight(const math::Vec2 &pos);
    void setBottomLeft(const math::Vec2 &pos);
    void setBottomMid(const math::Vec2 &pos);
    void setBottomRight(const math::Vec2 &pos);
    void setLeftMid(const math::Vec2 &pos);
    void setRightMid(const math::Vec2 &pos);

    math::Vec2 getCenter();
    float getLeft();
    float getRight();
    float getTop();
    float getBottom();
    math::Vec2 getTopLeft();
    math::Vec2 getTopMid();
    math::Vec2 getTopRight();
    math::Vec2 getBottomLeft();
    math::Vec2 getBottomMid();
    math::Vec2 getBottomRight();
    math::Vec2 getLeftMid();
    math::Vec2 getRightMid();
};

}
