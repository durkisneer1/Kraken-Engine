#pragma once

#include <SDL.h>
#include <vector>
#include "Math.hpp"


namespace dk {
	class RenderWindow {
	public:
		RenderWindow(dk::math::Vector2 size, const char* title);
		~RenderWindow();

		void fill(SDL_Color color);
		void flip();

		SDL_Renderer* getRenderer() { return renderer; }
		const std::vector<SDL_Event>& getEvents();
	private:
		SDL_Renderer* renderer = nullptr;
		SDL_Window* window = nullptr;

		SDL_Event event;
		std::vector<SDL_Event> events;
	};
}
