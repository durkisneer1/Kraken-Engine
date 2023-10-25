#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "Display.hpp"
#include "Clock.hpp"

void DK_Init();
void DK_Quit(SDL_Window* window, SDL_Renderer* renderer);
