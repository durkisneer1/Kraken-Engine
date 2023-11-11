#pragma once

#include <SDL.h>
#include "DK_Math.h"
#include "DK_Rect.h"


class DK_Surface {
public:
	DK_Surface() = default;
	DK_Surface(DK_Math::Vector2 size);
	~DK_Surface() {
		if (surface) SDL_FreeSurface(surface);
	}

	void fill(SDL_Color color);
	DK_Math::Vector2 getSize();
	DK_Rect getRect();
	void free() { SDL_FreeSurface(surface); }

	SDL_Surface* get() { return surface; }
	void set(SDL_Surface* setSurface);

private:
	SDL_Surface* surface = nullptr;
	DK_Rect rect = {};
};
