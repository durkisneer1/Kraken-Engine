#include "Key.hpp"
#include <SDL.h>

namespace kn::key
{

const uint8_t* getPressed() { return SDL_GetKeyboardState(nullptr); }

} // namespace kn::key