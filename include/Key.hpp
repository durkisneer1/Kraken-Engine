#pragma once

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
 * @brief Get the keys that are currently pressed.
 *
 * @return The keys that are currently pressed.
 */
[[nodiscard]] const uint8_t* getPressed();

} // namespace key
} // namespace kn