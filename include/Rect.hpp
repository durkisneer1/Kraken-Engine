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
        kn::math::Vector2 getPos();

        /// @brief Get the size of the rectangle.
        /// @return The size of the rectangle.
        kn::math::Vector2 getSize();

        /// @brief Check if the rectangle collides with a point.
        /// @param pos The point to check.
        /// @return Whether the rectangle collides with a point.
        bool collidePoint(kn::math::Vector2 pos);

        /// @brief Check if the rectangle collides with another rectangle.
        /// @param rect The rectangle to check.
        /// @return Whether the rectangle collides with another rectangle.
        bool collideRect(Rect rect);

        /// @brief Clamp the rectangle.
        /// @param min The minimum value.
        /// @param max The maximum value.
        void clamp(kn::math::Vector2 min = {}, kn::math::Vector2 max = WIN_SIZE);

        void setCenter(kn::math::Vector2 pos);
        void setLeft(float x);
        void setRight(float x);
        void setTop(float y);
        void setBottom(float y);
        void setTopLeft(kn::math::Vector2 pos);
        void setTopMid(kn::math::Vector2 pos);
        void setTopRight(kn::math::Vector2 pos);
        void setBottomLeft(kn::math::Vector2 pos);
        void setBottomMid(kn::math::Vector2 pos);
        void setBottomRight(kn::math::Vector2 pos);
        void setLeftMid(kn::math::Vector2 pos);
        void setRightMid(kn::math::Vector2 pos);

        kn::math::Vector2 getCenter();
        float getLeft();
        float getRight();
        float getTop();
        float getBottom();
        kn::math::Vector2 getTopLeft();
        kn::math::Vector2 getTopMid();
        kn::math::Vector2 getTopRight();
        kn::math::Vector2 getBottomLeft();
        kn::math::Vector2 getBottomMid();
        kn::math::Vector2 getBottomRight();
        kn::math::Vector2 getLeftMid();
        kn::math::Vector2 getRightMid();
    };
}
