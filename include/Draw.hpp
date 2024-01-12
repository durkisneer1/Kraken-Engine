#pragma once

#include <SDL.h>

#include "Rect.hpp"

namespace kn
{
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
void rect(Rect& rect, const SDL_Color color, int thickness = 0);

} // namespace draw
} // namespace kn