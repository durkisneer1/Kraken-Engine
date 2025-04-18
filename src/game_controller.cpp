#include <algorithm>

#include "GameController.hpp"
#include "Math.hpp"
#include "_globals.hpp"

namespace kn::controller
{
static float _deadZone = 0.1f;

math::Vec2 getLeftJoystick()
{
    if (!_controller)
        return {};

    math::Vec2 controllerDir = {SDL_GameControllerGetAxis(_controller, C_AXIS_LEFTX),
                                SDL_GameControllerGetAxis(_controller, C_AXIS_LEFTY)};
    controllerDir /= 32767.0;
    if (controllerDir.getLength() > _deadZone)
        return controllerDir;

    return {};
}

math::Vec2 getRightJoystick()
{
    if (!_controller)
        return {};

    math::Vec2 controllerDir = {SDL_GameControllerGetAxis(_controller, C_AXIS_RIGHTX),
                                SDL_GameControllerGetAxis(_controller, C_AXIS_RIGHTY)};
    controllerDir /= 32767.0;
    if (controllerDir.getLength() > _deadZone)
        return controllerDir;

    return {};
}

double getLeftTrigger()
{
    if (!_controller)
        return 0.0;

    return SDL_GameControllerGetAxis(_controller, C_TRIGGERLEFT) / 32768.0;
}

double getRightTrigger()
{
    if (!_controller)
        return 0.0;

    return SDL_GameControllerGetAxis(_controller, C_TRIGGERRIGHT) / 32768.0;
}

bool isPressed(const ControllerButton button)
{
    if (!_controller)
        return false;

    return SDL_GameControllerGetButton(_controller, button);
}

bool isJustPressed(const ControllerButton button) { return g_controllerPressed[button]; }

bool isJustReleased(const ControllerButton button) { return g_controllerReleased[button]; }

void setDeadZone(const float deadZone) { _deadZone = std::clamp(deadZone, 0.0f, 1.0f); }

float getDeadZone() { return _deadZone; }

} // namespace kn::controller
