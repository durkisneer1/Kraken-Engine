#pragma once

#include <SDL.h>
#include "Math.hpp"
#include "Rect.hpp"


namespace kn {
	class Texture {
	public:
		Texture(SDL_Texture* texture);
		~Texture() { if (texture) SDL_DestroyTexture(texture); }

		kn::math::Vector2 getSize() const { return { rect.w, rect.h }; }
		kn::Rect getRect() const { return rect; }
		SDL_Texture* getSDLTexture() const { return texture; }

		void setSize(kn::math::Vector2 size);
		void scaleBy(float scale);
		void fitWidth(float width);
		void fitHeight(float height);
		
	private:
		SDL_Texture* texture = nullptr;
		kn::Rect rect = {};

		void query();
	};
}
