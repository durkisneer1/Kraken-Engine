#pragma once

#include <SDL.h>

namespace kn
{
namespace time
{

/**
 * @brief A class to keep track of time.
 *
 * @warning This class is planned to become a singleton.
 */
class Clock final
{
  public:
    Clock() = default;
    ~Clock() = default;

    /**
     * @brief Get the delta time between frames.
     *
     * @param frameRate The frame rate to calculate the delta time.
     *
     * @return The delta time between frames.
     */
    double tick(int frameRate = 60);

  private:
    double frameTime, targetFrameTime, deltaTime;
    double frequency = SDL_GetPerformanceFrequency();
    double now, last = SDL_GetPerformanceCounter();
};

} // namespace time
} // namespace kn
