#pragma once

#include <SDL.h>

#include "RenderWindow.hpp"
#include "Rect.hpp"


namespace kn {
namespace draw {

/// @brief Draw a rectangle.
/// @param window Reference to the RenderWindow instance.
/// @param rect The rectangle to draw.
/// @param color The color of the rectangle.
/// @param thickness The thickness of the rectangle.
/// @note If thickness remains 0, the rectangle will be filled.
void rect(RenderWindow& window, Rect& rect, const SDL_Color color, int thickness = 0);

}
}