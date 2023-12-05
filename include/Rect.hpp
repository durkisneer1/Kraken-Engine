#pragma once

#include <SDL.h>
#include "Math.hpp"
#include "Globals.hpp"


namespace kn {
    struct Rect : public SDL_FRect {
        Rect() = default;

        Rect(float x, float y, float w, float h) : SDL_FRect{ x, y, w, h } {}
        Rect(int x, int y, int w, int h) : SDL_FRect{ (float)x, (float)y, (float)w, (float)h } {}

        kn::math::Vector2 getPos();
        kn::math::Vector2 getSize();
        bool collidePoint(kn::math::Vector2 pos);
        void clamp(kn::math::Vector2 min = {}, kn::math::Vector2 max = WIN_SIZE);
        bool collideRect(Rect rect);

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
