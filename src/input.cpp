#include "../include/Input.hpp"


namespace DK_Input {
	const Uint8* getKeysPressed() {
		return SDL_GetKeyboardState(nullptr);
	}

	DK_Math::Vector2f getVector(Uint8 up, Uint8 down, Uint8 left, Uint8 right) {
		const Uint8* keys = getKeysPressed();
		DK_Math::Vector2f vector;
		if (keys[up]) {
			vector.y = -1;
		}
		if (keys[down]) {
			vector.y = 1;
		}
		if (keys[left]) {
			vector.x = -1;
		}
		if (keys[right]) {
			vector.x = 1;
		}
		if (vector.length() > 0) {
			vector.normalize();
		}
		return vector;
	}
}