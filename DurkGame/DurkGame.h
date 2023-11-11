#pragma once
#define SDL_MAIN_HANDLED

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "DK_Display.h"
#include "DK_Clock.h"
#include "DK_Texture.h"
#include "DK_Math.h"
#include "DK_Rect.h"
#include "DK_Input.h"
#include "DK_Font.h"
#include "DK_Character.h"
#include "DK_Globals.h"
#include "DK_Surface.h"


namespace dk {
	void init();

	void quit(SDL_Window* window, SDL_Renderer* renderer);
}

