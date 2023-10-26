#pragma once
#include <cmath>


namespace DK_Math {
	struct Vector2i {
		int x = 0;
		int y = 0;

		Vector2i() = default;
		Vector2i(float x, float y) : x((int)x), y((int)y) {}
		Vector2i(int x, int y) : x(x), y(y) {}

		void ZERO() {
			x = 0;
			y = 0;
		}

		[[nodiscard]] float length() const {
			return sqrtf(float(x * x + y * y));
		}

		void normalize() {
			float length = sqrtf(float(x * x + y * y));
			x = int((float)x / length);
			y = int((float)y / length);
		}

		Vector2i operator*(float scalar) const {
			return {int((float)x * scalar), int((float)y * scalar)};
		}

		Vector2i operator*(int scalar) const {
			return {x * scalar, y * scalar};
		}
	};

	struct Vector2f {
		float x = 0.0f;
		float y = 0.0f;

		Vector2f() = default;
		Vector2f(float x, float y) : x(x), y(y) {}
		Vector2f(int x, int y) : x((float)x), y((float)y) {}

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

		Vector2f operator*(float scalar) const {
			return {x * scalar, y * scalar};
		}

		Vector2f operator*(int scalar) const {
			return {x * (float)scalar, y * (float)scalar};
		}

		Vector2f operator/(float scalar) const {
			return {x / scalar, y / scalar};
		}

		Vector2f operator/(int scalar) const {
			return {x / (float)scalar, y / (float)scalar};
		}

		Vector2f operator+(const Vector2f& other) const {
			return {x + other.x, y + other.y};
		}

		Vector2f operator+(const Vector2i& other) const {
			return {x + (float)other.x, y + (float)other.y};
		}

		Vector2f operator+=(const Vector2f& other) {
			x += other.x;
			y += other.y;
			return *this;
		}

		Vector2f operator+=(const Vector2i& other) {
			x += (float)other.x;
			y += (float)other.y;
			return *this;
		}
	};
}