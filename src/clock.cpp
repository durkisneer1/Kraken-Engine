#include "../include/Clock.hpp"


namespace DK_Time {
	float Clock::tick(int frameRate) {
		endTicks = SDL_GetTicks() - startTicks;
		if (frameRate > 0) {
			int frameDelay = 1000 / frameRate;
			if (endTicks < frameDelay) {
				Uint32 neutralTicks = frameDelay - endTicks;
				SDL_Delay(neutralTicks);
				endTicks = neutralTicks;
			}
		}
		startTicks = SDL_GetTicks();
		return (float) endTicks;
	}
}
