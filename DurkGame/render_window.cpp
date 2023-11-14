#include "pch.h"
#include "RenderWindow.hpp"
#include <iostream>


namespace dk {
	RenderWindow::RenderWindow(dk::math::Vector2 size, const char* title) {
		this->window = SDL_CreateWindow(
			title,
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			(int)size.x, (int)size.y,
			SDL_WINDOW_SHOWN
		);
		if (!window) {
			std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
			SDL_Quit();
			exit(3);
		}
		renderer = SDL_CreateRenderer(
			window, -1, SDL_RENDERER_ACCELERATED
		);
		if (!renderer) {
			std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
			SDL_DestroyWindow(window);
			SDL_Quit();
			exit(3);
		}
	}

	RenderWindow::~RenderWindow() {
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
	}

	const std::vector<SDL_Event>& RenderWindow::getEvents() {
		events.clear();
		while (SDL_PollEvent(&event)) {
			events.push_back(event);
		}
		return events;
	}

	void RenderWindow::fill(SDL_Color color) {
		SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
		SDL_RenderClear(renderer);
	}

	void RenderWindow::flip() {
		SDL_RenderPresent(renderer);
	}
}