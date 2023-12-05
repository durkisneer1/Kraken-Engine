#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <vector>
#include "Texture.hpp"
#include "Math.hpp"


namespace dk {
	class RenderWindow {
	public:
		RenderWindow(dk::math::Vector2 size, const char* title);
		~RenderWindow();

		void fill(SDL_Color color);
		void flip();
		void blit(dk::Texture& texture, dk::Rect rect);
		void blit(dk::Texture& texture, dk::math::Vector2 position);
		void blitEx(dk::Texture& texture, dk::Rect rect, double angle = 0.0, bool flipX = false, bool flipY = false);
		void blitEx(dk::Texture& texture, dk::math::Vector2 position, double angle = 0.0, bool flipX = false, bool flipY = false);

		SDL_Renderer* getRenderer() { return renderer; }
		const std::vector<SDL_Event>& getEvents();
		
	private:
		SDL_Renderer* renderer = nullptr;
		SDL_Window* window = nullptr;

		SDL_Event event;
		std::vector<SDL_Event> events;

		void init();
	};
}