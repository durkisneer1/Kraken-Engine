#include "../include/Texture.hpp"
#include <iostream>


namespace dk {
	Texture::Texture(dk::RenderWindow& window, const char* fileDir)
	: window(window) {
		loadTextureFile(fileDir);
	}

	Texture::Texture(dk::RenderWindow& window, dk::math::Vector2 size, SDL_Color color)
	: window(window) {
		SDL_Surface* surface = SDL_CreateRGBSurface(0, (int)size.x, (int)size.y, 32, 0, 0, 0, 0);
		if (surface == nullptr) {
			std::cout << "SDL_CreateRGBSurface Error: " << SDL_GetError() << std::endl;
			exit(3);
		} else {}

		SDL_FillRect(surface, nullptr, SDL_MapRGB(surface->format, color.r, color.g, color.b));
		texture = SDL_CreateTextureFromSurface(window.getRenderer(), surface);
		if (texture == nullptr) {
			std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
		} else {}

		SDL_FreeSurface(surface);
		query();
	}

	Texture::Texture(dk::RenderWindow& window, SDL_Surface* surface)
	: window(window) {
		texture = SDL_CreateTextureFromSurface(window.getRenderer(), surface);
		if (!texture) {
			std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
			exit(3);
		} else {}

		query();
	}

	Texture::Texture(dk::RenderWindow& window, SDL_Texture* texture)
	: window(window), texture(texture) {
		query();
	}

	void Texture::query() {
		int w, h;
		SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);
		this->rect = { 0, 0, w, h };
	}

	void Texture::loadTextureFile(const char* fileDir) {
		texture = IMG_LoadTexture(window.getRenderer(), fileDir);
		if (!texture) {
			std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
			exit(3);
		} else {}

		query();
	}

	void Texture::drawAt(dk::Rect dstRect) {
		SDL_RenderCopyF(window.getRenderer(), texture, nullptr, &dstRect);
	}

	void Texture::drawAtEx(dk::Rect dstRect, float angleDeg, bool flipX, bool flipY) {
		SDL_RendererFlip flip = SDL_FLIP_NONE;
		if (flipX) {
			flip = (SDL_RendererFlip)(flip | SDL_FLIP_HORIZONTAL);
		} else {}
		if (flipY) {
			flip = (SDL_RendererFlip)(flip | SDL_FLIP_VERTICAL);
		} else {}
		SDL_RenderCopyExF(window.getRenderer(), texture, nullptr, &dstRect, angleDeg, nullptr, flip);
	}

	dk::math::Vector2 dk::Texture::getSize() const {
		return { rect.w, rect.h };
	}

	void Texture::setSize(int w, int h) {
		rect.w = (float)w;
		rect.h = (float)h;
	}

	void Texture::scaleBy(float scale) {
		rect.w = rect.w * scale;
		rect.h = rect.h * scale;
	}

	dk::Rect Texture::getRect() const {
		return rect;
	}
}
