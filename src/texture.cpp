#include "../include/Texture.hpp"


DK_Texture::DK_Texture(SDL_Renderer* renderer, const char *fileDir) {
	loadTextureFile(renderer, fileDir);
}

DK_Texture::DK_Texture(SDL_Renderer* renderer, SDL_Surface *surface) {
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (!texture) {
		std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
		exit(3);
	}

	int w, h;
	SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);
	this->rect = { 0, 0, w, h };
}

void DK_Texture::loadTextureFile(SDL_Renderer* renderer, const char *fileDir) {
    texture = IMG_LoadTexture(renderer, fileDir);
    if (!texture) {
        std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        exit(3);
    }

    int w, h;
    SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);
    this->rect = { 0, 0, w, h };
}

void DK_Texture::blit(SDL_Renderer* renderer, DK_Rect dstRect) {
	SDL_RenderCopyF(renderer, texture, nullptr, &dstRect);
}

void DK_Texture::blitAngle(SDL_Renderer* renderer, DK_Rect dstRect, float angleDeg) {
	SDL_RenderCopyExF(renderer, texture, nullptr, &dstRect, angleDeg, nullptr, SDL_FLIP_NONE);
}

DK_Math::Vector2 DK_Texture::getSize() const {
	return {rect.w, rect.h};
}

void DK_Texture::setSize(int w, int h) {
	rect.w = (float)w;
	rect.h = (float)h;
}

void DK_Texture::scaleBy(float scale) {
	rect.w = rect.w * scale;
	rect.h = rect.h * scale;
}

DK_Rect DK_Texture::getRect() const {
	return rect;
}
