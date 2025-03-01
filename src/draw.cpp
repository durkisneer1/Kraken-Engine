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

static void drawCircleSegment(SDL_Renderer* renderer, const math::Vec2& center, int radius,
                              bool filled)
{
    int offsetX = 0;
    int offsetY = radius;
    int d = radius - 1;
    // Precompute the camera-adjusted center.
    const float cx = static_cast<float>(center.x - camera.x);
    const float cy = static_cast<float>(center.y - camera.y);

    while (offsetY >= offsetX)
    {
        if (filled)
        {
            // Draw horizontal spans to fill the circle.
            SDL_RenderDrawLineF(renderer, cx - offsetY, cy + offsetX, cx + offsetY, cy + offsetX);
            SDL_RenderDrawLineF(renderer, cx - offsetX, cy + offsetY, cx + offsetX, cy + offsetY);
            SDL_RenderDrawLineF(renderer, cx - offsetX, cy - offsetY, cx + offsetX, cy - offsetY);
            SDL_RenderDrawLineF(renderer, cx - offsetY, cy - offsetX, cx + offsetY, cy - offsetX);
        }
        else
        {
            // Plot the eight symmetrical points along the circle's edge.
            SDL_RenderDrawPointF(renderer, cx + offsetX, cy + offsetY);
            SDL_RenderDrawPointF(renderer, cx + offsetY, cy + offsetX);
            SDL_RenderDrawPointF(renderer, cx - offsetX, cy + offsetY);
            SDL_RenderDrawPointF(renderer, cx - offsetY, cy + offsetX);
            SDL_RenderDrawPointF(renderer, cx + offsetX, cy - offsetY);
            SDL_RenderDrawPointF(renderer, cx + offsetY, cy - offsetX);
            SDL_RenderDrawPointF(renderer, cx - offsetX, cy - offsetY);
            SDL_RenderDrawPointF(renderer, cx - offsetY, cy - offsetX);
        }

        // Midpoint circle algorithm decision step.
        if (d >= offsetX * 2)
        {
            d -= offsetX * 2 + 1;
            ++offsetX;
        }
        else if (d < 2 * (radius - offsetY))
        {
            d += offsetY * 2 - 1;
            --offsetY;
        }
        else
        {
            d += 2 * (offsetY - offsetX - 1);
            --offsetY;
            ++offsetX;
        }
    }
}

void circle(const math::Vec2& center, int radius, const Color& color, const int thickness)
{
    SDL_Renderer* renderer = window::getRenderer();
    if (!renderer)
    {
        WARN("Cannot draw circle before creating the window");
        return;
    }

    if (radius < 1)
        return;

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    // For a filled circle, simply draw one segment using horizontal spans.
    if (thickness <= 0)
        drawCircleSegment(renderer, center, radius, true);
    else
        // For an outlined circle with thickness, draw multiple concentric outlines.
        for (int i = 0; i < thickness; i++)
        {
            drawCircleSegment(renderer, center, radius, false);
            --radius;
        }
}

} // namespace kn::draw