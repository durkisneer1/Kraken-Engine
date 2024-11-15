#include <algorithm>

#include "Constants.hpp"
#include "Input.hpp"
#include "Math.hpp"
#include "Window.hpp"

namespace kn::input
{
math::Vec2 getMousePos()
{
    int x, y;
    SDL_GetMouseState(&x, &y);
    const int scale = window::getScale();
    const math::Vec2 pos{x / scale, y / scale};
    return pos + camera;
}

int getMouseButtonPressed() { return static_cast<int>(SDL_GetMouseState(nullptr, nullptr)); }

const Uint8* getKeysPressed() { return SDL_GetKeyboardState(nullptr); }

math::Vec2 getVector(const std::vector<KEYS>& left, const std::vector<KEYS>& right,
                     const std::vector<KEYS>& up, const std::vector<KEYS>& down)
{
    const Uint8* keys = getKeysPressed();
    math::Vec2 vector;

    if (std::any_of(up.begin(), up.end(), [&](auto scancode) { return keys[scancode]; }))
        vector.y -= 1;
    if (std::any_of(left.begin(), left.end(), [&](auto scancode) { return keys[scancode]; }))
        vector.x -= 1;
    if (std::any_of(down.begin(), down.end(), [&](auto scancode) { return keys[scancode]; }))
        vector.y += 1;
    if (std::any_of(right.begin(), right.end(), [&](auto scancode) { return keys[scancode]; }))
        vector.x += 1;

    if (vector.getLength() > 0)
        vector.normalize();

    return vector;
}
} // namespace kn::input
