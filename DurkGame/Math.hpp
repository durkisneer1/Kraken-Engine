#pragma once

#include <cmath>
#include <algorithm>


namespace dk {
	namespace math {
		struct Vector2 {
			float x = 0.0f;
			float y = 0.0f;

			Vector2() = default;
			Vector2(float x, float y);
			Vector2(int x, int y);

			void ZERO();
			[[nodiscard]] float getLength() const;
			void normalize();

			Vector2 operator*(float scalar) const;
			Vector2 operator/(float scalar) const;
			Vector2 operator+(const Vector2& other) const;
			Vector2 operator-(const Vector2& other) const;
			Vector2 operator+=(const Vector2& other);
		};

		Vector2 clampVec(Vector2 vec, Vector2 min, Vector2 max);

		template <class digit>
		digit clamp(digit val, digit min, digit max);
	}
}
