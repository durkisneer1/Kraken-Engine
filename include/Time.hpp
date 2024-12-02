#pragma once

#include <SDL.h>

namespace kn::time
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
    [[maybe_unused]] double tick(int frameRate = 60);

  private:
    double m_frameTime = 0.0;
    double m_targetFrameTime = 0.0;
    double m_deltaTime = 0.0;
    double m_frequency = static_cast<double>(SDL_GetPerformanceFrequency());
    double m_now = static_cast<double>(SDL_GetPerformanceCounter());
    double m_last = static_cast<double>(SDL_GetPerformanceCounter());
};

/**
 * @brief Get the elapsed time in seconds since Kraken was initialized.
 *
 * @return The elapsed time.
 */
[[nodiscard]] double getTicks();

} // namespace kn::time