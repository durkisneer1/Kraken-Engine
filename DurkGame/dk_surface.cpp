#include "pch.h"
#include "DK_Surface.h"


namespace dk {
	Surface::Surface(dk::math::Vector2 size) {
		surface = SDL_CreateRGBSurface(0, (int)size.x, (int)size.y, 32, 0, 0, 0, 0);
		rect.w = size.x;
		rect.h = size.y;
	}

	void Surface::fill(SDL_Color color) {
		SDL_FillRect(surface, nullptr, SDL_MapRGB(surface->format, color.r, color.g, color.b));
	}

	dk::math::Vector2 Surface::getSize() {
		return { rect.w, rect.h };
	}

	dk::Rect Surface::getRect() {
		return rect;
	}

	void Surface::set(SDL_Surface* setSurface) {
		surface = setSurface;
		rect = { 0, 0, surface->w, surface->h };
	}
}
