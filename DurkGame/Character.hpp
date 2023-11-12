#pragma once

#include "Rect.hpp"
#include "Texture.hpp"
#include "Math.hpp"
#include "Globals.hpp"
#include "RenderWindow.hpp"


namespace dk {
	class Character {
	public:
		Character(dk::RenderWindow& window, dk::Texture& texture);
		~Character() = default;

		[[nodiscard]] dk::math::Vector2 getPosition() const;
		[[nodiscard]] dk::Rect getRect() const;

	protected:
		dk::RenderWindow& window;
		dk::Texture& texture;
		dk::Rect rect;

		dk::math::Vector2 velocity;
		dk::math::Vector2 position;

		void move();
		void draw();
	};
}
