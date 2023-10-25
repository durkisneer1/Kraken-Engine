#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Math.hpp"


class DK_Texture {
public:
	DK_Texture(SDL_Renderer* renderer, const char* fileDir, float scale = 1.0f);
	~DK_Texture() = default;
	void blit() const;
	[[nodiscard]] DK_Math::Vector2 getSize() const;
	[[nodiscard]] SDL_Rect getRect() const;
private:
	SDL_Renderer* renderer;
	SDL_Texture* texture;
	SDL_Rect rect = {};
};
