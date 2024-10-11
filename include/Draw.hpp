#pragma once

#include "Constants.hpp"

namespace kn
{
struct Rect;

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
void rect(Rect& rect, const Color& color, float thickness = 0.0f);
} // namespace draw
} // namespace kn
