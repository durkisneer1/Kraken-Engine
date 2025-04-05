#pragma once

#include <SDL.h>

namespace kn
{
namespace time
{

class Clock final
{
  public:
    Clock() = default;
    ~Clock() = default;

    /**
     * @brief Get the delta time between frames in milliseconds.
     *
     * @param frameRate The frame rate to cap the program at.
     *
     * @return The delta time between frames.
     */
    [[maybe_unused]] double tick(int frameRate = 60);

  private:
    double m_frameTime = 0.0;
    double m_targetFrameTime = 0.0;
    double m_frequency = static_cast<double>(SDL_GetPerformanceFrequency());
    double m_now = static_cast<double>(SDL_GetPerformanceCounter());
    double m_last = m_now;
};

/**
 * @brief Get the elapsed time in seconds since Kraken was initialized.
 *
 * @return The elapsed time.
 */
[[nodiscard]] double getTicks();

} // namespace time
using time::Clock;
} // namespace kn