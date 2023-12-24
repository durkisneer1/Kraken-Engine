#include "../include/Font.hpp"
#include <iostream>


namespace kn {

Font::Font(RenderWindow& window, const std::string &fileDir, int ptSize)
: window(window) {
	font = TTF_OpenFont(fileDir.c_str(), ptSize);
	if (!font) {
		std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
		exit(3);
	}
}

std::shared_ptr<Texture> Font::render(const std::string &text, bool antialias, SDL_Color color, int wrapLength) {
	SDL_Surface* surface;

	if (antialias) {
		if (wrapLength > 0) {
			surface = TTF_RenderUTF8_Blended_Wrapped(font, text.c_str(), color, wrapLength);
		} else {
			surface = TTF_RenderUTF8_Blended(font, text.c_str(), color);
		}
	}
	else {
		if (wrapLength > 0) {
			surface = TTF_RenderText_Solid_Wrapped(font, text.c_str(), color, wrapLength);
		} else {
			surface = TTF_RenderText_Solid(font, text.c_str(), color);
		}
	}

	if (surface == nullptr) {
		std::cerr << "Failed to render text: " << TTF_GetError() << std::endl;
		exit(3);
	}

	SDL_Texture* sdlTexture = SDL_CreateTextureFromSurface(window.getRenderer(), surface);
	if (sdlTexture == nullptr) {
		std::cerr << "Failed to create texture: " << SDL_GetError() << std::endl;
		exit(3);
	}

	std::shared_ptr<Texture> texture = std::make_shared<Texture>(sdlTexture);
	SDL_FreeSurface(surface);

	return texture;
}

}
