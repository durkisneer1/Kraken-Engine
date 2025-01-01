#pragma once

#include <SDL_ttf.h>
#include <string>

#include "Constants.hpp"

namespace kn
{
class Texture;

class Font final
{
  public:
    Font() = default;
    ~Font();

    /**
     * @brief Open a font from a file.
     * @param fileDir The directory of the font file.
     * @param ptSize The point size of the font.
     * @return ``true`` if the font was opened successfully, ``false`` otherwise.
     */
    [[maybe_unused]] bool openFromFile(const std::string& fileDir, int ptSize);

    /**
     * @brief Generate a texture with rendered text.
     *
     * @param text The text to render.
     * @param antialias Whether to antialias the text.
     * @param color The color of the text.
     * @param wrapLength The length to wrap the text. If ``0``, the text will not be wrapped.
     *
     * @return The generated texture object.
     * If a font has not been opened, an empty texture will be returned.
     */
    [[nodiscard]] Texture render(const std::string& text, bool antialias, Color color,
                                 int wrapLength = 0) const;

  private:
    TTF_Font* font;
};
} // namespace kn
