#pragma once
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
 * @brief Check if the argument mouse button is pressed.
 *
 * @param button The mouse button to check.
 *
 * @return If the argument mouse button is pressed.
 */
bool isPressed(uint32_t button);

} // namespace mouse
} // namespace kn