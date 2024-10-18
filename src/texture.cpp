#include <SDL_image.h>

#include "Math.hpp"
#include "Texture.hpp"
#include "Window.hpp"

namespace kn
{
Texture::Texture(const std::string& path)
{
    texture = IMG_LoadTexture(window::getRenderer(), path.c_str());
    if (!texture)
        WARN("Failed to create texture from: " + path);

    query();
}

Texture::Texture(const math::Vec2& size, const Color color)
{
    SDL_Surface* surface =
        SDL_CreateRGBSurface(0, static_cast<int>(size.x), static_cast<int>(size.y), 32, 0, 0, 0, 0);
    if (!surface)
        WARN("Failed to create surface")
    else
        SDL_FillRect(surface, nullptr,
                     SDL_MapRGBA(surface->format, color.r, color.g, color.b, color.a));

    texture = SDL_CreateTextureFromSurface(window::getRenderer(), surface);
    if (!texture)
        WARN("Failed to create texture from surface");

    SDL_FreeSurface(surface);

    query();
}

Texture::Texture(SDL_Texture* sdlTexture) : texture(sdlTexture) { query(); }

void Texture::query()
{
    int w, h;
    SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);
    this->rect = {0, 0, w, h};
}

math::Vec2 Texture::getSize() const { return {rect.w, rect.h}; }

Rect Texture::getRect() const { return rect; }

SDL_Texture* Texture::getSDLTexture() const { return texture; }

void Texture::setSize(const math::Vec2& size)
{
    rect.w = static_cast<float>(size.x);
    rect.h = static_cast<float>(size.y);
}

void Texture::scaleBy(const float factor)
{
    rect.w = rect.w * factor;
    rect.h = rect.h * factor;
}

void Texture::fitWidth(const float width)
{
    const float scale = width / rect.w;
    rect.w = width;
    rect.h = rect.h * scale;
}

void Texture::fitHeight(const float height)
{
    const float scale = height / rect.h;
    rect.w = rect.w * scale;
    rect.h = height;
}
} // namespace kn
