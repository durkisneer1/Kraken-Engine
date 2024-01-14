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
    Clock();
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
    double m_frameTime;
    double m_targetFrameTime;
    double m_deltaTime;
    double m_frequency;
    double m_now;
    double m_last;
};

} // namespace time
} // namespace kn
