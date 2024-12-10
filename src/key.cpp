#include "Key.hpp"
#include <SDL.h>

namespace kn::key
{

bool isPressed(const int key) { return SDL_GetKeyboardState(nullptr)[key]; }

} // namespace kn::key