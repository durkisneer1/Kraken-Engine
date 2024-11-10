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

bool AnimationController::addAnim(const std::string& filePath, const std::string& name,
                                  const int frameWidth, const int frameHeight)
{
    std::shared_ptr<Texture> texPtr(new Texture());
    if (!texPtr->loadFromFile(filePath))
        return false;

    if (m_animMap.find(name) != m_animMap.end()) // if animation name already exists
    {
        m_animMap.at(name).clear();
        m_timeLeftInFrame_ms = (m_fps == 0) ? 0.0 : m_frameTime_ms;
        m_index = 0;
    }

    m_animMap[name] = {};
    const math::Vec2 size = texPtr->getSize();

    if (static_cast<int>(size.x) % frameWidth || static_cast<int>(size.y) % frameHeight)
    {
        ERROR("Sprite sheet dimensions are not divisible by frame dimensions");
        return false;
    }

    for (int x = 0; x < size.x; x += frameWidth)
        for (int y = 0; y < size.y; y += frameHeight)
        {
            const Frame frame{texPtr, {x, y, frameWidth, frameHeight}};
            m_animMap.at(name).emplace_back(frame);
        }

    m_currAnim = name;

    return true;
}

bool AnimationController::setAnim(const std::string& name)
{
    if (m_animMap.find(name) == m_animMap.end())
    {
        ERROR(name + " does not exist in animation controller.")
        return false;
    }

    m_currAnim = name;
    return true;
}

const Frame& AnimationController::nextFrame(const double deltaTime)
{
    if (m_paused)
        return m_animMap.at(m_currAnim).at(m_index);

    if (!isProductValid(static_cast<double>(MILLISECONDS_PER_SECOND), deltaTime))
    {
        ERROR("Cannot multiply values");
        return m_animMap.at(m_currAnim).at(m_index);
    }

    if (const double msTakenLastFrame = MILLISECONDS_PER_SECOND * deltaTime;
        m_timeLeftInFrame_ms < msTakenLastFrame)
    {
        const int numberOfFramesPassed =
            static_cast<int>((msTakenLastFrame - m_timeLeftInFrame_ms) / m_frameTime_ms) + 1;
        m_timeLeftInFrame_ms = m_frameTime_ms;
        m_index =
            (m_index + numberOfFramesPassed) % static_cast<int>(m_animMap.at(m_currAnim).size());
    }
    else
    {
        if (!isSumValid(m_timeLeftInFrame_ms, -msTakenLastFrame))
        {
            ERROR("Cannot subtract values");
            return m_animMap.at(m_currAnim).at(m_index);
        }
        m_timeLeftInFrame_ms -= msTakenLastFrame;
    }

    return m_animMap.at(m_currAnim).at(m_index);
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
