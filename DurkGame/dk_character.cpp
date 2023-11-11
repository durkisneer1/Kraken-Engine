#include "pch.h"
#include "DK_Character.h"


namespace dk {
	Character::Character(SDL_Renderer* renderer, dk::Texture* texture) {
		this->renderer = renderer;
		this->texture = texture;
		rect = texture->getRect();
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
		if (!texture) return;
		texture->blit(renderer, rect);
	}
}
