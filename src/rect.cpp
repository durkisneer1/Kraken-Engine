#include "../include/Rect.hpp"


DK_Math::Vector2 DK_Rect::getPos() {
	return {x, y};
}

void DK_Rect::setCenter(DK_Math::Vector2 pos) {
	x = int(pos.x) - w / 2;
	y = int(pos.y) - h / 2;
}
