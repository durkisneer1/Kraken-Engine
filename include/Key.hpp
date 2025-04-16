#pragma once

#include "Constants.hpp"
#include <cstdint>

namespace kn
{
namespace math
{
class Vec2;
} // namespace math

namespace key
{

/**
 * @brief Check if a key is pressed.
 *
 * @param key The key's scancode to check.
 *
 * @return ``true`` if the key is pressed, ``false`` otherwise.
 */
[[nodiscard]] bool isPressed(Scancode key);

/**
 * @brief Check if a key is just pressed.
 *
 * @param key The key's scancode to check.
 * @return ``true`` if the key is just pressed, ``false`` otherwise.
 */
[[nodiscard]] bool isJustPressed(Scancode key);

/**
 * @brief Check if a key is just released.
 *
 * @param key The key's scancode to check.
 * @return ``true`` if the key is just released, ``false`` otherwise.
 */
[[nodiscard]] bool isJustReleased(Scancode key);

/**
 * @brief Check if a key is pressed.
 *
 * @param key The key's keycode to check.
 *
 * @return ``true`` if the key is pressed, ``false`` otherwise.
 */
[[nodiscard]] bool isPressed(Keycode key);

/**
 * @brief Check if a key is just pressed.
 *
 * @param key The key's keycode to check.
 * @return ``true`` if the key is just pressed, ``false`` otherwise.
 */
[[nodiscard]] bool isJustPressed(Keycode key);

/**
 * @brief Check if a key is just released.
 *
 * @param key The key's keycode to check.
 * @return ``true`` if the key is just released, ``false`` otherwise.
 */
[[nodiscard]] bool isJustReleased(Keycode key);

} // namespace key
} // namespace kn
