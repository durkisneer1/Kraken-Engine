#include "../include/Rect.hpp"


DK_Math::Vector2 DK_Rect::getPos() {
	return {x, y};
}

DK_Math::Vector2 DK_Rect::getSize() {
	return {w, h};
}

bool DK_Rect::collidePoint(DK_Math::Vector2 pos) {
	return (pos.x >= x && pos.x <= x + w && pos.y >= y && pos.y <= y + h);
}

void DK_Rect::setCenter(DK_Math::Vector2 pos) {
	x = pos.x - w / 2;
	y = pos.y - h / 2;
}

void DK_Rect::setTopLeft(DK_Math::Vector2 pos) {
	x = pos.x;
	y = pos.y;
}

void DK_Rect::setTopMid(DK_Math::Vector2 pos) {
	x = pos.x - w / 2;
	y = pos.y;
}

void DK_Rect::setTopRight(DK_Math::Vector2 pos) {
	x = pos.x - w;
	y = pos.y;
}

void DK_Rect::setBottomLeft(DK_Math::Vector2 pos) {
	x = pos.x;
	y = pos.y - h;
}

void DK_Rect::setBottomMid(DK_Math::Vector2 pos) {
	x = pos.x - w / 2;
	y = pos.y - h;
}

void DK_Rect::setBottomRight(DK_Math::Vector2 pos) {
	x = pos.x - w;
	y = pos.y - h;
}

void DK_Rect::setLeftMid(DK_Math::Vector2 pos) {
	x = pos.x;
	y = pos.y - h / 2;
}

void DK_Rect::setRightMid(DK_Math::Vector2 pos) {
	x = pos.x - w;
	y = pos.y - h / 2;
}

DK_Math::Vector2 DK_Rect::getCenter() {
	return {x + w / 2, y + h / 2};
}

DK_Math::Vector2 DK_Rect::getTopLeft() {
	return {x, y};
}

DK_Math::Vector2 DK_Rect::getTopMid() {
	return {x + w / 2, y};
}

DK_Math::Vector2 DK_Rect::getTopRight() {
	return {x + w, y};
}

DK_Math::Vector2 DK_Rect::getBottomLeft() {
	return {x, y + h};
}

DK_Math::Vector2 DK_Rect::getBottomMid() {
	return {x + w / 2, y + h};
}

DK_Math::Vector2 DK_Rect::getBottomRight() {
	return {x + w, y + h};
}

DK_Math::Vector2 DK_Rect::getLeftMid() {
	return {x, y + h / 2};
}

DK_Math::Vector2 DK_Rect::getRightMid() {
	return {x + w, y + h / 2};
}
