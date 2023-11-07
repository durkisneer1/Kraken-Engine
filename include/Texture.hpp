#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Math.hpp"
#include "Rect.hpp"


class DK_Texture {
public:
    DK_Texture() = default;
	DK_Texture(SDL_Renderer* renderer, const char* fileDir);
	DK_Texture(SDL_Renderer* renderer, SDL_Surface* surface);
	~DK_Texture() { if (texture) SDL_DestroyTexture(texture); }

	[[nodiscard]] DK_Math::Vector2 getSize() const;
	[[nodiscard]] DK_Rect getRect() const;

    void loadTextureFile(SDL_Renderer* renderer, const char* fileDir);
	void setSize(int w, int h);
	void scaleBy(float scale);
    void blit(SDL_Renderer* renderer, DK_Rect rect);
	void blitAngle(SDL_Renderer* renderer, DK_Rect rect, float angle);
private:
	SDL_Texture* texture = nullptr;
	DK_Rect rect = {};
};
