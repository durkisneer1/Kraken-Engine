#include "pch.h"
#include "Character.hpp"


namespace dk {
	Character::Character(dk::RenderWindow& window, dk::Texture& texture)
	: window(window), texture(texture) {
		rect = texture.getRect();
	}

	dk::math::Vector2 Character::getPosition() const {
		return position;
	}

	dk::Rect Character::getRect() const {
		return rect;
	}

	void Character::move() {
		// velocity.y += GRAVITY; // FIXME: Implement gravity
		position += velocity;
		rect.setCenter(position);
	}

	void Character::draw() {
		texture.blit(rect);
	}
}
