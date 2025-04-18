#pragma once

#include <SDL.h>
#include <chrono>

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
     * @brief Get the delta time from the last frame in seconds.
     *
     * @param frameRate The frame rate to cap the program at.
     *
     * @return The delta time between frames.
     */
    [[maybe_unused]] double tick(int frameRate = 60);

    /**
     * @brief Get the current count of frames per second.
     *
     * @return The current FPS.
     */
    [[nodiscard]] int getFPS();

  private:
    const double m_frequency = static_cast<double>(SDL_GetPerformanceFrequency());
    double m_last = static_cast<double>(SDL_GetPerformanceCounter());
    int m_fps = 0;
};

class Timer
{
  public:
    /**
     * @brief Create a timer with a specified duration in seconds.
     *
     * @param duration The duration of the timer in seconds.
     * If the duration is negative, it will be set to 0.
     */
    explicit Timer(double duration);
    ~Timer() = default;

    /**
     * @brief Start the timer.
     * This will also reset the timer.
     */
    void start();

    /**
     * @brief Pause the timer.
     */
    void pause();

    /**
     * @brief Resume the timer.
     */
    void resume();

    /**
     * @brief Check if the timer is done counting down.
     *
     * @return ``true`` if the timer is finished, ``false`` otherwise.
     */
    [[nodiscard]] bool isFinished() const;

    /**
     * @brief Get the remaining time in seconds.
     *
     * @return The remaining time in seconds.
     */
    [[nodiscard]] double timeRemaining() const;

  private:
    double m_duration;
    bool m_started = false;
    bool m_paused = false;
    std::chrono::steady_clock::time_point m_startTime;
    std::chrono::steady_clock::time_point m_pauseTime;
    double m_elapsedPausedTime = 0.0;
};

/**
 * @brief Get the elapsed time in seconds since Kraken was initialized.
 *
 * @return The elapsed time.
 */
[[nodiscard]] double getTicks();

} // namespace time
using time::Clock;
using time::Timer;
} // namespace kn
