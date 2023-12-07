#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <vector>
#include <memory>
#include "Texture.hpp"
#include "Math.hpp"
#include "Constants.hpp"


namespace kn {
	class RenderWindow {
	public:
		RenderWindow(kn::math::Vector2 size, const char* title);
		~RenderWindow();

		void fill(SDL_Color color);
		void flip();
		void blit(const std::shared_ptr<kn::Texture> texture, kn::Rect rect);
		void blit(const std::shared_ptr<kn::Texture> texture, kn::math::Vector2 position);
		void blitEx(const std::shared_ptr<kn::Texture>, kn::Rect rect, double angle = 0.0, bool flipX = false, bool flipY = false);
		void blitEx(const std::shared_ptr<kn::Texture>, kn::math::Vector2 position, double angle = 0.0, bool flipX = false, bool flipY = false);

		SDL_Renderer* getRenderer() { return renderer; }
		const std::vector<KN_Event>& getEvents();
		
	private:
		SDL_Renderer* renderer = nullptr;
		SDL_Window* window = nullptr;

		KN_Event event;
		std::vector<SDL_Event> events;

		void init();
	};
}
