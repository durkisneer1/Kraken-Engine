#include "../include/Character.hpp"


namespace dk {
	std::vector<Character*> Character::characters;

	Character::Character(dk::RenderWindow& window, dk::Texture& texture)
	: window(window), texture(texture) {
		rect = texture.getRect();
		characters.push_back(this);
	}

	dk::math::Vector2 Character::getPosition() const {
		return position;
	}

	dk::Rect Character::getRect() const {
		return rect;
	}

	const std::vector<Character*>& Character::getCharacters() {
		return characters;
	}

	void Character::moveAndSlide() {
		move();

		for (auto& target : characters) {
			if (target == this) continue;
			float distance = position.distanceTo(target->getPosition());
			float radiusSum = rect.getSize().x / 2 + target->getRect().getSize().x / 2;
			if (distance < radiusSum) {
				float overlap = radiusSum - distance;
				position += (position - target->getPosition()) * (overlap / distance);
			}
		}
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
