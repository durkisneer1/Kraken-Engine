#include "../include/SpriteCharacter.hpp"
#include <memory>


namespace dk {
	CharacterSprite::CharacterSprite(dk::RenderWindow& window, dk::Texture& texture)
	: SpriteNode(window, texture) {
		addCharacterSprite(std::make_unique<CharacterSprite>(this));
	}

	void CharacterSprite::move() {
		position += velocity;
		rect.setCenter(position);
	}

	void CharacterSprite::movePhysicsRect(double deltaTime) {
		velocity.y += GRAVITY * deltaTime;

		position.x += velocity.x;
		rect.setCenter({ position.x, rect.getCenter().y });
		rectHorizontalCollision();

		position.y += velocity.y;
		rect.setCenter({ rect.getCenter().x, position.y });
		rectVerticalCollision();
	}

	void CharacterSprite::rectHorizontalCollision() {
		for (auto& sprite : staticSprites) {
			if (rect.collideRect(sprite->getRect())) {
				if (velocity.x > 0) {
					rect.setRight(sprite->getRect().getLeft());
					velocity.x = 0;
				}
				else if (velocity.x < 0) {
					rect.setLeft(sprite->getRect().getRight());
					velocity.x = 0;
				}
				position.x = rect.getCenter().x;
			}
		}
	}

	void CharacterSprite::rectVerticalCollision() {
		for (auto& sprite : staticSprites) {
			if (rect.collideRect(sprite->getRect())) {
				if (velocity.y > 0) {
					rect.setBottom(sprite->getRect().getTop());
					velocity.y = 0;
					onFloor = true;
				}
				else if (velocity.y < 0) {
					rect.setTop(sprite->getRect().getBottom());
					velocity.y = 0;
					onCeiling = true;
				}
				position.y = rect.getCenter().y;
			}
		}
	}
}
