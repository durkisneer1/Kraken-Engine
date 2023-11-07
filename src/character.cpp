#include "../include/Character.hpp"


DK_Character::DK_Character(SDL_Renderer* renderer, DK_Texture* texture) {
	this->renderer = renderer;
	this->texture = texture;
	rect = texture->getRect();
}

DK_Math::Vector2 DK_Character::getPosition() const {
	return position;
}

DK_Rect DK_Character::getRect() const {
	return rect;
}

void DK_Character::move() {
	position += velocity;
	rect.setCenter(position);
}

void DK_Character::draw() {
	if (!texture) return;
	texture->blit(renderer, rect);
}
