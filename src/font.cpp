#include "../include/Font.hpp"


DK_Font::DK_Font(SDL_Renderer* renderer, const char* fileDir, int ptSize)
: renderer(renderer) {
	font = TTF_OpenFont(fileDir, ptSize);
	if (!font) {
		std::cout << "Failed to load font: " << TTF_GetError() << std::endl;
		exit(3);
	}
}

DK_Texture* DK_Font::render(const char* text, SDL_Color color, int wrapLength) {
	SDL_Surface* surface;

	if (wrapLength > 0) {
		surface = TTF_RenderText_Solid_Wrapped(font, text, color, wrapLength);
	}
	surface = TTF_RenderText_Solid(font, text, color);

	if (!surface) {
		std::cout << "Failed to render text: " << TTF_GetError() << std::endl;
		exit(3);
	}

	return new DK_Texture(renderer, surface);
}
