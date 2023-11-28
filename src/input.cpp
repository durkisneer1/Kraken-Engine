#include "../include/Input.hpp"
#include <algorithm>


namespace dk {
	namespace input {
		dk::math::Vector2 getMousePos() {
			int x, y;
			SDL_GetMouseState(&x, &y);
			return { x, y };
		}

		const int getMouseButtonPressed() {
			return SDL_GetMouseState(nullptr, nullptr);
		}

		const Uint8* getKeysPressed() {
			return SDL_GetKeyboardState(nullptr);
		}

		dk::math::Vector2 getVector(
			const std::vector<SDL_Scancode>& left,
			const std::vector<SDL_Scancode>& right,
			const std::vector<SDL_Scancode>& up,
			const std::vector<SDL_Scancode>& down
		) {
			const Uint8* keys = getKeysPressed();
			dk::math::Vector2 vector;

			if (std::any_of(up.begin(), up.end(), [&](auto scancode) {
				return keys[scancode];
				})) {
				vector.y -= 1;
			} else {}
			if (std::any_of(left.begin(), left.end(), [&](auto scancode) {
				return keys[scancode];
				})) {
				vector.x -= 1;
			} else {}
			if (std::any_of(down.begin(), down.end(), [&](auto scancode) {
				return keys[scancode];
				})) {
				vector.y += 1;
			} else {}
			if (std::any_of(right.begin(), right.end(), [&](auto scancode) {
				return keys[scancode];
				})) {
				vector.x += 1;
			} else {}

			if (vector.getLength() > 0) {
				vector.normalize();
			} else {}

			return vector;
		}
	}
}
