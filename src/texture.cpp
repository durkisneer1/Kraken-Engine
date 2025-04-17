#include <SDL_image.h>

#include "Math.hpp"
#include "Surface.hpp"
#include "Texture.hpp"
#include "Window.hpp"

namespace kn
{
Texture::Texture(const std::string& filePath)
{
    if (!loadFromFile(filePath))
        throw Exception("Failed to load texture from: " + filePath);
}

Texture::Texture(const math::Vec2& size, const Color color)
{
    if (!create(size, color))
        throw Exception("Failed to create texture");
}

Texture::Texture(const void* pixelData, const math::Vec2& size, int depth)
{
    if (!loadFromArray(pixelData, size, depth))
        throw Exception("Failed to load texture from pixel data");
}

Texture::Texture(SDL_Texture* sdlTexture) : texture(sdlTexture) {}

Texture::Texture(const Surface& surface)
{
    if (!loadFromSurface(surface))
        throw Exception("Failed to load texture from surface");
}

Texture::~Texture()
{
    if (texture)
        SDL_DestroyTexture(texture);
}

bool Texture::loadFromFile(const std::string& filePath)
{
    if (texture)
    {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }

    texture = IMG_LoadTexture(window::getRenderer(), filePath.c_str());
    if (!texture)
    {
        WARN("Failed to create texture from: " + filePath);
        return false;
    }

    return true;
}

bool Texture::create(const math::Vec2& size, const Color color)
{
    if (texture)
    {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }

    SDL_Surface* surface = SDL_CreateRGBSurfaceWithFormat(
        0, static_cast<int>(size.x), static_cast<int>(size.y), 32, SDL_PIXELFORMAT_RGBA8888);

    if (!surface)
    {
        WARN("Failed to create surface")
        return false;
    }

    SDL_FillRect(surface, nullptr,
                 SDL_MapRGBA(surface->format, color.r, color.g, color.b, color.a));

    if (color.a == 255)
    {
        texture = SDL_CreateTextureFromSurface(window::getRenderer(), surface);
    }
    else
    {
        texture = SDL_CreateTextureFromSurface(window::getRenderer(), surface);
        SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
    }

    if (!texture)
    {
        WARN("Failed to create texture from surface");
        return false;
    }

    SDL_FreeSurface(surface);

    return true;
}

bool Texture::loadFromArray(const void* pixelData, const math::Vec2& size, int depth)
{
    if (texture)
    {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }

    if (depth == 32)
    {
        texture = SDL_CreateTexture(window::getRenderer(), SDL_PIXELFORMAT_RGBA8888,
                                    SDL_TEXTUREACCESS_STATIC, static_cast<int>(size.x),
                                    static_cast<int>(size.y));
        SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
    }
    else if (depth == 24)
    {
        texture = SDL_CreateTexture(window::getRenderer(), SDL_PIXELFORMAT_RGB24,
                                    SDL_TEXTUREACCESS_STATIC, static_cast<int>(size.x),
                                    static_cast<int>(size.y));
    }
    else
    {
        WARN("Unsupported pixel depth: " + std::to_string(depth));
        return false;
    }

    if (!texture)
    {
        WARN("Failed to create texture from pixel data");
        return false;
    }

    if (SDL_UpdateTexture(texture, nullptr, pixelData, size.x * depth / 8) != 0)
    {
        WARN("Failed to update texture with pixel data");
        return false;
    }

    return true;
}

bool Texture::loadFromSurface(const Surface& surface)
{
    if (!surface.getSDL())
    {
        WARN("Surface is null");
        return false;
    }

    if (texture)
    {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }

    texture = SDL_CreateTextureFromSurface(window::getRenderer(), surface.getSDL());
    if (!texture)
    {
        WARN("Failed to create texture from surface");
        return false;
    }

    return true;
}

math::Vec2 Texture::getSize() const
{
    int w, h;
    SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);
    return {w, h};
}

Rect Texture::getRect() const
{
    int w, h;
    SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);
    return {0, 0, w, h};
}

void Texture::setColorMod(Color colorMod) const
{
    SDL_SetTextureColorMod(texture, colorMod.r, colorMod.g, colorMod.b);
}

Color Texture::getColorMod() const
{
    Color colorMod;
    SDL_GetTextureColorMod(texture, &colorMod.r, &colorMod.g, &colorMod.b);
    return colorMod;
}

void Texture::setAlphaMod(uint8_t alphaMod) const { SDL_SetTextureAlphaMod(texture, alphaMod); }

uint8_t Texture::getAlphaMod() const
{
    uint8_t alphaMod;
    SDL_GetTextureAlphaMod(texture, &alphaMod);
    return alphaMod;
}

SDL_Texture* Texture::getSDL() const { return texture; }

} // namespace kn
