#include "AnimationController.hpp"
#include "Constants.hpp"
#include "ErrorLogger.hpp"
#include "Math.hpp"
#include "Overflow.hpp"

namespace kn
{

AnimationController::AnimationController(const int fps) : m_fps(fps)
{
    m_frameTime_ms = (fps == 0) ? 0.0 : MILLISECONDS_PER_SECOND / fps;
}

bool AnimationController::setup(const math::Vec2& size, int frameWidth, int frameHeight)
{
    if (!m_frameRects.empty())
    {
        m_frameRects.clear();
        m_timeLeftInFrame_ms = (m_fps == 0) ? 0.0 : m_frameTime_ms;
        m_index = 0;
    }

    if (static_cast<int>(size.x) % frameWidth || static_cast<int>(size.y) % frameHeight)
    {
        ERROR("Sprite sheet dimensions are not divisible by frame dimensions");
        return false;
    }

    for (int x = 0; x < size.x; x += frameWidth)
        for (int y = 0; y < size.y; y += frameHeight)
            m_frameRects.emplace_back(x, y, frameWidth, frameHeight);

    return true;
}

const Rect& AnimationController::update(const double deltaTime)
{
    if (m_paused)
        return m_frameRects.at(m_index);

    if (!isProductValid(static_cast<double>(MILLISECONDS_PER_SECOND), deltaTime))
    {
        ERROR("Cannot multiply values");
        return m_frameRects.at(m_index);
    }

    if (const double msTakenLastFrame = MILLISECONDS_PER_SECOND * deltaTime;
        m_timeLeftInFrame_ms < msTakenLastFrame)
    {
        const int numberOfFramesPassed =
            static_cast<int>((msTakenLastFrame - m_timeLeftInFrame_ms) / m_frameTime_ms) + 1;
        m_timeLeftInFrame_ms = m_frameTime_ms;
        m_index = (m_index + numberOfFramesPassed) % static_cast<int>(m_frameRects.size());
    }
    else
    {
        if (!isSumValid(m_timeLeftInFrame_ms, -msTakenLastFrame))
        {
            ERROR("Cannot subtract values");
            return m_frameRects.at(m_index);
        }
        m_timeLeftInFrame_ms -= msTakenLastFrame;
    }

    return m_frameRects.at(m_index);
}

void AnimationController::pause() { m_paused = true; }

void AnimationController::resume()
{
    if (m_fps > 0)
        m_paused = false;
}

void AnimationController::setFPS(const int fps)
{
    m_fps = fps;

    if (m_fps == 0)
    {
        pause();
        m_frameTime_ms = 0.0;
    }
    else
        m_frameTime_ms = MILLISECONDS_PER_SECOND / m_fps;

    m_timeLeftInFrame_ms = m_frameTime_ms;
}

} // namespace kn
