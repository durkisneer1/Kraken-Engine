#include "../include/Input.hpp"


namespace DK_Input {
	const Uint8* getKeysPressed() {
		return SDL_GetKeyboardState(nullptr);
	}

	DK_Math::Vector2f getVector(
        const std::vector<SDL_Scancode>& up,
        const std::vector<SDL_Scancode>& left,
        const std::vector<SDL_Scancode>& down,
        const std::vector<SDL_Scancode>& right
        ) {
		const Uint8* keys = getKeysPressed();
		DK_Math::Vector2f vector;
        for (auto scancode : up) {
            if (keys[scancode]) {
                vector.y -= 1;
                break;
            }
        }
        for (auto scancode : left) {
            if (keys[scancode]) {
                vector.x -= 1;
                break;
            }
        }
        for (auto scancode : down) {
            if (keys[scancode]) {
                vector.y += 1;
                break;
            }
        }
        for (auto scancode : right) {
            if (keys[scancode]) {
                vector.x += 1;
                break;
            }
        }
		if (vector.length() > 0) {
			vector.normalize();
		}
		return vector;
	}
}