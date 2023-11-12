#pragma once

#include <SDL.h>
#include "Math.hpp"
#include "Rect.hpp"


namespace dk {
	class Surface {
	public:
		Surface(dk::math::Vector2 size = { 0, 0 });
		~Surface() { if (surface) SDL_FreeSurface(surface); }

		void fill(SDL_Color color);
		dk::math::Vector2 getSize();
		dk::Rect getRect();
		void free() { SDL_FreeSurface(surface); }

		SDL_Surface* get() { return surface; }
		void set(SDL_Surface* setSurface);

	private:
		SDL_Surface* surface = nullptr;
		dk::Rect rect = {};
	};
}
