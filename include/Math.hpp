#pragma once


namespace kn {
	namespace math {
		/// @brief A struct to represent a 2D vector.
		struct Vec2 {
			float x = 0.0f;
			float y = 0.0f;

			Vec2() = default;
			Vec2(float x, float y);
			Vec2(int x, int y);
			Vec2(float x, int y);
			Vec2(int x, float y);

			/// @brief Get a zero vector.
			/// @return A zero vector.
			static Vec2 ZERO();

			/// @brief Get the length of the vector.
			/// @return The length of the vector.
			float getLength() const;

			/// @brief Normalize the vector.
			void normalize();

			/// @brief Get the distance to another vector.
			/// @param other The other vector.
			/// @return The distance to another vector.
			float distanceTo(const Vec2& other) const;

			Vec2 operator*(float scalar) const;
			Vec2 operator/(float scalar) const;
			Vec2 operator+(const Vec2& other) const;
			Vec2 operator-(const Vec2& other) const;
			Vec2 operator+=(const Vec2& other);
		};

		/// @brief Clamp a vector.
		/// @param vec The vector to clamp.
		/// @param min The minimum value.
		/// @param max The maximum value.
		/// @return The clamped vector.
		Vec2 clampVec(Vec2 vec, Vec2 min, Vec2 max);

		/// @brief Linearly interpolate a vector.
		/// @param a The first vector.
		/// @param b The second vector.
		/// @param t The time.
		/// @return The interpolated vector.
		Vec2 lerpVec(Vec2 a, Vec2 b, float t);

		/// @brief Clamp a value.
		/// @param val The value to clamp.
		/// @param min The minimum value.
		/// @param max The maximum value.
		/// @return The clamped value.
		template <class digit>
		digit clamp(digit val, digit min, digit max);
	}
}
