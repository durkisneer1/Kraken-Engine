#pragma once
#include <cmath>


namespace DK_Math {
	struct Vector2 {
		float x = 0.0f;
		float y = 0.0f;

		Vector2() = default;
		Vector2(float x, float y) : x(x), y(y) {}
		Vector2(int x, int y) : x((float)x), y((float)y) {}

		void ZERO() {
			x = 0.0f;
			y = 0.0f;
		}

		[[nodiscard]] float length() const {
			return sqrtf(x * x + y * y);
		}

		void normalize() {
			float length = sqrtf(x * x + y * y);
			x /= length;
			y /= length;
		}

		Vector2 operator*(float scalar) const {
			return {x * scalar, y * scalar};
		}

		Vector2 operator/(float scalar) const {
			return {x / scalar, y / scalar};
		}

		Vector2 operator+(const Vector2& other) const {
			return {x + other.x, y + other.y};
		}

		Vector2 operator+=(const Vector2& other) {
			x += other.x;
			y += other.y;
			return *this;
		}
	};
}