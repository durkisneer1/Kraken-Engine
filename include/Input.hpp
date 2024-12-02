#pragma once

#include <SDL.h>
#include <vector>

#include "Constants.hpp"

namespace kn
{
namespace math
{
class Vec2;
}  // namespace math

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
}  // namespace input
}  // namespace kn
