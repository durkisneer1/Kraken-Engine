#include "Input.hpp"

#include <algorithm>
#include <unordered_map>

#include "ErrorLogger.hpp"
#include "GameController.hpp"
#include "Key.hpp"
#include "Math.hpp"
#include "Mouse.hpp"

namespace kn
{

static std::unordered_map<std::string, std::vector<InputAction>> _inputBindings;

InputAction::InputAction(const Scancode key) : type(InputType::KEYBOARD), key(key) {}

InputAction::InputAction(const ControllerAxis axis, const bool isPositive)
    : type(InputType::CONTROLLER_AXIS), controllerAxis{axis, isPositive}
{
}

InputAction::InputAction(const ControllerButton controllerButton)
    : type(InputType::CONTROLLER_BUTTON), controllerButton{controllerButton}
{
}

InputAction::InputAction(const int mouseButton) : type(InputType::MOUSE), mouseButton(mouseButton)
{
}

namespace input
{

void bind(const std::string& name, const std::vector<InputAction>& actions)
{
    if (name.empty())
    {
        WARN("Input binding name cannot be empty")
        return;
    }

    _inputBindings[name] = actions;
}

void unbind(const std::string& name) { _inputBindings.erase(name); }

math::Vec2 getDirection(const std::string& left, const std::string& right, const std::string& up,
                        const std::string& down)
{
    math::Vec2 directionVec;
    const auto* keysPressed = key::getPressed();
    const auto buttonsPressed = mouse::getPressed();
    const auto leftJoystick = controller::getLeftJoystick();
    const auto rightJoystick = controller::getRightJoystick();

    static const auto processActions =
        [&](const std::string& name, double& axisValue, const int direction)
    {
        if (const auto it = _inputBindings.find(name); it != _inputBindings.end())
            for (const InputAction& action : it->second)
            {
                if (action.type == InputType::KEYBOARD && keysPressed[action.key])
                    axisValue += direction;

                if (action.type == InputType::MOUSE && buttonsPressed == action.mouseButton)
                    axisValue += direction;

                if (action.type == InputType::CONTROLLER_BUTTON &&
                    controller::isPressed(action.controllerButton))
                    axisValue += direction;

                if (action.type == InputType::CONTROLLER_AXIS)
                {
                    if (action.controllerAxis.axis == C_AXIS_LEFTX &&
                        ((action.controllerAxis.isPositive && leftJoystick.x > 0.0) ||
                         (!action.controllerAxis.isPositive && leftJoystick.x < 0.0)))
                        axisValue += leftJoystick.x;
                    if (action.controllerAxis.axis == C_AXIS_LEFTY &&
                        ((action.controllerAxis.isPositive && leftJoystick.y > 0.0) ||
                         (!action.controllerAxis.isPositive && leftJoystick.y < 0.0)))
                        axisValue += leftJoystick.y;
                    if (action.controllerAxis.axis == C_AXIS_RIGHTX &&
                        ((action.controllerAxis.isPositive && rightJoystick.x > 0.0) ||
                         (!action.controllerAxis.isPositive && rightJoystick.x < 0.0)))
                        axisValue += rightJoystick.x;
                    if (action.controllerAxis.axis == C_AXIS_RIGHTY &&
                        ((action.controllerAxis.isPositive && rightJoystick.y > 0.0) ||
                         (!action.controllerAxis.isPositive && rightJoystick.y < 0.0)))
                        axisValue += rightJoystick.y;
                }
            }
    };

    processActions(left, directionVec.x, -1); // Left decreases X
    processActions(right, directionVec.x, 1); // Right increases X
    processActions(up, directionVec.y, -1);   // Up decreases Y
    processActions(down, directionVec.y, 1);  // Down increases Y

    if (directionVec.getLength() > 1.0f)
        directionVec.normalize();

    return directionVec;
}

bool isPressed(const std::string& name)
{
    const auto it = _inputBindings.find(name);
    if (it == _inputBindings.end())
        return false;

    return std::any_of(
        it->second.begin(), it->second.end(),
        [](const InputAction& action)
        {
            return (action.type == InputType::KEYBOARD && key::getPressed()[action.key]) ||
                   (action.type == InputType::MOUSE && mouse::getPressed() == action.mouseButton) ||
                   (action.type == InputType::CONTROLLER_BUTTON &&
                    controller::isPressed(action.controllerButton));
        });
}
} // namespace input
} // namespace kn
