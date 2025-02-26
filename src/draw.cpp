#include <SDL.h>

#include "Camera.hpp"
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
        offsetRect.topLeft(offsetRect.topLeft() - camera::pos());
        SDL_RenderFillRectF(window::getRenderer(), &offsetRect);
        return;
    }

    for (int i = 0; i < thickness; i++)
    {
        const auto offset = static_cast<float>(i);
        Rect layerRect = {static_cast<float>(rect.x + offset - camera::pos().x),
                          static_cast<float>(rect.y + offset - camera::pos().y),
                          rect.w - offset * 2, rect.h - offset * 2};
        SDL_RenderDrawRectF(window::getRenderer(), &layerRect);
    }
}

void line(const math::Vec2& start, const math::Vec2& end, const Color& color)
{
    SDL_SetRenderDrawColor(window::getRenderer(), color.r, color.g, color.b, color.a);

    SDL_RenderDrawLineF(window::getRenderer(), static_cast<float>(start.x - camera::pos().x),
                        static_cast<float>(start.y - camera::pos().y),
                        static_cast<float>(end.x - camera::pos().x),
                        static_cast<float>(end.y - camera::pos().y));
}

void point(const math::Vec2& point, const Color& color)
{
    SDL_SetRenderDrawColor(window::getRenderer(), color.r, color.g, color.b, color.a);

    SDL_RenderDrawPointF(window::getRenderer(), static_cast<float>(point.x - camera::pos().x),
                         static_cast<float>(point.y - camera::pos().y));
}

void circle(const math::Vec2& center, double radius, const Color& color, const int thickness)
{
    if (thickness < 0)
        return;

    SDL_Renderer* renderer = window::getRenderer();
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    double offsetX = 0.0;
    double offsetY = radius;
    double d = radius - 1.0f;

    if (thickness == 0)
    {
        while (offsetY >= offsetX)
        {
            SDL_RenderDrawLineF(renderer, static_cast<float>(center.x - offsetY - camera::pos().x),
                                static_cast<float>(center.y + offsetX - camera::pos().y),
                                static_cast<float>(center.x + offsetY - camera::pos().x),
                                static_cast<float>(center.y + offsetX - camera::pos().y));
            SDL_RenderDrawLineF(renderer, static_cast<float>(center.x - offsetX - camera::pos().x),
                                static_cast<float>(center.y + offsetY - camera::pos().y),
                                static_cast<float>(center.x + offsetX - camera::pos().x),
                                static_cast<float>(center.y + offsetY - camera::pos().y));
            SDL_RenderDrawLineF(renderer, static_cast<float>(center.x - offsetX - camera::pos().x),
                                static_cast<float>(center.y - offsetY - camera::pos().y),
                                static_cast<float>(center.x + offsetX - camera::pos().x),
                                static_cast<float>(center.y - offsetY - camera::pos().y));
            SDL_RenderDrawLineF(renderer, static_cast<float>(center.x - offsetY - camera::pos().x),
                                static_cast<float>(center.y - offsetX - camera::pos().y),
                                static_cast<float>(center.x + offsetY - camera::pos().x),
                                static_cast<float>(center.y - offsetX - camera::pos().y));

            if (d >= offsetX * 2)
            {
                d -= offsetX * 2 + 1;
                offsetX++;
            }
            else if (d < 2 * (radius - offsetY))
            {
                d += offsetY * 2 - 1;
                offsetY--;
            }
            else
            {
                d += 2 * (offsetY - offsetX - 1);
                offsetY--;
                offsetX++;
            }
        }
        return;
    }

    for (int i = 0; i < thickness; i++)
    {
        while (offsetY >= offsetX)
        {
            SDL_RenderDrawPointF(renderer, static_cast<float>(center.x + offsetX - camera::pos().x),
                                 static_cast<float>(center.y + offsetY - camera::pos().y));
            SDL_RenderDrawPointF(renderer, static_cast<float>(center.x + offsetY - camera::pos().x),
                                 static_cast<float>(center.y + offsetX - camera::pos().y));
            SDL_RenderDrawPointF(renderer, static_cast<float>(center.x - offsetX - camera::pos().x),
                                 static_cast<float>(center.y + offsetY - camera::pos().y));
            SDL_RenderDrawPointF(renderer, static_cast<float>(center.x - offsetY - camera::pos().x),
                                 static_cast<float>(center.y + offsetX - camera::pos().y));
            SDL_RenderDrawPointF(renderer, static_cast<float>(center.x + offsetX - camera::pos().x),
                                 static_cast<float>(center.y - offsetY - camera::pos().y));
            SDL_RenderDrawPointF(renderer, static_cast<float>(center.x + offsetY - camera::pos().x),
                                 static_cast<float>(center.y - offsetX - camera::pos().y));
            SDL_RenderDrawPointF(renderer, static_cast<float>(center.x - offsetX - camera::pos().x),
                                 static_cast<float>(center.y - offsetY - camera::pos().y));
            SDL_RenderDrawPointF(renderer, static_cast<float>(center.x - offsetY - camera::pos().x),
                                 static_cast<float>(center.y - offsetX - camera::pos().y));

            if (d >= offsetX * 2)
            {
                d -= offsetX * 2 + 1;
                offsetX++;
            }
            else if (d < 2 * (radius - offsetY))
            {
                d += offsetY * 2 - 1;
                offsetY--;
            }
            else
            {
                d += 2 * (offsetY - offsetX - 1);
                offsetY--;
                offsetX++;
            }
        }
        radius--;
        offsetX = 0.0;
        offsetY = radius;
        d = radius - 1.0f;
    }
}

} // namespace kn::draw