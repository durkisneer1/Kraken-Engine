#pragma once

#include <SDL.h>
#include "Math.hpp"
#include "Rect.hpp"


namespace dk {
	class Texture {
	public:
		Texture(SDL_Texture* texture);
		~Texture() { if (texture) SDL_DestroyTexture(texture); }

		dk::math::Vector2 getSize() const { return { rect.w, rect.h }; }
		dk::Rect getRect() const { return rect; }
		SDL_Texture* toSDLTexture() const { return texture; }

		void setSize(dk::math::Vector2 size);
		void scaleBy(float scale);
		void fitWidth(float width);
		void fitHeight(float height);
		
	private:
		SDL_Texture* texture = nullptr;
		dk::Rect rect = {};

		void query();
	};
}
