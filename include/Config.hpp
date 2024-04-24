#pragma once

#if defined(_WIN64)
#   define KN_SDL_PATH <SDL.h>
#   define KN_IMG_PATH <SDL_image.h>
#   define KN_TTF_PATH <SDL_ttf.h>
#   define KN_MIX_PATH <SDL_mixer.h>
#else
#   define KN_SDL_PATH <SDL2/SDL.h>
#   define KN_IMG_PATH <SDL2/SDL_image.h>
#   define KN_TTF_PATH <SDL2/SDL_ttf.h>
#   define KN_MIX_PATH <SDL2/SDL_mixer.h>
#endif