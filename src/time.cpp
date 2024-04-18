#include "Time.hpp"
#include "Math.hpp"

namespace kn
{
namespace time
{
Clock::Clock()
    : m_frameTime(0), m_targetFrameTime(0), m_deltaTime(0),
      m_frequency(SDL_GetPerformanceFrequency()), m_now(0), m_last(SDL_GetPerformanceCounter())
{
}

double Clock::tick(int frameRate)
{
    if (frameRate < 1)
        frameRate = 1;

    m_targetFrameTime = 1000.0 / frameRate;
    m_frameTime = ((SDL_GetPerformanceCounter() / m_frequency) - (m_last / m_frequency)) * 1000.0;
    if (m_frameTime < m_targetFrameTime)
        SDL_Delay((uint32_t)(m_targetFrameTime - m_frameTime));

    m_now = SDL_GetPerformanceCounter();
    m_deltaTime = (m_now / m_frequency) - (m_last / m_frequency);
    m_last = m_now;

    return m_deltaTime;
}
} // namespace time
} // namespace kn
