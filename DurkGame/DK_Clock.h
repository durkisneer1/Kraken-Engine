#pragma once

#include <SDL.h>


namespace dk {
	namespace time {
		class Clock {
		public:
			Clock() = default;
			~Clock() = default;

			float tick(int frameRate = 0);

		private:
			Uint32 startTicks = 0;
			Uint32 endTicks = 0;
		};
	}
}
