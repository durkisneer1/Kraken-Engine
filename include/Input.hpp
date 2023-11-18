#pragma once

#include <SDL.h>
#include <vector>
#include <algorithm>
#include "Math.hpp"


namespace dk {
	namespace input {
		dk::math::Vector2 getMousePos();

		const Uint8* getKeysPressed();

		dk::math::Vector2 getVector(
			const std::vector<SDL_Scancode>& up,
			const std::vector<SDL_Scancode>& left,
			const std::vector<SDL_Scancode>& down,
			const std::vector<SDL_Scancode>& right
		);
	}
}
