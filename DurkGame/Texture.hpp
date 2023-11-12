#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Math.hpp"
#include "Rect.hpp"
#include "Surface.hpp"
#include "RenderWindow.hpp"


namespace dk {
	class Texture {
	public:
		Texture() = default;
		Texture(dk::RenderWindow& window, const char* fileDir);
		Texture(dk::RenderWindow& window, dk::Surface& surface);
		~Texture() { if (texture) SDL_DestroyTexture(texture); }

		[[nodiscard]] dk::math::Vector2 getSize() const;
		[[nodiscard]] dk::Rect getRect() const;

		void loadTextureFile(const char* fileDir);
		void setSize(int w, int h);
		void scaleBy(float scale);
		void blit(dk::Rect rect);
		void blitAngle(dk::Rect rect, float angle);
	private:
		dk::RenderWindow& window;
		SDL_Texture* texture = nullptr;
		dk::Rect rect = {};
	};
}
