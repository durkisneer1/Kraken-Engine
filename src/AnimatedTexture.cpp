#include "AnimatedTexture.hpp"
#include "Overflow.hpp"
#include "Window.hpp"

namespace kn
{

AnimatedTexture::AnimatedTexture(const uint32_t fps) :
  m_fps(fps),
  m_width(0U),
  m_height(0U),
  m_index(0U),
  m_paused(false),
  m_timeLeftInFrame_ms(0.0),
  m_spritesheet(nullptr),
  m_rects()
{
    if (fps == 0U)
    {
        m_frameMilliseconds = 0.0;
    }
    else
    {
        m_frameMilliseconds = MILLISECONDS_PER_SECOND / fps;
    }
}

AnimatedTexture::~AnimatedTexture()
{
}

bool AnimatedTexture::loadSpritesheet(const std::string& file, const uint32_t width, const uint32_t height)
{
    if (m_spritesheet)
    {
        // yes, you can use m_spritesheet.reset(), but this makes it clear that the intention is actually to
        // store a nullptr internally
        m_spritesheet = nullptr;
        if (m_fps == 0U)
        {
            m_timeLeftInFrame_ms = 0.0;
        }
        else
        {
            m_timeLeftInFrame_ms = m_frameMilliseconds;
        }

        m_index = 0U;
        m_rects.clear();
    }

    m_width = width;
    m_height = height;

    m_spritesheet = std::make_unique<Texture>();
    if (!m_spritesheet->loadFromFile(file))
    {
        ERROR("Failed to load AnimatedTexture spritesheet from file: " + file);
        return false;
    }

    for (int x = 0; x < m_spritesheet->getSize().x; x += m_width)
    {
        for (int y = 0; y < m_spritesheet->getSize().y; y += m_height)
        {
            m_rects.emplace_back(x, y, m_width, m_height);
        }
    }

    return true;
}

void AnimatedTexture::update(const double dt)
{
    if (m_paused)
    {
        return;
    }

    if (!overflow::isProductValid(static_cast<double>(MILLISECONDS_PER_SECOND), dt))
    {
        ERROR("Cannot multiply values");
        return;
    }
    const double millisecondsTakenLastFrame = MILLISECONDS_PER_SECOND * dt;

    if (m_timeLeftInFrame_ms < millisecondsTakenLastFrame)
    {
        uint32_t numberOfFramesPassed = static_cast<uint32_t>((millisecondsTakenLastFrame - m_timeLeftInFrame_ms) / m_frameMilliseconds) + 1U;

        m_timeLeftInFrame_ms = m_frameMilliseconds;

        m_index = (m_index + numberOfFramesPassed) % m_rects.size();
    }
    else
    {
        if (!overflow::isSumValid(static_cast<double>(m_timeLeftInFrame_ms), -millisecondsTakenLastFrame))
        {
            ERROR("Cannot subtract values");
            return;
        }
        m_timeLeftInFrame_ms -= millisecondsTakenLastFrame;
    }
}

void AnimatedTexture::pause()
{
    m_paused = true;
}

void AnimatedTexture::resume()
{
    if (m_fps > 0U)
    {
        m_paused = false;
    }
}

void AnimatedTexture::setFPS(const uint32_t fps)
{
    m_fps = fps;

    if (m_fps == 0U)
    {
        pause();
        m_frameMilliseconds = 0U;
    }
    else
    {
        m_frameMilliseconds = MILLISECONDS_PER_SECOND / m_fps;
    }

    m_timeLeftInFrame_ms = m_frameMilliseconds;
}

void AnimatedTexture::render(const Rect& dstRect)
{
    if (m_spritesheet)
    {
        window::blit(*m_spritesheet, dstRect, m_rects.at(m_index));
    }
    else
    {
        ERROR("Cannot draw nonexistent Texture");
    }
}

} // namespace kn
