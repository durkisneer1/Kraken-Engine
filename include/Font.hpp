#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include "Texture.hpp"
#include "RenderWindow.hpp"


namespace kn {
	class Font {
	public:
		Font(kn::RenderWindow& window, const char* fileDir, int ptSize);
		kn::Texture render(const char* text, bool antialias, SDL_Color color, int wrapLength = 0);
		~Font() { if (font) TTF_CloseFont(font); }

	private:
		kn::RenderWindow& window;
		TTF_Font* font;
	};
}
