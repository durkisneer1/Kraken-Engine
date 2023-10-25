#include "../include/Texture.hpp"


DK_Texture::DK_Texture(SDL_Renderer *renderer, const char *fileDir, float scale) {
	this->renderer = renderer;
	SDL_Surface* surface = IMG_Load(fileDir);
	if (!surface) {
		std::cout << "IMG_Load Error: " << IMG_GetError() << std::endl;
		exit(3);
	}
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (!texture) {
		std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
		exit(3);
	}
	SDL_FreeSurface(surface);

	int w, h;
	SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);
	int scaleW = int(float(w) * scale);
	int scaleH = int(float(h) * scale);
	this->rect = { 0, 0, scaleW, scaleH };
}

void DK_Texture::blit() const {
	SDL_RenderCopy(renderer, texture, nullptr, &rect);
}

DK_Math::Vector2 DK_Texture::getSize() const {
	return {rect.w, rect.h};
}

SDL_Rect DK_Texture::getRect() const {
	return rect;
}