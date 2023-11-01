#include "../include/Texture.hpp"


DK_Texture::DK_Texture(SDL_Renderer *renderer, const char *fileDir) {
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
	this->rect = { 0, 0, w, h };
}

void DK_Texture::blit() {
	SDL_RenderCopy(renderer, texture, nullptr, &rect);
}

DK_Math::Vector2i DK_Texture::getSize() const {
	return {rect.w, rect.h};
}

void DK_Texture::setSize(int w, int h) {
	rect.w = w;
	rect.h = h;
}

void DK_Texture::scaleBy(float scale) {
	rect.w = int(float(rect.w) * scale);
	rect.h = int(float(rect.h) * scale);
}

DK_Rect DK_Texture::getRect() const {
	return rect;
}
