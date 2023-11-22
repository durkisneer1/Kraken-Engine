#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "Math.hpp"
#include "Rect.hpp"
#include "RenderWindow.hpp"


namespace dk {
	class Texture {
	public:
		Texture() = default;
		Texture(dk::RenderWindow& window, const char* fileDir);
		Texture(dk::RenderWindow& window, dk::math::Vector2 size, SDL_Color color);
		Texture(dk::RenderWindow& window, SDL_Surface* surface);
		Texture(dk::RenderWindow& window, SDL_Texture* texture);
		~Texture() { if (texture) SDL_DestroyTexture(texture); }

		dk::math::Vector2 getSize() const;
		dk::Rect getRect() const;

		void loadTextureFile(const char* fileDir);
		void setSize(int w, int h);
		void scaleBy(float scale);
		void drawAt(dk::Rect rect);
		void drawAtAngle(dk::Rect rect, float angle);
	private:
		dk::RenderWindow& window;
		SDL_Texture* texture = nullptr;
		dk::Rect rect = {};

		void query();
	};
}
