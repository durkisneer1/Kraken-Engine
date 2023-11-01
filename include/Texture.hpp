#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Math.hpp"
#include "Rect.hpp"


class DK_Texture {
public:
	DK_Texture(SDL_Renderer* renderer, const char* fileDir);
	~DK_Texture() { SDL_DestroyTexture(texture); }
	void blit();

	[[nodiscard]] DK_Math::Vector2i getSize() const;
	[[nodiscard]] DK_Rect getRect() const;

	void setSize(int w, int h);
	void scaleBy(float scale);
private:
	SDL_Renderer* renderer;
	SDL_Texture* texture;
	DK_Rect rect = {};
};
