#pragma once

#include <SDL.h>


namespace kn {
	namespace time {
		/// @brief A class to keep track of time.
		/// @note This class is not thread-safe.
		class Clock final {
		public:
			Clock() = default;
			~Clock() = default;

			/// @brief Get the delta time between frames.
			/// @param frameRate The frame rate to calculate the delta time.
			/// @return The delta time between frames.
			double tick(int frameRate = 360);

		private:
			uint64_t now, last = SDL_GetTicks64();
			uint64_t rawTime, frameTime = 0;
		};
	}
}
