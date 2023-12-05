#include "../include/Font.hpp"
#include <iostream>


namespace kn {
	Font::Font(kn::RenderWindow& window, const char* fileDir, int ptSize)
	: window(window) {
		font = TTF_OpenFont(fileDir, ptSize);
		if (!font) {
			std::cout << "Failed to load font: " << TTF_GetError() << std::endl;
			exit(3);
		} else {}
	}

	kn::Texture Font::render(const char* text, bool antialias, SDL_Color color, int wrapLength) {
		SDL_Surface* surface;

		if (antialias) {
			if (wrapLength > 0) {
				surface = TTF_RenderUTF8_Blended_Wrapped(font, text, color, wrapLength);
			} else {
				surface = TTF_RenderUTF8_Blended(font, text, color);
			}
		}
		else {
			if (wrapLength > 0) {
				surface = TTF_RenderText_Solid_Wrapped(font, text, color, wrapLength);
			} else {
				surface = TTF_RenderText_Solid(font, text, color);
			}
		}
	
		if (surface == nullptr) {
			std::cout << "Failed to render text: " << TTF_GetError() << std::endl;
			exit(3);
		} else {}

		SDL_Texture* sdlTexture = SDL_CreateTextureFromSurface(window.getRenderer(), surface);
		if (sdlTexture == nullptr) {
			std::cout << "Failed to create texture: " << SDL_GetError() << std::endl;
			exit(3);
		} else {}

		kn::Texture texture(sdlTexture);
		SDL_FreeSurface(surface);

		return texture;
	}
}
