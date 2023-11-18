#pragma once
#define SDL_MAIN_HANDLED

#include <SDL_mixer.h> // FIXME: Remove once dk::mixer implemented.

#include "Character.hpp"
#include "Clock.hpp"
#include "Font.hpp"
#include "Globals.hpp"
#include "Input.hpp"
#include "Math.hpp"
#include "Rect.hpp"
#include "RenderWindow.hpp"
#include "Texture.hpp"
#include "Constants.hpp"


namespace dk {
	void init();

	void quit();
}

