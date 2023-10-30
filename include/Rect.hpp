#pragma once

#include <SDL.h>
#include "Math.hpp"


struct DK_Rect : public SDL_Rect {
	DK_Rect() = default;
	DK_Rect(int x, int y, int w, int h) : SDL_Rect(x, y, w, h) {};

	DK_Math::Vector2i getPos();
	DK_Math::Vector2f getPosF();
    bool collidePoint(DK_Math::Vector2i pos);
    bool collidePointF(DK_Math::Vector2f pos);

	void setCenter(DK_Math::Vector2i pos);
	void setCenterF(DK_Math::Vector2f pos);
};