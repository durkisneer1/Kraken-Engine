#pragma once
#define SDL_MAIN_HANDLED

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "Display.hpp"
#include "Clock.hpp"
#include "Texture.hpp"
#include "Math.hpp"
#include "Rect.hpp"
#include "Input.hpp"
#include "Font.hpp"
#include "Character.hpp"
#include "Globals.hpp"


void DK_Init();
void DK_Quit(SDL_Window *window, SDL_Renderer *renderer);
