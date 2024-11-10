#include <SDL.h>

#include "Rect.hpp"
#include "Window.hpp"

namespace kn::draw
{
void rect(const Rect& rect, const Color& color, int thickness)
{
    SDL_SetRenderDrawColor(window::getRenderer(), color.r, color.g, color.b, color.a);

    if (thickness == 0)
    {
        Rect offsetRect = rect;
        offsetRect.setTopLeft(offsetRect.getTopLeft() - camera);
        SDL_RenderFillRectF(window::getRenderer(), &offsetRect);
        return;
    }

    const int halfWidth = static_cast<int>(rect.w / 2.0);
    const int halfHeight = static_cast<int>(rect.h / 2.0);

    if (thickness > halfWidth || thickness > halfHeight)
        thickness = std::min(halfWidth, halfHeight);

    for (int i = 0; i < thickness; i++)
    {
        const auto offset = static_cast<float>(i);
        Rect layerRect = {static_cast<float>(rect.x + offset - camera.x),
                          static_cast<float>(rect.y + offset - camera.y), rect.w - offset * 2,
                          rect.h - offset * 2};
        SDL_RenderDrawRectF(window::getRenderer(), &layerRect);
    }
}
} // namespace kn::draw