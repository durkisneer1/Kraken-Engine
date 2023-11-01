#include "../include/Font.hpp"


SDL_Surface* DK_Font::render(const char* text, SDL_Color color, int wrapLength) {
    if (wrapLength > 0) {
        return TTF_RenderText_Solid_Wrapped(font, text, color, wrapLength);
    }
    return TTF_RenderText_Solid(font, text, color);
}