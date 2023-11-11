#include "pch.h"
#include "DK_Clock.h"


namespace dk {
	namespace time {
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
			return (float)endTicks;
		}
	}
}
