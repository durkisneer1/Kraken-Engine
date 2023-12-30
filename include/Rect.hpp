#pragma once

#include <SDL.h>

#include "Math.hpp"
#include "Globals.hpp"


namespace kn {

/// @brief A class to represent a rectangle.
struct Rect : public SDL_FRect {
    Rect() = default;

    Rect(float x, float y, float w, float h) : SDL_FRect{ x, y, w, h } {}
    Rect(int x, int y, int w, int h) : SDL_FRect{ (float)x, (float)y, (float)w, (float)h } {}

    /// @brief Get the position of the rectangle.
    /// @return The position of the rectangle.
    math::Vec2 getPos();

    /// @brief Get the size of the rectangle.
    /// @return The size of the rectangle.
    math::Vec2 getSize();

    /// @brief Set the size of the rectangle.
    /// @param size The new size.
    void setSize(math::Vec2 size);

    /// @brief Check if the rectangle collides with a point.
    /// @param pos The point to check.
    /// @return Whether the rectangle collides with a point.
    bool collidePoint(math::Vec2 pos);

    /// @brief Check if the rectangle collides with another rectangle.
    /// @param rect The rectangle to check.
    /// @return Whether the rectangle collides with another rectangle.
    bool collideRect(Rect& rect);

    /// @brief Clamp the rectangle.
    /// @param min The minimum value.
    /// @param max The maximum value.
    void clamp(math::Vec2 min = {}, math::Vec2 max = SCREEN_SIZE);

    void setCenter(math::Vec2 pos);
    void setLeft(float x);
    void setRight(float x);
    void setTop(float y);
    void setBottom(float y);
    void setTopLeft(math::Vec2 pos);
    void setTopMid(math::Vec2 pos);
    void setTopRight(math::Vec2 pos);
    void setBottomLeft(math::Vec2 pos);
    void setBottomMid(math::Vec2 pos);
    void setBottomRight(math::Vec2 pos);
    void setLeftMid(math::Vec2 pos);
    void setRightMid(math::Vec2 pos);

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
