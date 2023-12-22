#include "../include/Math.hpp"
#include <cmath>
#include <algorithm>


namespace kn {
	namespace math {
		Vec2::Vec2(float x, float y) : x(x), y(y) {}
		Vec2::Vec2(int x, int y) : x(static_cast<float>(x)), y(static_cast<float>(y)) {}
		Vec2::Vec2(float x, int y) : x(x), y(static_cast<float>(y)) {}
		Vec2::Vec2(int x, float y) : x(static_cast<float>(x)), y(y) {}

		Vec2 Vec2::ZERO() {
			return { 0.0f, 0.0f };
		}

		float Vec2::getLength() const {
			return sqrtf(x * x + y * y);
		}

		void Vec2::normalize() {
			float c = getLength();
			x /= c;
			y /= c;
		}

		float Vec2::distanceTo(const Vec2& other) const {
			return sqrtf(powf(other.x - x, 2) + powf(other.y - y, 2));
		}

		Vec2 Vec2::operator*(float scalar) const {
			return { x * scalar, y * scalar };
		}

		Vec2 Vec2::operator/(float scalar) const {
			return { x / scalar, y / scalar };
		}

		Vec2 Vec2::operator+(const Vec2& other) const {
			return { x + other.x, y + other.y };
		}

		Vec2 Vec2::operator-(const Vec2& other) const {
			return { x - other.x, y - other.y };
		}

		Vec2 Vec2::operator+=(const Vec2& other) {
			x += other.x;
			y += other.y;
			return *this;
		}

		Vec2 clampVec(Vec2 vec, Vec2 min, Vec2 max) {
			vec.x = clamp(vec.x, min.x, max.x);
			vec.y = clamp(vec.y, min.y, max.y);
			return vec;
		}

		Vec2 lerpVec(Vec2 a, Vec2 b, float t) {
			return a + (b - a) * t;
		}

		template <class digit>
		digit clamp(digit val, digit min, digit max) {
			if (min > max) return val;
			return std::min(max, std::max(min, val));
		}
	}
}
