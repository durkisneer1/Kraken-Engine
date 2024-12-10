#include "Mouse.hpp"
#include "Math.hpp"
#include "Window.hpp"

namespace kn::mouse
{
math::Vec2 getPos()
{
    int x, y;
    SDL_GetMouseState(&x, &y);
    const math::Vec2 pos{x, y};
    return pos / window::getScale() + camera;
}

bool isPressed(const uint32_t button) { return SDL_GetMouseState(nullptr, nullptr) == button; }
} // namespace kn::mouse
