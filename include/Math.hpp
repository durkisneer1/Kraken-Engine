#pragma once


namespace dk {
	namespace math {
		struct Vector2 {
			float x = 0.0f;
			float y = 0.0f;

			Vector2() = default;
			Vector2(float x, float y);
			Vector2(int x, int y);
			Vector2(float x, int y);
			Vector2(int x, float y);

			void ZERO();
			float getLength() const;
			void normalize();
			float distanceTo(const Vector2& other) const;

			Vector2 operator*(float scalar) const;
			Vector2 operator/(float scalar) const;
			Vector2 operator+(const Vector2& other) const;
			Vector2 operator-(const Vector2& other) const;
			Vector2 operator+=(const Vector2& other);
		};

		Vector2 clampVec(Vector2 vec, Vector2 min, Vector2 max);
		Vector2 lerpVec(Vector2 a, Vector2 b, float t);

		template <class digit>
		digit clamp(digit val, digit min, digit max);
	}
}
