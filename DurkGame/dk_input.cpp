#include "pch.h"
#include "DK_Input.h"


namespace DK_Input {
	DK_Math::Vector2 getMousePos() {
		int x, y;
		SDL_GetMouseState(&x, &y);
		return { x, y };
	}

	const Uint8* getKeysPressed() {
		return SDL_GetKeyboardState(nullptr);
	}

	DK_Math::Vector2 getVector(
		const std::vector<SDL_Scancode>& up,
		const std::vector<SDL_Scancode>& left,
		const std::vector<SDL_Scancode>& down,
		const std::vector<SDL_Scancode>& right
	) {
		const Uint8* keys = getKeysPressed();
		DK_Math::Vector2 vector;

		if (std::any_of(up.begin(), up.end(), [&](auto scancode) {
			return keys[scancode];
			})) {
			vector.y -= 1;
		}
		if (std::any_of(left.begin(), left.end(), [&](auto scancode) {
			return keys[scancode];
			})) {
			vector.x -= 1;
		}
		if (std::any_of(down.begin(), down.end(), [&](auto scancode) {
			return keys[scancode];
			})) {
			vector.y += 1;
		}
		if (std::any_of(right.begin(), right.end(), [&](auto scancode) {
			return keys[scancode];
			})) {
			vector.x += 1;
		}

		if (vector.getLength() > 0) {
			vector.normalize();
		}

		return vector;
	}
}
