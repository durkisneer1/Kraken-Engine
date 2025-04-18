#include "Key.hpp"
#include "_globals.hpp"
#include <SDL.h>

namespace kn
{

bool key::isPressed(Scancode key)
{
    const Uint8* state = SDL_GetKeyboardState(nullptr);
    return state[key];
}

bool key::isJustPressed(Scancode key) { return g_scancodePressed[key]; }

bool key::isJustReleased(Scancode key) { return g_scancodeReleased[key]; }

bool key::isPressed(Keycode key)
{
    const Uint8* keyboardState = SDL_GetKeyboardState(nullptr);
    SDL_Scancode scancode = SDL_GetScancodeFromKey(key);
    return keyboardState[scancode];
}

bool key::isJustPressed(Keycode key)
{
    auto it = g_keycodePressed.find(key);
    return it != g_keycodePressed.end() && it->second;
}

bool key::isJustReleased(Keycode key)
{
    auto it = g_keycodeReleased.find(key);
    return it != g_keycodeReleased.end() && it->second;
}

} // namespace kn