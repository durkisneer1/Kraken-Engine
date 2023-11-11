#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include "DK_Texture.h"
#include "DK_Surface.h"


class DK_Font {
public:
	DK_Font(SDL_Renderer* renderer, const char* fileDir, int ptSize);
	DK_Texture* render(const char* text, SDL_Color color, int wrapLength = 0);
	~DK_Font() { if (font) TTF_CloseFont(font); }

private:
	SDL_Renderer* renderer;
	TTF_Font* font;
};
