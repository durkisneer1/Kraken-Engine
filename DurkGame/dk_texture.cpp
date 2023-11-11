#include "pch.h"
#include "DK_Texture.h"


namespace dk {
	Texture::Texture(SDL_Renderer* renderer, const char* fileDir) {
		loadTextureFile(renderer, fileDir);
	}

	Texture::Texture(SDL_Renderer* renderer, dk::Surface* surface) {
		texture = SDL_CreateTextureFromSurface(renderer, surface->get());
		if (!texture) {
			std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
			exit(3);
		}

		int w, h;
		SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);
		this->rect = { 0, 0, w, h };
	}

	void Texture::loadTextureFile(SDL_Renderer* renderer, const char* fileDir) {
		texture = IMG_LoadTexture(renderer, fileDir);
		if (!texture) {
			std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
			exit(3);
		}

		int w, h;
		SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);
		this->rect = { 0, 0, w, h };
	}

	void Texture::blit(SDL_Renderer* renderer, dk::Rect dstRect) {
		SDL_RenderCopyF(renderer, texture, nullptr, &dstRect);
	}

	void Texture::blitAngle(SDL_Renderer* renderer, dk::Rect dstRect, float angleDeg) {
		SDL_RenderCopyExF(renderer, texture, nullptr, &dstRect, angleDeg, nullptr, SDL_FLIP_NONE);
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
