#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <vector>
#include "Texture.hpp"
#include "Math.hpp"


namespace kn {
	class RenderWindow {
	public:
		RenderWindow(kn::math::Vector2 size, const char* title);
		~RenderWindow();

		void fill(SDL_Color color);
		void flip();
		void blit(kn::Texture& texture, kn::Rect rect);
		void blit(kn::Texture& texture, kn::math::Vector2 position);
		void blitEx(kn::Texture& texture, kn::Rect rect, double angle = 0.0, bool flipX = false, bool flipY = false);
		void blitEx(kn::Texture& texture, kn::math::Vector2 position, double angle = 0.0, bool flipX = false, bool flipY = false);

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
