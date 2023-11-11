#include "pch.h"
#include "DK_Surface.h"


DK_Surface::DK_Surface(DK_Math::Vector2 size) {
	surface = SDL_CreateRGBSurface(0, (int)size.x, (int)size.y, 32, 0, 0, 0, 0);
	rect.w = size.x;
	rect.h = size.y;
}

void DK_Surface::fill(SDL_Color color) {
	SDL_FillRect(surface, nullptr, SDL_MapRGB(surface->format, color.r, color.g, color.b));
}

DK_Math::Vector2 DK_Surface::getSize() {
	return { rect.w, rect.h };
}

DK_Rect DK_Surface::getRect() {
	return rect;
}

void DK_Surface::set(SDL_Surface* setSurface) {
	surface = setSurface;
	rect = { 0, 0, surface->w, surface->h };
}
