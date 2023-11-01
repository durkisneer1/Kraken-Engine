#pragma once

#include <SDL.h>
#include <SDL_ttf.h>


class DK_Font {
public:
    DK_Font() = default;
    DK_Font(TTF_Font* font, int ptSize) : font(font) {}

    SDL_Surface* render(const char* text, SDL_Color color, int wrapLength = 0);

    ~DK_Font() { TTF_CloseFont(font); }
private:
    TTF_Font* font;
};