#pragma once

#include <SDL.h>
#include "DK_Rect.h"
#include "DK_Texture.h"
#include "DK_Math.h"
#include "DK_Globals.h"


class DK_Character {
public:
	DK_Character(SDL_Renderer* renderer, DK_Texture* texture);
	~DK_Character() = default;

	[[nodiscard]] DK_Math::Vector2 getPosition() const;
	[[nodiscard]] DK_Rect getRect() const;

protected:
	SDL_Renderer* renderer;
	DK_Texture* texture;
	DK_Rect rect = {};

	DK_Math::Vector2 velocity;
	DK_Math::Vector2 position;

	void move();
	void draw();
};
