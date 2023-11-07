#include "../include/Display.hpp"


namespace DK_Display {
	SDL_Window *setMode(const char *title, DK_Math::Vector2 size) {
		SDL_Window *window = SDL_CreateWindow(
			title,
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			(int)size.x, (int)size.y, SDL_WINDOW_SHOWN);
		if (window == nullptr) {
			std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
			SDL_Quit();
			exit(3);
		}
		return window;
	}

	SDL_Renderer *setRenderer(SDL_Window *window) {
		SDL_Renderer *renderer = SDL_CreateRenderer(
			window, -1, SDL_RENDERER_ACCELERATED
		);
		if (renderer == nullptr) {
			std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
			SDL_DestroyWindow(window);
			SDL_Quit();
			exit(3);
		}
		return renderer;
	}

	void cls(SDL_Renderer *renderer) {
		SDL_RenderClear(renderer);
	}

	void fill(SDL_Renderer *renderer, SDL_Color color) {
		SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
		SDL_RenderFillRect(renderer, nullptr);
	}

	void flip(SDL_Renderer *renderer) {
		SDL_RenderPresent(renderer);
	}
}
