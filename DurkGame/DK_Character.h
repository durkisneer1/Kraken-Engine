#pragma once

#include <SDL.h>
#include "DK_Rect.h"
#include "DK_Texture.h"
#include "DK_Math.h"
#include "DK_Globals.h"


namespace dk {
	class Character {
	public:
		Character(SDL_Renderer* renderer, dk::Texture* texture);
		~Character() = default;

		[[nodiscard]] dk::math::Vector2 getPosition() const;
		[[nodiscard]] dk::Rect getRect() const;
		void process();

	protected:
		SDL_Renderer* renderer;
		dk::Texture* texture;
		dk::Rect rect = {};

		dk::math::Vector2 velocity;
		dk::math::Vector2 position;

		void move();
		void draw();
	};
}
