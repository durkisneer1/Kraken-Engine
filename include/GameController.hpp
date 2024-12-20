#pragma once
#include "Constants.hpp"

namespace kn
{
namespace math
{
class Vec2;
} // namespace math

namespace controller
{
/**
 * @brief Get the direction vector from the controller's left joystick.
 *
 * @return A direction vector. If the controller is not connected, a zero vector is returned.
 */
[[nodiscard]] math::Vec2 getLeftJoystick();

/**
 * @brief Get the direction vector from the controller's right joystick.
 *
 * @return A direction vector. If the controller is not connected, a zero vector is returned.
 */
[[nodiscard]] math::Vec2 getRightJoystick();

/**
 * @brief Get how far the controller's left trigger is pressed.
 *
 * @return The value of the left trigger from the range 0.0 to 1.0. If the controller is not
 * connected, 0.0 is returned.
 */
[[nodiscard]] double getLeftTrigger();

/**
 * @brief Get how far the controller's right trigger is pressed.
 *
 * @return The value of the right trigger from the range 0.0 to 1.0. If the controller is not
 * connected, 0.0 is returned.
 */
[[nodiscard]] double getRightTrigger();

/**
 * @brief Check if a button on the controller is pressed.
 *
 * @param button The button to check.
 *
 * @return ``true`` if the button is pressed, ``false`` otherwise. If the controller is not
 * connected, ``false`` is returned.
 */
[[nodiscard]] bool isPressed(ControllerButton button);

/**
* @brief Change the dead zone for controller joystick input.
*
* @param deadZone The dead zone for the controller from the range 0.0 to 1.0.
*
* @note Negative values will be clamped to 0.0 and values greater than 1.0 will be clamped
to 1.0.
*/
void setDeadZone(float deadZone);

/**
 * @brief Get the dead zone for controller joystick input.
 *
 * @return The dead zone for the controller from the range 0.0 to 1.0.
 */
[[nodiscard]] float getDeadZone();

} // namespace controller
} // namespace kn
