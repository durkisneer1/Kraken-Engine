#pragma once

namespace kn
{
namespace math
{
class Vec2;
}
namespace camera
{

/**
 * @brief Set the position of the camera
 *
 * @param pos The new position vector
 */
void pos(math::Vec2 pos);

/**
 * @brief Get the position of the camera
 *
 * @return A position vector
 */
[[nodiscard]] math::Vec2 pos();

/**
 * @brief Set the rotation of the camera in degrees
 *
 * @param rot The new rotation
 */
void rot(float rot);

/**
 * @brief Get the rotation of the camera in degrees
 *
 * @return The rotation
 */
[[nodiscard]] float rot();

math::Vec2 worldToScreen(const math::Vec2& worldPos);

} // namespace camera
} // namespace kn