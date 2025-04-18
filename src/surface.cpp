#include "Surface.hpp"
#include "ErrorLogger.hpp"
#include "Math.hpp"
#include "Rect.hpp"
#include <SDL_image.h>

using namespace kn;

Surface::Surface(const math::Vec2& size)
{
    if (!create(size))
    {
        throw Exception("Failed to create surface of size " + std::to_string(size.x) + "x" +
                        std::to_string(size.y));
    }
}

Surface::Surface(const std::string& filePath)
{
    if (!loadFromFile(filePath))
    {
        throw Exception("Failed to load surface from file: " + filePath);
    }
}

Surface::Surface(SDL_Surface* sdlSurface)
{
    if (!loadFromSDL(sdlSurface))
    {
        throw Exception("Failed to load surface from SDL_Surface pointer");
    }
}

Surface::~Surface()
{
    if (surface)
    {
        SDL_FreeSurface(surface);
        surface = nullptr;
    }
}

bool Surface::loadFromFile(const std::string& filePath)
{
    SDL_Surface* raw = IMG_Load(filePath.c_str());
    if (!raw)
        return false;

    SDL_Surface* converted = SDL_ConvertSurfaceFormat(raw, SDL_PIXELFORMAT_RGBA32, 0);
    SDL_FreeSurface(raw);

    if (!converted)
        return false;

    if (surface)
        SDL_FreeSurface(surface);

    surface = converted;

    return true;
}

bool Surface::create(const math::Vec2& size)
{
    if (surface)
        SDL_FreeSurface(surface);

    surface = SDL_CreateRGBSurfaceWithFormat(0, static_cast<int>(size.x), static_cast<int>(size.y),
                                             32, SDL_PIXELFORMAT_RGBA32);
    return surface != nullptr;
}

bool Surface::loadFromSDL(SDL_Surface* sdlSurface)
{
    if (surface)
        SDL_FreeSurface(surface);

    surface = SDL_ConvertSurfaceFormat(sdlSurface, SDL_PIXELFORMAT_RGBA32, 0);
    return surface != nullptr;
}

void Surface::fill(Color color)
{
    uint32_t colorMap = SDL_MapRGBA(surface->format, color.r, color.g, color.b, color.a);
    SDL_FillRect(surface, nullptr, colorMap);
}

math::Vec2 Surface::getSize() const { return {surface->w, surface->h}; }

Rect Surface::getRect() const { return {0, 0, surface->w, surface->h}; }

SDL_Surface* Surface::getSDL() const { return surface; }