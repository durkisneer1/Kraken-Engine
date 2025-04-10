#include "Time.hpp"
#include <SDL.h>
#include <thread>

namespace kn::time
{

Clock::Clock() : m_last(std::chrono::high_resolution_clock::now()) {}

double Clock::tick(int frameRate)
{
    if (frameRate < 1)
        frameRate = 1;

    std::chrono::duration<double> targetFrameTime(1.0 / frameRate);

    auto now = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> frameTime = now - m_last;

    if (frameTime < targetFrameTime)
        std::this_thread::sleep_for(targetFrameTime - frameTime);

    now = std::chrono::high_resolution_clock::now();
    frameTime = now - m_last;
    m_last = now;

    return frameTime.count();
}

Timer::Timer(const double duration) : m_duration(duration)
{
    if (duration < 0.0)
        m_duration = 0.0;
}

void Timer::start()
{
    m_startTime = std::chrono::steady_clock::now();
    m_started = true;
    m_paused = false;
    m_elapsedPausedTime = 0.0;
}

void Timer::pause()
{
    if (m_started && !m_paused)
    {
        m_pauseTime = std::chrono::steady_clock::now();
        m_paused = true;
    }
}

void Timer::resume()
{
    if (m_started && m_paused)
    {
        auto now = std::chrono::steady_clock::now();
        auto pauseDuration = now - m_pauseTime;
        m_startTime += pauseDuration; // Adjust the start time to account for the pause duration
        m_paused = false;
    }
}

bool Timer::isFinished() const
{
    if (!m_started)
        return false;

    auto now = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed = now - m_startTime;

    return (elapsed.count() >= m_duration);
}

double Timer::timeRemaining() const
{
    if (!m_started)
        return m_duration;

    auto now = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed = now - m_startTime;
    double remaining = m_duration - elapsed.count();

    return (remaining > 0.0) ? remaining : 0.0;
}

double getTicks() { return SDL_GetTicks() / 1000.0; }

} // namespace kn::time