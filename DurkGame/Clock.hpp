#pragma once

#include <SDL.h>
#include <stdint.h>


namespace dk {
	namespace time {
		class Clock {
		public:
			Clock() = default;
			~Clock() = default;

			float tick(uint32_t frameRate = 0);

		private:
			uint32_t startTick = 0;
			uint32_t endTick = 0;
		};
	}
}
