#pragma once

#include <vector>

#include "Constants.hpp"

namespace kn
{
namespace math
{
class Vec2;
} // namespace math

namespace input
{
/**
 * @brief Get the mouse position.
 *
 * @return The mouse position.
 */
math::Vec2 getMousePos();

/**
 * @brief Check if the argument mouse button is pressed.
 *
 * @param button The mouse button to check.
 *
 * @return If the argument mouse button is pressed.
 */
bool isMouseButtonPressed(int button);

/**
 * @brief Check if the argument key is pressed.
 *
 * @param key The key to check.
 *
 * @return If the argument key is pressed.
 */
bool isKeyPressed(int key);

/**
 * @brief Get the vector of the keys pressed.
 *
 * @param left The keys to move left.
 * @param right The keys to move right.
 * @param up The keys to move up.
 * @param down The keys to move down.
 *
 * @return The vector of the keys pressed.
 */
math::Vec2 getVector(const std::vector<KEYS>& left = {}, const std::vector<KEYS>& right = {},
                     const std::vector<KEYS>& up = {}, const std::vector<KEYS>& down = {});

// /**
// * @brief Change the dead zone for controller joystick input.
// *
// * @param deadZone The dead zone for the controller from the range 0.0 to 1.0.
// *
// * @note Negative values will be clamped to 0.0 and values greater than 1.0 will be clamped
// to 1.0.
// */
// void setControllerDeadZone(float deadZone);
//
// /**
//  * @brief Get the dead zone for controller joystick input.
//  *
//  * @return The dead zone for the controller from the range 0.0 to 1.0.
//  */
// float getControllerDeadZone();

} // namespace input
} // namespace kn
