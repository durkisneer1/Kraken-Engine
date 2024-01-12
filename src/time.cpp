#include "Time.hpp"
#include "Math.hpp"

namespace kn
{
namespace time
{

double Clock::tick(int frameRate)
{
	if (frameRate < 1)
		frameRate = 1;

	targetFrameTime = 1000.0 / frameRate;
	frameTime = ((SDL_GetPerformanceCounter() / frequency) - (last / frequency)) * 1000.0;
	if (frameTime < targetFrameTime)
		SDL_Delay((uint32_t)(targetFrameTime - frameTime));

	now = SDL_GetPerformanceCounter();
	deltaTime = (now / frequency) - (last / frequency);
	last = now;

	return deltaTime;
}

}
}
