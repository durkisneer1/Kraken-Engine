#pragma once

#include <SDL.h>
#include <vector>
#include "Math.hpp"


namespace dk {
	namespace input {
		dk::math::Vector2 getMousePos();

		const int getMouseButtonPressed();

		const Uint8* getKeysPressed();

		dk::math::Vector2 getVector(
			const std::vector<SDL_Scancode>& left = {},
			const std::vector<SDL_Scancode>& right = {},
			const std::vector<SDL_Scancode>& up = {},
			const std::vector<SDL_Scancode>& down = {}
		);
	}
}
