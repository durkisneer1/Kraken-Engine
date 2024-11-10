#pragma once

#include "Rect.hpp"
#include "Texture.hpp"
#include <memory>
#include <unordered_map>
#include <vector>

namespace kn
{

/**
 * @brief Container for a texture pointer and rect
 */
struct Frame
{
    std::shared_ptr<Texture> tex;
    Rect rect;
};

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
     * @param filePath The path to the sprite sheet image file.
     * @param name The name of the animation.
     * @param frameWidth The width of each frame.
     * @param frameHeight The height of each frame.
     *
     * @return true if the setup was successful, false otherwise.
     */
    [[maybe_unused]] bool addAnim(const std::string& filePath, const std::string& name,
                                  int frameWidth, int frameHeight);

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
    std::string m_currAnim;

    double m_frameTime_ms;
    double m_timeLeftInFrame_ms = 0.0;

    std::unordered_map<std::string, std::vector<Frame>> m_animMap;
};
} // namespace kn
