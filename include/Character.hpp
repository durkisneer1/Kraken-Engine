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

		dk::math::Vector2 getPosition() const;
		dk::Rect getRect() const;

		static const std::vector<Character*>& getCharacters();

		virtual void process(double deltaTime) = 0;

	protected:
		dk::RenderWindow& window;
		dk::Texture& texture;
		dk::Rect rect;

		dk::math::Vector2 velocity;
		dk::math::Vector2 position;

		static std::vector<Character*> characters;

		void moveAndSlide();
		void move();
		void draw();
	};
}
