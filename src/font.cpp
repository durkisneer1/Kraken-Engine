#include "Font.hpp"
#include "ErrorLogger.hpp"
#include "Texture.hpp"
#include "Window.hpp"

namespace kn
{
Font::~Font()
{
    if (font)
        TTF_CloseFont(font);
}

bool Font::openFromFile(const std::string& fileDir, const int ptSize)
{
    font = TTF_OpenFont(fileDir.c_str(), ptSize);
    return font != nullptr;
}

Texture Font::render(const std::string& text, const bool antialias, const Color color,
                     const int wrapLength) const
{
    if (!font)
        return {};

    SDL_Surface* surface;

    if (antialias)
    {
        surface = wrapLength > 0
                      ? TTF_RenderUTF8_Blended_Wrapped(font, text.c_str(), color, wrapLength)
                      : TTF_RenderUTF8_Blended(font, text.c_str(), color);
    }
    else
    {
        surface = wrapLength > 0
                      ? TTF_RenderText_Solid_Wrapped(font, text.c_str(), color, wrapLength)
                      : TTF_RenderText_Solid(font, text.c_str(), color);
    }

    if (!surface)
        FATAL("Failed to render text: " + std::string(TTF_GetError()));

    SDL_Texture* sdlTexture = SDL_CreateTextureFromSurface(window::getRenderer(), surface);
    if (!sdlTexture)
        FATAL("Failed to create texture: " + std::string(SDL_GetError()));

    SDL_FreeSurface(surface);

    return Texture(sdlTexture);
}
} // namespace kn
