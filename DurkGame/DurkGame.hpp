#pragma once
#define SDL_MAIN_HANDLED

#include <SDL_mixer.h> // FIXME: Remove once dk::mixer implemented.

#include "Clock.hpp"
#include "Texture.hpp"
#include "Math.hpp"
#include "Rect.hpp"
#include "Input.hpp"
#include "Font.hpp"
#include "Character.hpp"
#include "Globals.hpp"
#include "RenderWindow.hpp"


namespace dk {
	void init();

	void quit();
}

