#pragma once

#include <string>
#include <vector>

#include "Constants.hpp"

namespace kn
{

enum class InputType
{
    KEYBOARD,
    MOUSE,
    CONTROLLER_AXIS,
    CONTROLLER_BUTTON
};

/**
 * @brief An input action.
 * Can either be a keyboard key, a mouse button, a controller button or a controller joystick.
 */
struct InputAction
{
    InputType type;
    union
    {
        Scancode key;
        ControllerButton controllerButton;
        uint32_t mouseButton;
        struct
        {
            ControllerAxis axis;
            bool isPositive;
        } controllerAxis;
    };

    /**
     * @param key The keyboard key.
     */
    explicit InputAction(Scancode key);

    /**
     * @param axis The controller axis.
     * @param isPositive Whether the axis is positive or negative.
     */
    InputAction(ControllerAxis axis, bool isPositive);

    /**
     * @param controllerButton The controller button.
     */
    explicit InputAction(ControllerButton controllerButton);

    /**
     * @param mouseButton The mouse button.
     */
    explicit InputAction(int mouseButton);
};

namespace math
{
class Vec2;
} // namespace math

namespace input
{

/**
 * @brief Bind a name to a set of input actions.
 *
 * @param name The name to bind to the input actions.
 * @param actions The input actions to bind to the name.
 */
void bind(const std::string& name, const std::vector<InputAction>& actions);

/**
 * @brief Unbind a name from the input actions.
 *
 * @param name The name to unbind from the input actions.
 */
void unbind(const std::string& name);

/**
 * @brief Get a normalized direction vector based on the input actions.
 *
 * @param left The name of the input action for moving left.
 * @param right The name of the input action for moving right.
 * @param up The name of the input action for moving up.
 * @param down The name of the input action for moving down.
 *
 * @return A normalized direction vector.
 */
[[nodiscard]] math::Vec2 getDirection(const std::string& left = "", const std::string& right = "",
                                      const std::string& up = "", const std::string& down = "");

/**
 * @brief Check if an input action is pressed.
 *
 * @param name The name of the input action to check.
 *
 * @return ``true`` if the input action is pressed, ``false`` otherwise.
 */
[[nodiscard]] bool isPressed(const std::string& name);

} // namespace input
} // namespace kn
