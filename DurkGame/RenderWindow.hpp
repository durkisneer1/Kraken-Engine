#pragma once

#include <SDL.h>
#include "Math.hpp"


namespace dk {
	class RenderWindow {
	public:
		RenderWindow(dk::math::Vector2 size, const char* title);
		~RenderWindow();

		void fill(SDL_Color color);
		void flip();

		SDL_Renderer* getRenderer() { return renderer; }
	private:
		SDL_Renderer* renderer = nullptr;
		SDL_Window* window = nullptr;
	};
}
