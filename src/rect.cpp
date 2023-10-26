#include "../include/Rect.hpp"


DK_Math::Vector2i DK_Rect::getPos() {
	return {x, y};
}

DK_Math::Vector2f DK_Rect::getPosF() {
	return {float(x), float(y)};
}

void DK_Rect::setCenter(DK_Math::Vector2i pos) {
	x = pos.x - w / 2;
	y = pos.y - h / 2;
}

void DK_Rect::setCenterF(DK_Math::Vector2f pos) {
	x = int(pos.x - float(w) / 2);
	y = int(pos.y - float(h) / 2);
}
