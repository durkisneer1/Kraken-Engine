#pragma once

#include <SDL.h>
#include "Math.hpp"


struct DK_Rect : public SDL_Rect {
	DK_Rect() = default;
	DK_Rect(int x, int y, int w, int h) : SDL_Rect(x, y, w, h) {}

	DK_Math::Vector2i getPos();
    bool collidePoint(DK_Math::Vector2i pos);

	void setCenter(DK_Math::Vector2i pos);
    void setTopLeft(DK_Math::Vector2i pos);
    void setTopMid(DK_Math::Vector2i pos);
    void setTopRight(DK_Math::Vector2i pos);
    void setBottomLeft(DK_Math::Vector2i pos);
    void setBottomMid(DK_Math::Vector2i pos);
    void setBottomRight(DK_Math::Vector2i pos);
    void setLeftMid(DK_Math::Vector2i pos);
    void setRightMid(DK_Math::Vector2i pos);

    DK_Math::Vector2i getCenter();
    DK_Math::Vector2i getTopLeft();
    DK_Math::Vector2i getTopMid();
    DK_Math::Vector2i getTopRight();
    DK_Math::Vector2i getBottomLeft();
    DK_Math::Vector2i getBottomMid();
    DK_Math::Vector2i getBottomRight();
    DK_Math::Vector2i getLeftMid();
    DK_Math::Vector2i getRightMid();
};