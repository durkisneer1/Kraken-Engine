#include "../include/Texture.hpp"
#include <iostream>


namespace dk {
	Texture::Texture(SDL_Texture* texture)
	: texture(texture) {
		query();
	}

	void Texture::query() {
		int w, h;
		SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);
		this->rect = { 0, 0, w, h };
	}

	void Texture::setSize(dk::math::Vector2 size) {
		rect.w = size.x;
		rect.h = size.y;
	}

	void Texture::scaleBy(float scale) {
		rect.w = rect.w * scale;
		rect.h = rect.h * scale;
	}
}
