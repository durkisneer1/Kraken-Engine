#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include "Texture.hpp"
#include "Surface.hpp"
#include "RenderWindow.hpp"


namespace dk {
	class Font {
	public:
		Font(dk::RenderWindow& window, const char* fileDir, int ptSize);
		dk::Texture render(const char* text, bool antialias, SDL_Color color, int wrapLength = 0);
		~Font() { if (font) TTF_CloseFont(font); }

	private:
		dk::RenderWindow& window;
		TTF_Font* font;
	};
}
