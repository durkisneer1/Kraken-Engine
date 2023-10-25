#pragma once


namespace DK_Math {
	struct Vector2 {
		float x = 0;
		float y = 0;

		Vector2() = default;
		Vector2(float x, float y) : x(x), y(y) {}
		Vector2(int x, int y) : x((float) x), y((float) y) {}
	};
}