#pragma once
#include <SDL.h>
#include "Math.hpp"

namespace DK_Input {
	const Uint8* getKeysPressed();
	DK_Math::Vector2f getVector(Uint8 up, Uint8 down, Uint8 left, Uint8 right);
}