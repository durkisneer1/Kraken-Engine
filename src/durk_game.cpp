#include "../include/DurkGame.hpp"
#include <iostream>


void DK_Init() {
	if (SDL_Init(SDL_INIT_VIDEO)) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		exit(3);
	}
	if (!IMG_Init(IMG_INIT_PNG)) {
		std::cout << "IMG_Init Error: " << IMG_GetError() << std::endl;
		SDL_Quit();
		exit(3);
	}
	if (TTF_Init() < 0) {
		std::cout << "TTF_Init Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		IMG_Quit();
		exit(3);
	};
}

void DK_Quit(SDL_Window* window, SDL_Renderer* renderer) {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	IMG_Quit();
	TTF_Quit();
}