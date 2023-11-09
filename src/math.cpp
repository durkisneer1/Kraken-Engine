#include "../include/Math.hpp"


namespace DK_Math {
	Vector2::Vector2(float x, float y) : x(x), y(y) {}
	Vector2::Vector2(int x, int y) : x(static_cast<float>(x)), y(static_cast<float>(y)) {}

	void Vector2::ZERO() {
		x = 0.0f;
		y = 0.0f;
	}

	float Vector2::getLength() const {
		return sqrtf(x * x + y * y);
	}

	void Vector2::normalize() {
		float c = getLength();
		x /= c;
		y /= c;
	}

	Vector2 Vector2::operator*(float scalar) const {
		return {x * scalar, y * scalar};
	}

	Vector2 Vector2::operator/(float scalar) const {
		return {x / scalar, y / scalar};
	}

	Vector2 Vector2::operator+(const Vector2 &other) const {
		return {x + other.x, y + other.y};
	}

	Vector2 Vector2::operator+=(const Vector2 &other) {
		x += other.x;
		y += other.y;
		return *this;
	}
}