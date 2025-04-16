#pragma once

#include "Constants.hpp"
#include <cstdint>

namespace kn
{
namespace math
{
class Vec2;
} // namespace math

namespace mouse
{
/**
 * @brief Get the mouse position.
 *
 * @return The mouse position as a vector.
 */
math::Vec2 getPos();

/**
 * @brief Get the mouse offset since the last frame.
 *
 * @return A vector representing the mouse offset since the last frame.
 */
math::Vec2 getRel();

/**
 * @brief Check if a button is pressed.
 *
 * @param button The button to check.
 * @return ``true`` if pressed, ``false`` otherwise.
 */
bool isPressed(MouseButton button);

/**
 * @brief Check if a button is just pressed.
 *
 * @param button The button to check.
 * @return ``true`` if just pressed, ``false`` otherwise.
 */
bool isJustPressed(MouseButton button);

/**
 * @brief Check if a button is just released.
 *
 * @param button The button to check.
 * @return ``true`` if just released, ``false`` otherwise.
 */
bool isJustReleased(MouseButton button);

/**
 * @brief Lock the cursor to the center of the window and hide it.
 * Commonly used when you want to solely focus on relative mouse movement.
 */
void lock();

/**
 * @brief Unlock the cursor and show it.
 */
void unlock();

/**
 * @brief Check if the cursor is locked.
 *
 * @return ``true`` if locked, ``false`` otherwise.
 */
bool isLocked();

/**
 * @brief Hide the cursor.
 */
void hide();

/**
 * @brief Show the cursor.
 */
void show();

/**
 * @brief Check if the cursor is hidden.
 *
 * @return ``true`` if hidden, ``false`` otherwise.
 */
bool isHidden();

} // namespace mouse
} // namespace kn