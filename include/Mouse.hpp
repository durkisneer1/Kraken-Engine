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
 * @brief Get all the mouse buttons that are pressed.
 *
 * @return A bitfield of all the mouse buttons that are pressed.
 */
uint32_t getPressed();

} // namespace mouse
} // namespace kn