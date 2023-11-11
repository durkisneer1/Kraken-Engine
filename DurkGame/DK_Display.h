#pragma once

#include <SDL.h>
#include <iostream>
#include "DK_Math.h"


namespace dk {
	namespace display {
		SDL_Window* setMode(const char* title, dk::math::Vector2 size);
		SDL_Renderer* setRenderer(SDL_Window* window);

		void cls(SDL_Renderer* renderer);
		void fill(SDL_Renderer* renderer, SDL_Color color);
		void flip(SDL_Renderer* renderer);
	}
}
