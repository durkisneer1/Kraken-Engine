#include "pch.h"
#include "DK_Font.h"


DK_Font::DK_Font(SDL_Renderer* renderer, const char* fileDir, int ptSize)
	: renderer(renderer) {
	font = TTF_OpenFont(fileDir, ptSize);
	if (!font) {
		std::cout << "Failed to load font: " << TTF_GetError() << std::endl;
		exit(3);
	}
}

DK_Texture* DK_Font::render(const char* text, SDL_Color color, int wrapLength) {
	auto* surface = new DK_Surface;

	if (wrapLength > 0) {
		surface->set(TTF_RenderText_Solid_Wrapped(font, text, color, wrapLength));
	}
	else {
		surface->set(TTF_RenderText_Solid(font, text, color));
	}
	
	if (!surface->get()) {
		std::cout << "Failed to render text: " << TTF_GetError() << std::endl;
		exit(3);
	}

	return new DK_Texture(renderer, surface);
}
