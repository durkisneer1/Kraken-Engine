#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "DK_Math.h"
#include "DK_Rect.h"
#include "DK_Surface.h"


namespace dk {
	class Texture {
	public:
		Texture() = default;
		Texture(SDL_Renderer* renderer, const char* fileDir);
		Texture(SDL_Renderer* renderer, dk::Surface* surface);
		~Texture() { if (texture) SDL_DestroyTexture(texture); }

		[[nodiscard]] dk::math::Vector2 getSize() const;
		[[nodiscard]] dk::Rect getRect() const;

		void loadTextureFile(SDL_Renderer* renderer, const char* fileDir);
		void setSize(int w, int h);
		void scaleBy(float scale);
		void blit(SDL_Renderer* renderer, dk::Rect rect);
		void blitAngle(SDL_Renderer* renderer, dk::Rect rect, float angle);
	private:
		SDL_Texture* texture = nullptr;
		dk::Rect rect = {};
	};
}
