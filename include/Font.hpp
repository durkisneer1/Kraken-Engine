#pragma once

#include <SDL_ttf.h>
#include <string>

#include "Constants.hpp"

namespace kn
{
class Texture;

/**
 * @brief A class to render text.
 */
class Font final
{
  public:
    /**
     * @brief Create a font object.
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
     * @brief Generate a texture with rendered text.
     *
     * @param text The text to render.
     * @param antialias Whether to antialias the text.
     * @param color The color of the text.
     * @param wrapLength The length to wrap the text.
     * If 0, the text will not be wrapped.
     *
     * @return The generated texture object.
     *
     * @note Do not confuse this with rendering text to the screen.
     */
    [[nodiscard]] Texture render(const std::string& text, bool antialias, Color color,
                                 int wrapLength = 0) const;

  private:
    TTF_Font* font;
};
} // namespace kn
