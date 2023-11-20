#pragma once
#define SDL_MAIN_HANDLED

#include <SDL_mixer.h> // FIXME: Remove once dk::mixer implemented.

#include "Clock.hpp"
#include "Constants.hpp"
#include "Font.hpp"
#include "Globals.hpp"
#include "Input.hpp"
#include "Math.hpp"
#include "Rect.hpp"
#include "RenderWindow.hpp"
#include "SpriteCharacter.hpp"
#include "SpriteNode.hpp"
#include "Texture.hpp"


namespace dk {
	void init();

	void quit();
}

