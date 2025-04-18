#include "Time.hpp"
#include <SDL.h>

namespace kn::time
{

double Clock::tick(int frameRate)
{
    const double targetFrameTime = 1000.0 / frameRate;
    auto now = static_cast<double>(SDL_GetPerformanceCounter());
    double frameTime = (now - m_last) / m_frequency * 1000.0;

    if (frameTime < targetFrameTime)
        SDL_Delay(static_cast<uint32_t>(targetFrameTime - frameTime));

    now = static_cast<double>(SDL_GetPerformanceCounter());
    frameTime = (now - m_last) / m_frequency;
    m_last = now;

    m_fps = static_cast<int>(1.0 / frameTime);
    return frameTime;
}

int Clock::getFPS() { return m_fps; }

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