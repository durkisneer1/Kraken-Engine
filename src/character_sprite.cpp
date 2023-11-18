#include "../include/CharacterSprite.hpp"


namespace dk {
	CharacterSprite::CharacterSprite(dk::RenderWindow& window, dk::Texture& texture)
	: SpriteNode(window, texture) {
		rect = texture.getRect();
		characterSprites.push_back(this);
	}

	void CharacterSprite::moveAndSlide() {
		move();

		for (auto& target : characterSprites) {
			if (target == this) continue;
			float distance = position.distanceTo(target->getPosition());
			float radiusSum = rect.getSize().x / 2 + target->getRect().getSize().x / 2;
			if (distance < radiusSum) {
				float overlap = radiusSum - distance;
				position += (position - target->getPosition()) * (overlap / distance);
			}
		}
	}

	void CharacterSprite::move() {
		// velocity.y += GRAVITY; // FIXME: Implement gravity
		position += velocity;
		rect.setCenter(position);
	}
}
