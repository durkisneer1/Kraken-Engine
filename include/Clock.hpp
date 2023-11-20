#pragma once

#include <SDL.h>


namespace dk {
	namespace time {
		class Clock {
		public:
			Clock() = default;
			~Clock() = default;

			double tick(int frameRate = 360);

		private:
			uint64_t now, last = SDL_GetTicks64();
			uint64_t rawTime, frameTime = 0;
		};
	}
}
