#include "../include/Clock.hpp"


namespace kn {
	namespace time {
		double Clock::tick(int frameRate) {

			if (frameRate) {
				double targetFrameTime = 1000.0 / frameRate;
				rawTime = SDL_GetTicks64() - last;
				double delay = targetFrameTime - rawTime;

				if (delay > 0) SDL_Delay((uint32_t)delay);
			} else {}

			now = SDL_GetTicks64();
			frameTime = now - last;
			last = now;

			if (!frameRate) rawTime = frameTime;

			return double(frameTime) / 1000.0;
		}
	}
}
