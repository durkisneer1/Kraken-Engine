#pragma once

#include <SDL.h>
#include <vector>
#include "Math.hpp"


namespace kn {
namespace input {

/// @brief Get the mouse position.
/// @return The mouse position.
/// @note The scale parameter is temporary.
math::Vec2 getMousePos(int scale = 1);

/// @brief Get the mouse button pressed.
/// @return The mouse button pressed.
const int getMouseButtonPressed();

/// @brief Get the keys pressed.
/// @return The keys pressed.
const Uint8* getKeysPressed();

/// @brief Get the vector of the keys pressed.
/// @param left The keys to move left.
/// @param right The keys to move right.
/// @param up The keys to move up.
/// @param down The keys to move down.
/// @return The vector of the keys pressed.
math::Vec2 getVector(
	const std::vector<SDL_Scancode>& left = {},
	const std::vector<SDL_Scancode>& right = {},
	const std::vector<SDL_Scancode>& up = {},
	const std::vector<SDL_Scancode>& down = {}
);

}
}
