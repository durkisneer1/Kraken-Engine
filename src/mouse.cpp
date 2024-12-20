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

uint32_t getPressed() { return SDL_GetMouseState(nullptr, nullptr); }

} // namespace kn::mouse
