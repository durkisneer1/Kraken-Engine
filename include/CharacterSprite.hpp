#pragma once

#include "SpriteNode.hpp"
#include "Globals.hpp"


namespace dk {
	class CharacterSprite : public SpriteNode {
	public:
		CharacterSprite(dk::RenderWindow& window, dk::Texture& texture);
		~CharacterSprite() = default;

	protected:
		dk::math::Vector2 velocity;
		bool onFloor;
		bool onCeiling;
		
		void movePhysicsRect(double deltaTime);
		void move();

	private:
		void rectHorizontalCollision();
		void rectVerticalCollision();
	};
}
