#pragma once

#include "Constants.hpp"

namespace kn
{
struct Rect;
namespace math
{
struct Vec2;
}

namespace draw
{
/**
 * @brief Draw a rectangle.
 *
 * @param rect The rectangle to draw.
 * @param color The color of the rectangle.
 * @param thickness The thickness of the rectangle.
 *
 * @note If thickness remains 0, the rectangle will be filled.
 */
void rect(const Rect& rect, const Color& color, int thickness = 0);

/**
 * @brief Draw a line.
 *
 * @param start The starting point of the line.
 * @param end The ending point of the line.
 * @param color The color of the line.
 *
 * @note A 'thickness' parameter is in development.
 */
void line(const math::Vec2& start, const math::Vec2& end, const Color& color);

/**
 * @brief Draw a point.
 *
 * @param point The point to draw.
 * @param color The color of the point.
 */
void point(const math::Vec2& point, const Color& color);

/**
 * @brief Draw a circle.
 *
 * @param center The center of the circle.
 * @param radius The radius of the circle.
 * @param color The color of the circle.
 * @param thickness The thickness of the circle.
 *
 * @note If thickness remains 0, the circle will be filled.
 */
void circle(const math::Vec2& center, double radius, const Color& color, int thickness = 0);

} // namespace draw
} // namespace kn
