#include "Transform.hpp"
#include "Math.hpp"
#include "Surface.hpp"

#include <algorithm>
#include <gfx/SDL2_rotozoom.h>
#include <vector>

namespace kn
{
namespace transform
{

Surface flip(const Surface& surface, bool flipX, bool flipY)
{
    SDL_Surface* src = surface.getSDL();
    if (!src)
        throw Exception("Cannot flip a null surface.");

    SDL_Surface* flipped =
        SDL_CreateRGBSurfaceWithFormat(0, src->w, src->h, 32, SDL_PIXELFORMAT_RGBA32);

    if (!flipped)
        throw Exception("Failed to create flipped surface.");

    SDL_LockSurface(src);
    SDL_LockSurface(flipped);

    int bpp = src->format->BytesPerPixel;

    for (int y = 0; y < src->h; ++y)
    {
        for (int x = 0; x < src->w; ++x)
        {
            int srcX = flipX ? (src->w - 1 - x) : x;
            int srcY = flipY ? (src->h - 1 - y) : y;

            Uint8* srcPixel = (Uint8*)src->pixels + srcY * src->pitch + srcX * bpp;
            Uint8* dstPixel = (Uint8*)flipped->pixels + y * flipped->pitch + x * bpp;

            memcpy(dstPixel, srcPixel, bpp);
        }
    }

    SDL_UnlockSurface(src);
    SDL_UnlockSurface(flipped);

    Surface result(flipped);
    return result;
}

Surface scale(const Surface& surface, const math::Vec2& newSize)
{
    SDL_Surface* src = surface.getSDL();
    if (!src)
        throw Exception("Cannot scale a null surface.");

    int newW = static_cast<int>(newSize.x);
    int newH = static_cast<int>(newSize.y);

    SDL_Surface* scaled = SDL_CreateRGBSurfaceWithFormat(0, newW, newH, 32, SDL_PIXELFORMAT_RGBA32);
    if (!scaled)
        throw Exception("Failed to create scaled surface.");

    SDL_Rect destRect = {0, 0, newW, newH};
    if (SDL_BlitScaled(src, nullptr, scaled, &destRect) < 0)
    {
        SDL_FreeSurface(scaled);
        throw Exception("SDL_BlitScaled failed: " + std::string(SDL_GetError()));
    }

    Surface result(scaled);
    return result;
}

Surface scaleBy(const Surface& surface, double factor)
{
    if (factor <= 0.0)
        throw Exception("Scale factor must be positive.");

    math::Vec2 originalSize = surface.getSize();
    math::Vec2 scaledSize = originalSize * factor;

    return scale(surface, scaledSize);
}

Surface rotate(const Surface& surface, double angle)
{
    SDL_Surface* src = surface.getSDL();
    if (!src)
        throw Exception("Cannot rotate a null surface.");

    SDL_Surface* rotated = rotozoomSurface(src, angle, 1.0, SMOOTHING_OFF); // rotate, don't scale

    if (!rotated)
        throw Exception("Failed to rotate surface.");

    Surface result(rotated);
    return result;
}

Surface boxBlur(const Surface& surface, int radius, bool repeatEdgePixels)
{
    if (radius <= 0)
        return surface;

    SDL_Surface* src = surface.getSDL();
    if (!src)
        throw Exception("Cannot blur a null surface.");

    const int w = src->w, h = src->h;
    Uint32 fmt = src->format->format;
    int bpp = src->format->BitsPerPixel;
    int diameter = radius * 2 + 1;

    SDL_Surface* temp = SDL_CreateRGBSurfaceWithFormat(0, w, h, bpp, fmt);
    SDL_Surface* result = SDL_CreateRGBSurfaceWithFormat(0, w, h, bpp, fmt);
    if (!temp || !result)
        throw Exception("Failed to create temporary surfaces for blur.");

    SDL_LockSurface(src);
    SDL_LockSurface(temp);
    SDL_LockSurface(result);

    auto clamp = [](int v, int lo, int hi) { return std::max(lo, std::min(v, hi)); };

    Uint32* srcPx = static_cast<Uint32*>(src->pixels);
    Uint32* tmpPx = static_cast<Uint32*>(temp->pixels);
    Uint32* dstPx = static_cast<Uint32*>(result->pixels);

    // Horizontal
    for (int y = 0; y < h; ++y)
    {
        for (int x = 0; x < w; ++x)
        {
            int r = 0, g = 0, b = 0, a = 0;
            for (int dx = -radius; dx <= radius; ++dx)
            {
                int sx = repeatEdgePixels ? clamp(x + dx, 0, w - 1) : x + dx;
                if (sx < 0 || sx >= w)
                    continue;
                Uint8 pr, pg, pb, pa;
                SDL_GetRGBA(srcPx[y * w + sx], src->format, &pr, &pg, &pb, &pa);
                r += pr;
                g += pg;
                b += pb;
                a += pa;
            }
            r /= diameter;
            g /= diameter;
            b /= diameter;
            a /= diameter;
            tmpPx[y * w + x] = SDL_MapRGBA(temp->format, r, g, b, a);
        }
    }

    // Vertical
    for (int y = 0; y < h; ++y)
    {
        for (int x = 0; x < w; ++x)
        {
            int r = 0, g = 0, b = 0, a = 0;
            for (int dy = -radius; dy <= radius; ++dy)
            {
                int sy = repeatEdgePixels ? clamp(y + dy, 0, h - 1) : y + dy;
                if (sy < 0 || sy >= h)
                    continue;
                Uint8 pr, pg, pb, pa;
                SDL_GetRGBA(tmpPx[sy * w + x], temp->format, &pr, &pg, &pb, &pa);
                r += pr;
                g += pg;
                b += pb;
                a += pa;
            }
            r /= diameter;
            g /= diameter;
            b /= diameter;
            a /= diameter;
            dstPx[y * w + x] = SDL_MapRGBA(result->format, r, g, b, a);
        }
    }

    SDL_UnlockSurface(src);
    SDL_UnlockSurface(temp);
    SDL_UnlockSurface(result);
    SDL_FreeSurface(temp);

    return Surface(result);
}

Surface gaussianBlur(const Surface& surface, int radius, bool repeatEdgePixels)
{
    if (radius <= 0)
        return surface;

    SDL_Surface* src = surface.getSDL();
    if (!src)
        throw Exception("Cannot blur a null surface.");

    const int w = src->w, h = src->h;
    Uint32 fmt = src->format->format;
    int bpp = src->format->BitsPerPixel;
    int diameter = radius * 2 + 1;

    // Build Gaussian kernel (σ = radius/2)
    float sigma = radius > 0 ? (radius / 2.0f) : 1.0f;
    float twoSigmaSq = 2.0f * sigma * sigma;
    float invSigmaRoot = 1.0f / (std::sqrt(2.0f * M_PI) * sigma);
    std::vector<float> kernel(diameter);
    for (int i = 0; i < diameter; ++i)
    {
        int x = i - radius;
        kernel[i] = invSigmaRoot * std::exp(-(x * x) / twoSigmaSq);
    }
    // Normalize
    float sum = 0;
    for (float v : kernel)
        sum += v;
    for (float& v : kernel)
        v /= sum;

    // Create intermediate and output surfaces
    SDL_Surface* temp = SDL_CreateRGBSurfaceWithFormat(0, w, h, bpp, fmt);
    SDL_Surface* result = SDL_CreateRGBSurfaceWithFormat(0, w, h, bpp, fmt);
    if (!temp || !result)
        throw Exception("Failed to create surfaces for Gaussian blur.");

    SDL_LockSurface(src);
    SDL_LockSurface(temp);
    SDL_LockSurface(result);

    auto clamp = [](int v, int lo, int hi) { return std::max(lo, std::min(v, hi)); };
    Uint32* srcPx = static_cast<Uint32*>(src->pixels);
    Uint32* tmpPx = static_cast<Uint32*>(temp->pixels);
    Uint32* dstPx = static_cast<Uint32*>(result->pixels);

    // Horizontal pass
    for (int y = 0; y < h; ++y)
    {
        for (int x = 0; x < w; ++x)
        {
            float fr = 0, fg = 0, fb = 0, fa = 0;
            for (int k = 0; k < diameter; ++k)
            {
                int sx = x + (k - radius);
                if (repeatEdgePixels)
                    sx = clamp(sx, 0, w - 1);
                if (sx < 0 || sx >= w)
                    continue;
                Uint8 pr, pg, pb, pa;
                SDL_GetRGBA(srcPx[y * w + sx], src->format, &pr, &pg, &pb, &pa);
                fr += pr * kernel[k];
                fg += pg * kernel[k];
                fb += pb * kernel[k];
                fa += pa * kernel[k];
            }
            tmpPx[y * w + x] =
                SDL_MapRGBA(temp->format, static_cast<Uint8>(fr), static_cast<Uint8>(fg),
                            static_cast<Uint8>(fb), static_cast<Uint8>(fa));
        }
    }

    // Vertical pass
    for (int y = 0; y < h; ++y)
    {
        for (int x = 0; x < w; ++x)
        {
            float fr = 0, fg = 0, fb = 0, fa = 0;
            for (int k = 0; k < diameter; ++k)
            {
                int sy = y + (k - radius);
                if (repeatEdgePixels)
                    sy = clamp(sy, 0, h - 1);
                if (sy < 0 || sy >= h)
                    continue;
                Uint8 pr, pg, pb, pa;
                SDL_GetRGBA(tmpPx[sy * w + x], temp->format, &pr, &pg, &pb, &pa);
                fr += pr * kernel[k];
                fg += pg * kernel[k];
                fb += pb * kernel[k];
                fa += pa * kernel[k];
            }
            dstPx[y * w + x] =
                SDL_MapRGBA(result->format, static_cast<Uint8>(fr), static_cast<Uint8>(fg),
                            static_cast<Uint8>(fb), static_cast<Uint8>(fa));
        }
    }

    SDL_UnlockSurface(src);
    SDL_UnlockSurface(temp);
    SDL_UnlockSurface(result);
    SDL_FreeSurface(temp);

    return Surface(result);
}

Surface invert(const Surface& surface)
{
    SDL_Surface* src = surface.getSDL();
    if (!src)
        throw Exception("Cannot invert a null surface.");

    const int w = src->w, h = src->h;
    Uint32 fmt = src->format->format;
    int bpp = src->format->BitsPerPixel;

    // Create an output surface matching the source format
    SDL_Surface* result = SDL_CreateRGBSurfaceWithFormat(0, w, h, bpp, fmt);
    if (!result)
        throw Exception("Failed to create surface for invert.");

    SDL_LockSurface(src);
    SDL_LockSurface(result);

    Uint32* srcPx = static_cast<Uint32*>(src->pixels);
    Uint32* dstPx = static_cast<Uint32*>(result->pixels);

    for (int i = 0; i < w * h; ++i)
    {
        Uint8 r, g, b, a;
        SDL_GetRGBA(srcPx[i], src->format, &r, &g, &b, &a);

        // Invert only color channels
        Uint8 ir = 255 - r;
        Uint8 ig = 255 - g;
        Uint8 ib = 255 - b;

        dstPx[i] = SDL_MapRGBA(result->format, ir, ig, ib, a);
    }

    SDL_UnlockSurface(src);
    SDL_UnlockSurface(result);

    return Surface(result);
}

Surface grayscale(const Surface& surface)
{
    SDL_Surface* src = surface.getSDL();
    if (!src)
        throw Exception("Cannot grayscale a null surface.");

    const int w = src->w;
    const int h = src->h;
    Uint32 fmt = src->format->format;
    int bpp = src->format->BitsPerPixel;

    // Create output surface matching the source format
    SDL_Surface* result = SDL_CreateRGBSurfaceWithFormat(0, w, h, bpp, fmt);
    if (!result)
        throw Exception("Failed to create surface for grayscale.");

    SDL_LockSurface(src);
    SDL_LockSurface(result);

    Uint32* srcPx = static_cast<Uint32*>(src->pixels);
    Uint32* dstPx = static_cast<Uint32*>(result->pixels);

    for (int i = 0; i < w * h; ++i)
    {
        Uint8 r, g, b, a;
        SDL_GetRGBA(srcPx[i], src->format, &r, &g, &b, &a);

        // luminance formula: 0.299 R + 0.587 G + 0.114 B
        Uint8 gray = static_cast<Uint8>(0.299f * r + 0.587f * g + 0.114f * b);

        dstPx[i] = SDL_MapRGBA(result->format, gray, gray, gray, a);
    }

    SDL_UnlockSurface(src);
    SDL_UnlockSurface(result);

    return Surface(result);
}

} // namespace transform
} // namespace kn
