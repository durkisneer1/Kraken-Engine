// DurkGame.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "DurkGame.h"
#include <iostream>


namespace dk {
	void init() {
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
			IMG_Quit();
			SDL_Quit();
			exit(3);
		}
		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
			std::cout << "Mix_OpenAudio Error: " << Mix_GetError() << std::endl;
			TTF_Quit();
			IMG_Quit();
			SDL_Quit();
		}
	}

	void quit(SDL_Window* window, SDL_Renderer* renderer) {
		Mix_CloseAudio();
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		IMG_Quit();
		TTF_Quit();
		SDL_Quit();
	}
}
