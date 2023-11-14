#include "pch.h"
#include "Clock.hpp"


namespace dk {
	namespace time {
		float Clock::tick(uint32_t frameRate) {
			if (frameRate <= 0) return 0.0f;

			endTick = SDL_GetTicks() - startTick;
			uint32_t frameTime = 1000 / frameRate;

			if (endTick < frameTime) {
				uint32_t neutralTicks = frameTime - endTick;
				SDL_Delay(neutralTicks);
				endTick = neutralTicks;
			}

			startTick = SDL_GetTicks();
			return (float) endTick;
		}
	}
}
