#pragma once

#include <string>
#include <variant>
#include <vector>

#include "Constants.hpp"

namespace kn
{

struct InputAction
{
    using InputData =
        std::variant<Scancode, MouseButton, ControllerButton, std::pair<ControllerAxis, bool>>;
    InputData data;

    /**
     * @brief Construct a new keyboard input action.
     *
     * @param key The keyboard key.
     */
    explicit InputAction(Scancode key);

    /**
     * @brief Construct a new mouse input action.
     *
     * @param mouseButton The mouse button.
     */
    explicit InputAction(MouseButton mouseButton);

    /**
     * @brief Construct a new controller button input action.
     *
     * @param controllerButton The controller button.
     */
    explicit InputAction(ControllerButton controllerButton);

    /**
     * @brief Construct a new controller axis input action.
     *
     * @param axis The controller axis.
     * @param isPositive Whether the axis is positive or negative.
     */
    InputAction(ControllerAxis axis, bool isPositive);
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
 * @brief Get the value of an axis based on the input actions.
 *
 * @param negative The name of the input action for negative axis movement.
 * @param positive The name of the input action for positive axis movement.
 * @return The value of the axis, ranging from ``-1.0`` to ``1.0``.
 */
[[nodiscard]] double getAxis(const std::string& negative = "", const std::string& positive = "");

/**
 * @brief Check if an input action is pressed.
 *
 * @param name The name of the input action to check.
 *
 * @return ``true`` if the input action is pressed, ``false`` otherwise.
 */
[[nodiscard]] bool isPressed(const std::string& name);

/**
 * @brief Check if an input action is just pressed.
 *
 * @param name The name of the input action to check.
 *
 * @return ``true`` if the input action is just pressed, ``false`` otherwise.
 */
[[nodiscard]] bool isJustPressed(const std::string& name);

/**
 * @brief Check if an input action is just released.
 *
 * @param name The name of the input action to check.
 *
 * @return ``true`` if the input action is released, ``false`` otherwise.
 */
[[nodiscard]] bool isJustReleased(const std::string& name);

} // namespace input
} // namespace kn
