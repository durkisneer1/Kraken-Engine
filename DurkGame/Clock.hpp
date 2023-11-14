#pragma once

#include <SDL.h>


namespace dk {
	namespace time {
		class Clock {
		public:
			Clock() = default;
			~Clock() = default;

			float tick(Uint32 frameRate = 0);

		private:
			Uint32 startTick = 0;
			Uint32 endTick = 0;
		};
	}
}
