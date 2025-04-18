#include "Input.hpp"

#include <algorithm>
#include <unordered_map>

#include "ErrorLogger.hpp"
#include "GameController.hpp"
#include "Key.hpp"
#include "Math.hpp"
#include "Mouse.hpp"

template <class... Ts> struct overloaded : Ts...
{
    using Ts::operator()...;
};
template <class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

namespace kn
{

static std::unordered_map<std::string, std::vector<InputAction>> _inputBindings;

InputAction::InputAction(const Scancode key) : data(key) {}

InputAction::InputAction(const MouseButton mouseButton) : data(mouseButton) {}

InputAction::InputAction(const ControllerButton controllerButton) : data{controllerButton} {}

InputAction::InputAction(const ControllerAxis axis, const bool isPositive)
    : data(std::make_pair(axis, isPositive))
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
    const auto leftJoystick = controller::getLeftJoystick();
    const auto rightJoystick = controller::getRightJoystick();

    const auto processActions = [&](const std::string& name, double& axisValue, int direction)
    {
        const auto it = _inputBindings.find(name);
        if (it == _inputBindings.end())
            return;

        for (const InputAction& action : it->second)
        {
            std::visit(overloaded{[&](Scancode key)
                                  {
                                      if (key::isPressed(key))
                                          axisValue += direction;
                                  },
                                  [&](MouseButton button)
                                  {
                                      if (mouse::isPressed(button))
                                          axisValue += direction;
                                  },
                                  [&](ControllerButton button)
                                  {
                                      if (controller::isPressed(button))
                                          axisValue += direction;
                                  },
                                  [&](std::pair<ControllerAxis, bool> axisData)
                                  {
                                      auto [axis, isPositive] = axisData;

                                      auto process = [&](int a, double value)
                                      {
                                          if (axis == a && ((isPositive && value > 0.0) ||
                                                            (!isPositive && value < 0.0)))
                                              axisValue += value;
                                      };

                                      process(C_AXIS_LEFTX, leftJoystick.x);
                                      process(C_AXIS_LEFTY, leftJoystick.y);
                                      process(C_AXIS_RIGHTX, rightJoystick.x);
                                      process(C_AXIS_RIGHTY, rightJoystick.y);
                                  }},
                       action.data);
        }
    };

    processActions(left, directionVec.x, -1); // Left = -X
    processActions(right, directionVec.x, 1); // Right = +X
    processActions(up, directionVec.y, -1);   // Up = -Y
    processActions(down, directionVec.y, 1);  // Down = +Y

    if (directionVec.getLength() > 1.0f)
        directionVec.normalize();

    return directionVec;
}

double getAxis(const std::string& negative, const std::string& positive)
{
    double value = 0.0;
    const auto leftJoystick = controller::getLeftJoystick();
    const auto rightJoystick = controller::getRightJoystick();

    const auto processActions = [&](const std::string& name, int direction)
    {
        const auto it = _inputBindings.find(name);
        if (it == _inputBindings.end())
            return;

        for (const InputAction& action : it->second)
        {
            std::visit(overloaded{[&](Scancode key)
                                  {
                                      if (key::isPressed(key))
                                          value += direction;
                                  },
                                  [&](MouseButton button)
                                  {
                                      if (mouse::isPressed(button))
                                          value += direction;
                                  },
                                  [&](ControllerButton button)
                                  {
                                      if (controller::isPressed(button))
                                          value += direction;
                                  },
                                  [&](std::pair<ControllerAxis, bool> axisData)
                                  {
                                      auto [axis, isPositive] = axisData;

                                      auto process = [&](int a, double axisValue)
                                      {
                                          if (axis == a && ((isPositive && axisValue > 0.0) ||
                                                            (!isPositive && axisValue < 0.0)))
                                              value += axisValue;
                                      };

                                      process(C_AXIS_LEFTX, leftJoystick.x);
                                      process(C_AXIS_LEFTY, leftJoystick.y);
                                      process(C_AXIS_RIGHTX, rightJoystick.x);
                                      process(C_AXIS_RIGHTY, rightJoystick.y);
                                  }},
                       action.data);
        }
    };

    processActions(negative, -1);
    processActions(positive, 1);

    return std::clamp(value, -1.0, 1.0);
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
            return std::visit(
                overloaded{
                    [](Scancode key) { return key::isPressed(key); },
                    [](MouseButton mouse) { return mouse::isPressed(mouse); },
                    [](ControllerButton button) { return controller::isPressed(button); },
                    [](std::pair<ControllerAxis, bool>) { return false; } // not for discrete press
                },
                action.data);
        });
}

bool isJustPressed(const std::string& name)
{
    const auto it = _inputBindings.find(name);
    if (it == _inputBindings.end())
        return false;

    return std::any_of(
        it->second.begin(), it->second.end(),
        [](const InputAction& action)
        {
            return std::visit(
                overloaded{
                    [](Scancode key) { return key::isJustPressed(key); },
                    [](MouseButton mouse) { return mouse::isJustPressed(mouse); },
                    [](ControllerButton button) { return controller::isJustPressed(button); },
                    [](std::pair<ControllerAxis, bool>) { return false; } // not discrete
                },
                action.data);
        });
}

bool isJustReleased(const std::string& name)
{
    const auto it = _inputBindings.find(name);
    if (it == _inputBindings.end())
        return false;

    return std::any_of(
        it->second.begin(), it->second.end(),
        [](const InputAction& action)
        {
            return std::visit(
                overloaded{
                    [](Scancode key) { return key::isJustReleased(key); },
                    [](MouseButton mouse) { return mouse::isJustReleased(mouse); },
                    [](ControllerButton button) { return controller::isJustReleased(button); },
                    [](std::pair<ControllerAxis, bool>) { return false; } // not discrete
                },
                action.data);
        });
}

} // namespace input
} // namespace kn
