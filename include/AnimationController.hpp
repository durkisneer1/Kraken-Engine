#pragma once

#include "Rect.hpp"
#include "Texture.hpp"
#include <memory>
#include <unordered_map>
#include <vector>

namespace kn
{

/**
 * @brief Container for a texture pointer and source rect
 */
struct Frame
{
    std::shared_ptr<Texture> tex;
    Rect rect;
};

/**
 * @brief Container for a list of frames.
 */
struct Animation
{
    std::vector<Frame> frames;
    int fps;
};

/**
 * @brief Handler for sprite sheet animations.
 */
class AnimationController final
{
  public:
    /**
     * @brief Construct a new Animation Controller object.
     */
    AnimationController() = default;
    ~AnimationController() = default;

    /**
     * @brief Set up the animation controller.
     *
     * @param name The name of the animation.
     * @param filePath The path to the sprite sheet image file.
     * @param frameSize The size of each frame in the sprite sheet.
     * @param fps The frame rate of the animation.
     *
     * @return true if the setup was successful, false otherwise.
     */
    [[maybe_unused]] bool addAnim(const std::string& name, const std::string& filePath,
                                  const math::Vec2& frameSize, int fps);

    /**
     * @brief Remove an animation from the controller.
     *
     * @param name The name of the animation to remove.
     */
    void removeAnim(const std::string& name);

    /**
     * @brief Change the active animation.
     *
     * @param name The name of an added animation.
     *
     * @return true if the animation was successfully changed, false otherwise.
     */
    [[maybe_unused]] bool setAnim(const std::string& name);

    /**
     * @brief Get the next frame of the animation.
     *
     * @param deltaTime The time since the last time this function was called.
     *
     * @return The next frame's texture and area to render from.
     */
    [[nodiscard]] const Frame& nextFrame(double deltaTime);

    /**
     * @brief Set the playback speed of animations.
     *
     * @param speed The speed to animate.
     * YES, IT WORKS WITH NEGATIVE VALUES!
     */
    void setPlaybackSpeed(double speed);

    /**
     * @brief Check if the current animation playing is finished.
     *
     * @return true if the animation is finished, false otherwise.
     */
    [[nodiscard]] bool isFinished();

    /**
     * @brief Get the current animation name.
     *
     * @return The name of the current animation.
     */
    [[nodiscard]] const std::string& getCurrentAnim() const { return m_currAnim; }

    /**
     * @brief Pause the animation.
     */
    void pause();

    /**
     * @brief Resume the animation.
     *
     * @note Will not do anything if fps is set to 0.
     */
    void resume();

  private:
    double m_playbackSpeed = 1.0;
    double m_index = 0.0;
    double m_prevIndex = 0.0;
    bool m_paused = false;
    std::string m_currAnim;

    std::unordered_map<std::string, Animation> m_animMap;
};
} // namespace kn
