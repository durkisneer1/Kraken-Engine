#include "../include/Math.hpp"
#include <cmath>
#include <algorithm>


namespace dk {
	namespace math {
		Vector2::Vector2(float x, float y) : x(x), y(y) {}
		Vector2::Vector2(int x, int y) : x(static_cast<float>(x)), y(static_cast<float>(y)) {}
		Vector2::Vector2(float x, int y) : x(x), y(static_cast<float>(y)) {}
		Vector2::Vector2(int x, float y) : x(static_cast<float>(x)), y(y) {}

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

		float Vector2::distanceTo(const Vector2& other) const {
			return sqrtf(powf(other.x - x, 2) + powf(other.y - y, 2));
		}

		Vector2 Vector2::operator*(float scalar) const {
			return { x * scalar, y * scalar };
		}

		Vector2 Vector2::operator/(float scalar) const {
			return { x / scalar, y / scalar };
		}

		Vector2 Vector2::operator+(const Vector2& other) const {
			return { x + other.x, y + other.y };
		}

		Vector2 Vector2::operator-(const Vector2& other) const {
			return { x - other.x, y - other.y };
		}

		Vector2 Vector2::operator+=(const Vector2& other) {
			x += other.x;
			y += other.y;
			return *this;
		}

		Vector2 clampVec(Vector2 vec, Vector2 min, Vector2 max) {
			vec.x = clamp(vec.x, min.x, max.x);
			vec.y = clamp(vec.y, min.y, max.y);
			return vec;
		}

		template <class digit>
		digit clamp(digit val, digit min, digit max) {
			if (min > max) return val;
			return std::min(max, std::max(min, val));
		}
	}
}
