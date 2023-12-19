#include "../include/RenderWindow.hpp"
#include <iostream>


namespace kn {
	RenderWindow::RenderWindow(const std::string &title, int scale, bool fullscreen) {
		init();
		scale = std::min(std::max(scale, 1), 32);

		this->window = SDL_CreateWindow(
			title.c_str(),
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			(int)SCREEN_SIZE.x * scale, (int)SCREEN_SIZE.y * scale,
			fullscreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN
		);

		if (!window) {
			std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
			SDL_Quit();
			exit(3);
		}

		renderer = SDL_CreateRenderer(
			window, -1, SDL_RENDERER_ACCELERATED
		);
		
		if (!renderer) {
			std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
			SDL_DestroyWindow(window);
			SDL_Quit();
			exit(3);
		}

		if (scale > 1) {
			SDL_RenderSetLogicalSize(renderer, SCREEN_SIZE.x, SCREEN_SIZE.y);
			SDL_RenderSetIntegerScale(renderer, SDL_TRUE);
		}
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
			std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
			exit(3);
		}
		if (!IMG_Init(IMG_INIT_PNG)) {
			std::cerr << "IMG_Init Error: " << IMG_GetError() << std::endl;
			SDL_Quit();
			exit(3);
		}
		if (TTF_Init() < 0) {
			std::cerr << "TTF_Init Error: " << TTF_GetError() << std::endl;
			IMG_Quit();
			SDL_Quit();
			exit(3);
		}
		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
			std::cerr << "Mix_OpenAudio Error: " << Mix_GetError() << std::endl;
			TTF_Quit();
			IMG_Quit();
			SDL_Quit();
		}
	}

	const std::vector<SDL_Event>& RenderWindow::getEvents() {
		events.clear();
		while (SDL_PollEvent(&event)) {
			events.push_back(event);
		}
		return events;
	}

	void RenderWindow::cls(SDL_Color color) {
		SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
		SDL_RenderClear(renderer);
	}

	void RenderWindow::flip() {
		SDL_RenderPresent(renderer);
	}

	void RenderWindow::blit(std::shared_ptr<kn::Texture> texture, kn::Rect rect) {
		SDL_RenderCopyF(renderer, texture->getSDLTexture(), nullptr, &rect);
	}

	void RenderWindow::blitEx(std::shared_ptr<kn::Texture> texture, kn::Rect rect, double angle, bool flipX, bool flipY) {
		SDL_RendererFlip flip = SDL_FLIP_NONE;
		if (flipX) {
			flip = (SDL_RendererFlip)(flip | SDL_FLIP_HORIZONTAL);
		}
		if (flipY) {
			flip = (SDL_RendererFlip)(flip | SDL_FLIP_VERTICAL);
		}
		SDL_RenderCopyExF(renderer, texture->getSDLTexture(), nullptr, &rect, angle, nullptr, flip);
	}

	void RenderWindow::blitEx(std::shared_ptr<kn::Texture> texture, kn::math::Vector2 position, double angle, bool flipX, bool flipY) {
		SDL_RendererFlip flip = SDL_FLIP_NONE;
		if (flipX) {
			flip = (SDL_RendererFlip)(flip | SDL_FLIP_HORIZONTAL);
		}
		if (flipY) {
			flip = (SDL_RendererFlip)(flip | SDL_FLIP_VERTICAL);
		}
		SDL_FRect rect = {
			position.x, position.y,
			texture->getSize().x, texture->getSize().y
		};
		SDL_RenderCopyExF(renderer, texture->getSDLTexture(), nullptr, &rect, angle, nullptr, flip);
	}

	void RenderWindow::blit(std::shared_ptr<kn::Texture> texture, kn::math::Vector2 position) {
		SDL_FRect rect = {
			position.x, position.y,
			texture->getSize().x, texture->getSize().y
		};
		SDL_RenderCopyF(renderer, texture->getSDLTexture(), nullptr, &rect);
	}
}
