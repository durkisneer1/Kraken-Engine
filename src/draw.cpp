#include <SDL.h>

#include "Rect.hpp"
#include "Window.hpp"

namespace kn::draw
{
void rect(const Rect& rect, const Color& color, float thickness)
{
    SDL_SetRenderDrawColor(window::getRenderer(), color.r, color.g, color.b, color.a);

    if (thickness == 0)
    {
        SDL_RenderFillRectF(window::getRenderer(), &rect);
        return;
    }

    if (thickness > rect.w / 2 || thickness > rect.h / 2)
        thickness = std::min(rect.w / 2, rect.h / 2);

    for (int i = 0; static_cast<float>(i) < thickness; i++)
    {
        const auto offset = static_cast<float>(i);
        Rect layerRect = {
            rect.x + offset, rect.y + offset, rect.w - offset * 2, rect.h - offset * 2
        };
        SDL_RenderDrawRectF(window::getRenderer(), &layerRect);
    }
}
} // namespace kn::draw