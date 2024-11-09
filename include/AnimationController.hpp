#pragma once

#include "Rect.hpp"
#include <vector>

namespace kn
{
/**
 * @brief Handler for sprite sheet animations.
 */
class AnimationController final
{
  public:
    /**
     * @brief Construct a new Animation Controller object at a given frame rate.
     *
     * @param fps The frame rate of the animation.
     */
    explicit AnimationController(int fps = 24);
    ~AnimationController() = default;

    /**
     * @brief Set up the animation controller.
     *
     * @param size The size of the sprite sheet.
     * @param frameWidth The width of each frame.
     * @param frameHeight The height of each frame.
     *
     * @return true if the setup was successful, false otherwise.
     */
    [[maybe_unused]] bool setup(const math::Vec2& size, int frameWidth, int frameHeight);

    /**
     * @brief Update the animation.
     *
     * @param deltaTime The time since the last frame.
     *
     * @return The srcRect area of the current frame. Use when blitting.
     */
    [[nodiscard]] const Rect& update(double deltaTime);

    /**
     * @brief Set the frame rate of the animation.
     *
     * @param fps The frame rate of the animation.
     *
     * @note Will pause the animation if set to 0.
     */
    void setFPS(int fps);

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
    int m_fps;
    int m_index = 0;
    bool m_paused = false;

    double m_frameTime_ms;
    double m_timeLeftInFrame_ms = 0.0;

    std::vector<Rect> m_frameRects;
};
} // namespace kn
