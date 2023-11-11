#include "pch.h"
#include "DK_Font.h"


namespace dk {
	Font::Font(SDL_Renderer* renderer, const char* fileDir, int ptSize)
		: renderer(renderer) {
		font = TTF_OpenFont(fileDir, ptSize);
		if (!font) {
			std::cout << "Failed to load font: " << TTF_GetError() << std::endl;
			exit(3);
		}
	}

	dk::Texture* Font::render(const char* text, SDL_Color color, int wrapLength) {
		auto* surface = new dk::Surface;

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

		return new dk::Texture(renderer, surface);
	}
}
