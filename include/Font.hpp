#pragma once

#include <memory>
#include <string>

#include <SDL.h>
#include <SDL_ttf.h>

#include "Texture.hpp"

namespace kn
{

/**
 * @brief A class to render text.
 */
class Font final
{
  public:
    /**
     * @brief Create a font.
     *
     * @param fileDir The directory of the font file.
     * @param ptSize The point size of the font.
     */
    Font(const std::string& fileDir, int ptSize);
    ~Font()
    {
        if (font)
            TTF_CloseFont(font);
    }

    /**
     * @brief Render text.
     *
     * @param text The text to render.
     * @param antialias Whether to antialias the text.
     * @param color The color of the text.
     * @param wrapLength The length to wrap the text.
     *
     * @return The rendered text.
     */
    std::shared_ptr<Texture> render(const std::string& text, bool antialias, SDL_Color color,
                                    int wrapLength = 0);

  private:
    TTF_Font* font;
};

} // namespace kn
