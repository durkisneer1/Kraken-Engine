#include "Mouse.hpp"
#include "Math.hpp"
#include "Window.hpp"
#include "_globals.hpp"

namespace kn::mouse
{
math::Vec2 getPos()
{
    int x, y;
    SDL_GetMouseState(&x, &y);
    const math::Vec2 pos{x, y};
    return pos / window::getScale() + camera;
}

math::Vec2 getRel()
{
    int dx, dy;
    SDL_GetRelativeMouseState(&dx, &dy);
    const math::Vec2 rel{dx, dy};
    return rel / window::getScale();
}

bool isPressed(MouseButton button)
{
    return SDL_GetMouseState(nullptr, nullptr) & static_cast<uint32_t>(button);
}

bool isJustPressed(MouseButton button) { return g_mousePressed[static_cast<uint32_t>(button) - 1]; }

bool isJustReleased(MouseButton button)
{
    return g_mouseReleased[static_cast<uint32_t>(button) - 1];
}

void lock() { SDL_SetRelativeMouseMode(SDL_TRUE); }

void unlock() { SDL_SetRelativeMouseMode(SDL_FALSE); }

bool isLocked() { return SDL_GetRelativeMouseMode(); }

void hide() { SDL_ShowCursor(SDL_DISABLE); }

void show() { SDL_ShowCursor(SDL_ENABLE); }

bool isHidden() { return !SDL_ShowCursor(SDL_QUERY); }

} // namespace kn::mouse
