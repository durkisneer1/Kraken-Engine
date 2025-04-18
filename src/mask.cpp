#include "Mask.hpp"
#include "ErrorLogger.hpp"
#include "Math.hpp"
#include "Rect.hpp"
#include "Surface.hpp"

using namespace kn;

Mask::Mask(const Surface& surface, uint8_t alphaThreshold)
    : width(surface.getSize().x), height(surface.getSize().y), maskData(width * height, false)
{
    SDL_Surface* rawSurface = surface.getSDL();
    if (!rawSurface)
        throw Exception("Surface is null");

    const auto* pixels = static_cast<uint8_t*>(rawSurface->pixels);
    const int pitch = rawSurface->pitch;

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            const Uint8* pixel = pixels + y * pitch + x * 4; // 4 bytes per pixel, RGBA32
            maskData[y * width + x] = (pixel[3] >= alphaThreshold);
        }
    }
}

bool Mask::getPixel(int x, int y) const
{
    if (x < 0 || x >= width || y < 0 || y >= height)
        return false;

    return maskData[y * width + x];
}

bool Mask::collideMask(const Mask& other, const math::Vec2& offset) const
{
    int xOffset = static_cast<int>(offset.x);
    int yOffset = static_cast<int>(offset.y);

    int xStart = std::max(0, -xOffset);
    int yStart = std::max(0, -yOffset);
    int xEnd = std::min(width, other.width - xOffset);
    int yEnd = std::min(height, other.height - yOffset);

    if (xStart >= xEnd || yStart >= yEnd)
        return false; // No overlap

    for (int y = yStart; y < yEnd; ++y)
        for (int x = xStart; x < xEnd; ++x)
            if (getPixel(x, y) && other.getPixel(x + xOffset, y + yOffset))
                return true;

    return false;
}

bool Mask::collideMask(const Mask& other, const Rect& rectA, const Rect& rectB) const
{
    return collideMask(other, rectA.topLeft() - rectB.topLeft());
}
