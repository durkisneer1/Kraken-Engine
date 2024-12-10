#include <algorithm>

#include "Constants.hpp"
#include "Input.hpp"
#include "Math.hpp"
#include "Window.hpp"

#include <_globals.hpp>

namespace kn::input
{
static float _deadZone = 0.1f;

math::Vec2 getMousePos()
{
    int x, y;
    SDL_GetMouseState(&x, &y);
    const int scale = window::getScale();
    const math::Vec2 pos{x / scale, y / scale};
    return pos + camera;
}

bool isMouseButtonPressed(const Uint32 button)
{
    return SDL_GetMouseState(nullptr, nullptr) == button;
}

bool isKeyPressed(const int key) { return SDL_GetKeyboardState(nullptr)[key]; }

math::Vec2 getVector(const std::vector<KEYS>& left, const std::vector<KEYS>& right,
                     const std::vector<KEYS>& up, const std::vector<KEYS>& down)
{
    math::Vec2 vector;

    if (std::any_of(up.begin(), up.end(), [&](auto scancode) { return isKeyPressed(scancode); }))
        vector.y -= 1;
    if (std::any_of(left.begin(), left.end(),
                    [&](auto scancode) { return isKeyPressed(scancode); }))
        vector.x -= 1;
    if (std::any_of(down.begin(), down.end(),
                    [&](auto scancode) { return isKeyPressed(scancode); }))
        vector.y += 1;
    if (std::any_of(right.begin(), right.end(),
                    [&](auto scancode) { return isKeyPressed(scancode); }))
        vector.x += 1;

    if (vector.getLength() > 1)
        vector.normalize();

    if (_controller)
    {
        math::Vec2 controllerDir = {
            SDL_GameControllerGetAxis(_controller, SDL_CONTROLLER_AXIS_LEFTX),
            SDL_GameControllerGetAxis(_controller, SDL_CONTROLLER_AXIS_LEFTY)};
        controllerDir /= 32767.0;
        if (controllerDir.getLength() > _deadZone)
            vector += controllerDir;
    }

    if (vector.getLength() > 1)
        vector.scaleToLength(1);

    return vector;
}

// void setControllerDeadZone(const float deadZone)
// {
//     _deadZone = std::clamp(deadZone, 0.0f, 1.0f);
// }
//
// float getControllerDeadZone() { return _deadZone; }

} // namespace kn::input
