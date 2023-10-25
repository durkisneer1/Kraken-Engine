#pragma once
#include <SDL.h>


namespace DK_Time {
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