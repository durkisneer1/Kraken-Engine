#include "pch.h"
#include "Rect.hpp"


namespace dk {
	dk::math::Vector2 Rect::getPos() {
		return { x, y };
	}

	dk::math::Vector2 Rect::getSize() {
		return { w, h };
	}

	bool Rect::collidePoint(dk::math::Vector2 pos) {
		return (pos.x >= x && pos.x <= x + w && pos.y >= y && pos.y <= y + h);
	}

	void Rect::clamp(dk::math::Vector2 min, dk::math::Vector2 max) {
		if ((max.x - min.x < this->w) || max.y - min.y < this->h) {
			return;
		}
		setTopLeft(clampVec(getTopLeft(), min, max));
		setBottomRight(clampVec(getBottomRight(), min, max));
	}

	void Rect::setCenter(dk::math::Vector2 pos) {
		x = pos.x - w / 2;
		y = pos.y - h / 2;
	}

	void Rect::setTopLeft(dk::math::Vector2 pos) {
		x = pos.x;
		y = pos.y;
	}

	void Rect::setTopMid(dk::math::Vector2 pos) {
		x = pos.x - w / 2;
		y = pos.y;
	}

	void Rect::setTopRight(dk::math::Vector2 pos) {
		x = pos.x - w;
		y = pos.y;
	}

	void Rect::setBottomLeft(dk::math::Vector2 pos) {
		x = pos.x;
		y = pos.y - h;
	}

	void Rect::setBottomMid(dk::math::Vector2 pos) {
		x = pos.x - w / 2;
		y = pos.y - h;
	}

	void Rect::setBottomRight(dk::math::Vector2 pos) {
		x = pos.x - w;
		y = pos.y - h;
	}

	void Rect::setLeftMid(dk::math::Vector2 pos) {
		x = pos.x;
		y = pos.y - h / 2;
	}

	void Rect::setRightMid(dk::math::Vector2 pos) {
		x = pos.x - w;
		y = pos.y - h / 2;
	}

	dk::math::Vector2 Rect::getCenter() {
		return { x + w / 2, y + h / 2 };
	}

	dk::math::Vector2 Rect::getTopLeft() {
		return { x, y };
	}

	dk::math::Vector2 Rect::getTopMid() {
		return { x + w / 2, y };
	}

	dk::math::Vector2 Rect::getTopRight() {
		return { x + w, y };
	}

	dk::math::Vector2 Rect::getBottomLeft() {
		return { x, y + h };
	}

	dk::math::Vector2 Rect::getBottomMid() {
		return { x + w / 2, y + h };
	}

	dk::math::Vector2 Rect::getBottomRight() {
		return { x + w, y + h };
	}

	dk::math::Vector2 Rect::getLeftMid() {
		return { x, y + h / 2 };
	}

	dk::math::Vector2 Rect::getRightMid() {
		return { x + w, y + h / 2 };
	}
}
