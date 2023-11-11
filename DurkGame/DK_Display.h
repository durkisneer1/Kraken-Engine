#pragma once

#include <SDL.h>
#include <iostream>
#include "DK_Math.h"


namespace DK_Display {
	SDL_Window* setMode(const char* title, DK_Math::Vector2 size);
	SDL_Renderer* setRenderer(SDL_Window* window);

	void cls(SDL_Renderer* renderer);
	void fill(SDL_Renderer* renderer, SDL_Color color);
	void flip(SDL_Renderer* renderer);
}
