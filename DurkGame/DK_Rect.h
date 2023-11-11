#pragma once

#include <SDL.h>
#include "DK_Math.h"


struct DK_Rect : public SDL_FRect {
    DK_Rect() = default;

    DK_Rect(float x, float y, float w, float h) : SDL_FRect{ x, y, w, h } {}
    DK_Rect(int x, int y, int w, int h) : SDL_FRect{ (float)x, (float)y, (float)w, (float)h } {}

    DK_Math::Vector2 getPos();
    DK_Math::Vector2 getSize();
    bool collidePoint(DK_Math::Vector2 pos);

    void setCenter(DK_Math::Vector2 pos);
    void setTopLeft(DK_Math::Vector2 pos);
    void setTopMid(DK_Math::Vector2 pos);
    void setTopRight(DK_Math::Vector2 pos);
    void setBottomLeft(DK_Math::Vector2 pos);
    void setBottomMid(DK_Math::Vector2 pos);
    void setBottomRight(DK_Math::Vector2 pos);
    void setLeftMid(DK_Math::Vector2 pos);
    void setRightMid(DK_Math::Vector2 pos);

    DK_Math::Vector2 getCenter();
    DK_Math::Vector2 getTopLeft();
    DK_Math::Vector2 getTopMid();
    DK_Math::Vector2 getTopRight();
    DK_Math::Vector2 getBottomLeft();
    DK_Math::Vector2 getBottomMid();
    DK_Math::Vector2 getBottomRight();
    DK_Math::Vector2 getLeftMid();
    DK_Math::Vector2 getRightMid();
};
