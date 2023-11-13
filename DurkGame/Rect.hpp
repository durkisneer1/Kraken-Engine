#pragma once

#include <SDL.h>
#include "Math.hpp"
#include "Globals.hpp"


namespace dk {
    struct Rect : public SDL_FRect {
        Rect() = default;

        Rect(float x, float y, float w, float h) : SDL_FRect{ x, y, w, h } {}
        Rect(int x, int y, int w, int h) : SDL_FRect{ (float)x, (float)y, (float)w, (float)h } {}

        dk::math::Vector2 getPos();
        dk::math::Vector2 getSize();
        bool collidePoint(dk::math::Vector2 pos);
        void clamp(dk::math::Vector2 min = {}, dk::math::Vector2 max = WIN_SIZE);

        void setCenter(dk::math::Vector2 pos);
        void setTopLeft(dk::math::Vector2 pos);
        void setTopMid(dk::math::Vector2 pos);
        void setTopRight(dk::math::Vector2 pos);
        void setBottomLeft(dk::math::Vector2 pos);
        void setBottomMid(dk::math::Vector2 pos);
        void setBottomRight(dk::math::Vector2 pos);
        void setLeftMid(dk::math::Vector2 pos);
        void setRightMid(dk::math::Vector2 pos);

        dk::math::Vector2 getCenter();
        dk::math::Vector2 getTopLeft();
        dk::math::Vector2 getTopMid();
        dk::math::Vector2 getTopRight();
        dk::math::Vector2 getBottomLeft();
        dk::math::Vector2 getBottomMid();
        dk::math::Vector2 getBottomRight();
        dk::math::Vector2 getLeftMid();
        dk::math::Vector2 getRightMid();
    };
}
