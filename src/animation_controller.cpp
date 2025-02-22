#include "AnimationController.hpp"
#include "ErrorLogger.hpp"
#include "Math.hpp"

#include <filesystem>
namespace fs = std::filesystem;

namespace kn
{

bool AnimationController::loadSpriteSheet(const std::string& name, const std::string& filePath,
                                          const math::Vec2& frameSize, const int fps)
{
    const std::shared_ptr<Texture> texPtr(new Texture());
    if (!texPtr->loadFromFile(filePath))
        return false;

    const math::Vec2 size = texPtr->getSize();
    const int frameWidth = static_cast<int>(frameSize.x);
    const int frameHeight = static_cast<int>(frameSize.y);

    if (static_cast<int>(size.x) % frameWidth || static_cast<int>(size.y) % frameHeight)
    {
        ERROR("Sprite sheet dimensions are not divisible by frame dimensions");
        return false;
    }

    if (m_animMap.find(name) != m_animMap.end())
        m_animMap.erase(name);

    Animation newAnim;
    newAnim.fps = fps;
    for (int y = 0; y < size.y; y += frameHeight)
        for (int x = 0; x < size.x; x += frameWidth)
        {
            const Frame frame{texPtr, {x, y, frameWidth, frameHeight}};
            newAnim.frames.emplace_back(frame);
        }

    m_animMap[name] = std::move(newAnim);
    m_currAnim = name;

    return true;
}

bool AnimationController::loadFolder(const std::string& name, const std::string& dirPath,
                                     const int fps)
{
    if (m_animMap.find(name) != m_animMap.end())
        m_animMap.erase(name);

    Animation newAnim;
    newAnim.fps = fps;

    for (const auto& entry : fs::directory_iterator(dirPath))
    {
        const std::string filePath = entry.path().string();

        const std::shared_ptr<Texture> texPtr(new Texture());
        if (!texPtr->loadFromFile(filePath))
            continue;

        const Frame frame{texPtr, texPtr->getRect()};
        newAnim.frames.emplace_back(frame);
    }

    if (newAnim.frames.empty())
        return false;

    m_animMap[name] = std::move(newAnim);
    m_currAnim = name;

    return true;
}

void AnimationController::removeAnim(const std::string& name)
{
    if (m_animMap.find(name) != m_animMap.end())
        m_animMap.erase(name);
}

bool AnimationController::setAnim(const std::string& name)
{
    if (m_animMap.find(name) == m_animMap.end())
        return false;

    m_currAnim = name;
    return true;
}

const Frame* AnimationController::nextFrame(const double deltaTime)
{
    const Animation& currAnim = m_animMap.at(m_currAnim);

    if (m_paused)
        return &currAnim.frames.at(static_cast<int>(m_index));

    m_index += deltaTime * currAnim.fps * m_playbackSpeed;
    const auto frameCount = static_cast<double>(currAnim.frames.size());
    m_index = fmod(m_index + frameCount, frameCount);

    return &currAnim.frames.at(static_cast<int>(m_index));
}

void AnimationController::rewind()
{
    m_index = 0.0;
    m_prevIndex = 0.0;
}

void AnimationController::pause() { m_paused = true; }

void AnimationController::resume()
{
    if (m_playbackSpeed > 0.0)
        m_paused = false;
}

void AnimationController::setPlaybackSpeed(const double speed)
{
    m_playbackSpeed = speed;
    if (speed == 0)
        pause();
}

bool AnimationController::isFinished()
{
    if (m_prevIndex > m_index)
    {
        m_prevIndex = m_index;
        return true;
    }
    m_prevIndex = m_index;
    return false;
}

const std::string& AnimationController::getCurrentAnim() const { return m_currAnim; }

} // namespace kn
