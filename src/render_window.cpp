#include "../include/RenderWindow.hpp"
#include <iostream>


namespace dk {
	RenderWindow::RenderWindow(dk::math::Vector2 size, const char* title) {
		init();

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
		} else {}

		renderer = SDL_CreateRenderer(
			window, -1, SDL_RENDERER_ACCELERATED
		);
		
		if (!renderer) {
			std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
			SDL_DestroyWindow(window);
			SDL_Quit();
			exit(3);
		} else {}
	}

	RenderWindow::~RenderWindow() {
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		Mix_CloseAudio();
		IMG_Quit();
		TTF_Quit();
		SDL_Quit();
	}

	void RenderWindow::init() {
		if (SDL_Init(SDL_INIT_VIDEO)) {
			std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
			exit(3);
		} else {}
		if (!IMG_Init(IMG_INIT_PNG)) {
			std::cout << "IMG_Init Error: " << IMG_GetError() << std::endl;
			SDL_Quit();
			exit(3);
		} else {}
		if (TTF_Init() < 0) {
			std::cout << "TTF_Init Error: " << TTF_GetError() << std::endl;
			IMG_Quit();
			SDL_Quit();
			exit(3);
		} else {}
		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
			std::cout << "Mix_OpenAudio Error: " << Mix_GetError() << std::endl;
			TTF_Quit();
			IMG_Quit();
			SDL_Quit();
		} else {}
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

	void RenderWindow::blit(dk::Texture& texture, dk::Rect rect) {
		SDL_RenderCopyF(renderer, texture.getSDLTexture(), nullptr, &rect);
	}

	void RenderWindow::blitEx(dk::Texture& texture, dk::Rect rect, double angle, bool flipX, bool flipY) {
		SDL_RendererFlip flip = SDL_FLIP_NONE;
		if (flipX) {
			flip = (SDL_RendererFlip)(flip | SDL_FLIP_HORIZONTAL);
		} else {}
		if (flipY) {
			flip = (SDL_RendererFlip)(flip | SDL_FLIP_VERTICAL);
		} else {}
		SDL_RenderCopyExF(renderer, texture.getSDLTexture(), nullptr, &rect, angle, nullptr, flip);
	}

	void RenderWindow::blitEx(dk::Texture& texture, dk::math::Vector2 position, double angle, bool flipX, bool flipY) {
		SDL_RendererFlip flip = SDL_FLIP_NONE;
		if (flipX) {
			flip = (SDL_RendererFlip)(flip | SDL_FLIP_HORIZONTAL);
		} else {}
		if (flipY) {
			flip = (SDL_RendererFlip)(flip | SDL_FLIP_VERTICAL);
		} else {}
		SDL_FRect rect = {
			position.x, position.y,
			texture.getSize().x, texture.getSize().y
		};
		SDL_RenderCopyExF(renderer, texture.getSDLTexture(), nullptr, &rect, angle, nullptr, flip);
	}

	void RenderWindow::blit(dk::Texture& texture, dk::math::Vector2 position) {
		SDL_FRect rect = {
			position.x, position.y,
			texture.getSize().x, texture.getSize().y
		};
		SDL_RenderCopyF(renderer, texture.getSDLTexture(), nullptr, &rect);
	}
}
