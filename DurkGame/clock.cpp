#include "pch.h"
#include "Clock.hpp"


namespace dk {
	namespace time {
		float Clock::tick(Uint32 frameRate) {
			if (frameRate <= 0) return 0.0f;

			endTick = SDL_GetTicks() - startTick;
			Uint32 frameTime = 1000 / frameRate;

			if (endTick < frameTime) {
				Uint32 neutralTicks = frameTime - endTick;
				SDL_Delay(neutralTicks);
				endTick = neutralTicks;
			}

			startTick = SDL_GetTicks();
			return (float)endTick;
		}
	}
}
