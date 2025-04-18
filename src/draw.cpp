#include <SDL.h>
#include <gfx/SDL2_gfxPrimitives.h>

#include "Draw.hpp"
#include "Math.hpp"
#include "Rect.hpp"
#include "Window.hpp"

namespace kn::draw
{
void rect(const Rect& rect, const Color& color, const int thickness)
{
    if (thickness < 0)
        return;

    SDL_SetRenderDrawColor(window::getRenderer(), color.r, color.g, color.b, color.a);

    const int halfWidth = static_cast<int>(rect.w / 2.0);
    const int halfHeight = static_cast<int>(rect.h / 2.0);
    if (thickness == 0 || thickness > halfWidth || thickness > halfHeight)
    {
        Rect offsetRect = rect;
        offsetRect.topLeft(offsetRect.topLeft() - camera);
        SDL_RenderFillRectF(window::getRenderer(), &offsetRect);
        return;
    }

    for (int i = 0; i < thickness; i++)
    {
        const auto offset = static_cast<float>(i);
        Rect layerRect = {static_cast<float>(rect.x + offset - camera.x),
                          static_cast<float>(rect.y + offset - camera.y), rect.w - offset * 2,
                          rect.h - offset * 2};
        SDL_RenderDrawRectF(window::getRenderer(), &layerRect);
    }
}

void line(const math::Vec2& start, const math::Vec2& end, const Color& color, const int thickness)
{
    SDL_Renderer* renderer = window::getRenderer();
    if (!renderer)
    {
        WARN("Cannot draw line before creating the window");
        return;
    }

    if (thickness < 1)
        return;

    const math::Vec2 offsetStart = start - camera;
    const math::Vec2 offsetEnd = end - camera;

    const auto x1 = static_cast<Sint16>(offsetStart.x);
    const auto y1 = static_cast<Sint16>(offsetStart.y);
    const auto x2 = static_cast<Sint16>(offsetEnd.x);
    const auto y2 = static_cast<Sint16>(offsetEnd.y);

    thickLineRGBA(renderer, x1, y1, x2, y2, thickness, color.r, color.g, color.b, color.a);
}

void point(const math::Vec2& point, const Color& color)
{
    SDL_SetRenderDrawColor(window::getRenderer(), color.r, color.g, color.b, color.a);

    SDL_RenderDrawPointF(window::getRenderer(), static_cast<float>(point.x - camera.x),
                         static_cast<float>(point.y - camera.y));
}

void circle(const math::Vec2& center, int radius, const Color& color, const int thickness)
{
    SDL_Renderer* renderer = window::getRenderer();
    if (!renderer)
    {
        WARN("Cannot draw circle before creating the window");
        return;
    }
    if (radius <= 0)
        return;

    // Enable alpha blending
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    // Compute camera‑adjusted center
    const float cx = center.x - camera.x;
    const float cy = center.y - camera.y;
    int r2 = radius * radius;

    // Filled circle if thickness <= 0 or >= radius
    if (thickness <= 0 || thickness >= radius)
    {
        for (int dy = -radius + 1; dy < radius; ++dy)
        {
            int dx = static_cast<int>(std::floor(std::sqrt(r2 - dy * dy)));
            if (dy == 0 && dx > 0)
                dx--;
            SDL_RenderDrawLineF(renderer, cx - dx, cy + dy, cx + dx, cy + dy);
        }
        return;
    }

    // Outline ring of width `thickness`
    int innerRadius = radius - thickness;
    int ir2 = innerRadius * innerRadius;

    for (int dy = -radius + 1; dy < radius; ++dy)
    {
        int absDy = std::abs(dy);
        int dxOuter = static_cast<int>(std::floor(std::sqrt(r2 - dy * dy)));
        if (dy == 0 && dxOuter > 0)
            dxOuter--;

        if (absDy < innerRadius)
        {
            int dxInner = static_cast<int>(std::floor(std::sqrt(ir2 - dy * dy)));
            if (dy == 0 && dxInner > 0)
                dxInner--;
            // left edge of ring
            SDL_RenderDrawLineF(renderer, cx - dxOuter, cy + dy, cx - dxInner, cy + dy);
            // right edge of ring
            SDL_RenderDrawLineF(renderer, cx + dxInner, cy + dy, cx + dxOuter, cy + dy);
        }
        else
        {
            // caps (top/bottom arcs)
            SDL_RenderDrawLineF(renderer, cx - dxOuter, cy + dy, cx + dxOuter, cy + dy);
        }
    }
}

} // namespace kn::draw