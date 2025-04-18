#pragma once

#include "Constants.hpp"

namespace kn
{
struct Rect;
namespace math
{
class Vec2;
} // namespace math

namespace draw
{
/**
 * @brief Draw a rectangle.
 *
 * @param rect The rectangle to draw.
 * @param color The color of the rectangle.
 * @param thickness The thickness of the rectangle.
 *
 * @note If `thickness` remains 0, the rectangle will be filled.
 */
void rect(const Rect& rect, const Color& color, int thickness = 0);

/**
 * @brief Draw a line.
 *
 * @param start The starting point of the line.
 * @param end The ending point of the line.
 * @param color The color of the line.
 * @param thickness The thickness of the line.
 *
 * @note A `thickness` of 0 or less will not draw anything.
 */
void line(const math::Vec2& start, const math::Vec2& end, const Color& color, int thickness = 1);

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
 * @note If `thickness` is a value of 0 or less, the circle will be filled.
 * A `radius` of 0 or less will not draw anything.
 */
void circle(const math::Vec2& center, int radius, const Color& color, int thickness = 0);

} // namespace draw
} // namespace kn
