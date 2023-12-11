#pragma once


namespace kn {
	namespace math {
		/// @brief A struct to represent a 2D vector.
		struct Vector2 {
			float x = 0.0f;
			float y = 0.0f;

			Vector2() = default;
			Vector2(float x, float y);
			Vector2(int x, int y);
			Vector2(float x, int y);
			Vector2(int x, float y);

			/// @brief Get a zero vector.
			/// @return A zero vector.
			Vector2 ZERO();

			/// @brief Get the length of the vector.
			/// @return The length of the vector.
			float getLength() const;

			/// @brief Normalize the vector.
			void normalize();

			/// @brief Get the distance to another vector.
			/// @param other The other vector.
			/// @return The distance to another vector.
			float distanceTo(const Vector2& other) const;

			Vector2 operator*(float scalar) const;
			Vector2 operator/(float scalar) const;
			Vector2 operator+(const Vector2& other) const;
			Vector2 operator-(const Vector2& other) const;
			Vector2 operator+=(const Vector2& other);
		};

		/// @brief Clamp a vector.
		/// @param vec The vector to clamp.
		/// @param min The minimum value.
		/// @param max The maximum value.
		/// @return The clamped vector.
		Vector2 clampVec(Vector2 vec, Vector2 min, Vector2 max);

		/// @brief Linearly interpolate a vector.
		/// @param a The first vector.
		/// @param b The second vector.
		/// @param t The time.
		/// @return The interpolated vector.
		Vector2 lerpVec(Vector2 a, Vector2 b, float t);

		/// @brief Clamp a value.
		/// @param val The value to clamp.
		/// @param min The minimum value.
		/// @param max The maximum value.
		/// @return The clamped value.
		template <class digit>
		digit clamp(digit val, digit min, digit max);
	}
}
