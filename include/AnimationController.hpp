#pragma once

#include "Rect.hpp"
#include "Texture.hpp"
#include <string>
#include <unordered_map>
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
     * @brief Adds a new animation.
     *
     * @param file The image file path that contains the animation frames.
     * @param animationName The name of the animation.
     * @param frameWidth The width of each frame.
     * @param frameHeight The height of each frame.
     *
     * @return true if adding a new animation was succesful, false otherwise.
     */
    [[maybe_unused]] bool addAnim(const std::string& file, std::string animationName,
                                  int frameWidth, int frameHeight);

    /**
     * @brief Sets the animation which will be used.
     *
     * @param name The name of the animation.
     *
     * @return true if such animation exists, false otherwise.
     */
    [[maybe_unused]] bool setAnim(std::string animationName);

    /**
     * @brief Looks for a texture that was loaded with an specific name durinng addAnim()
     *
     * @param animationName The name of the animation.
     * @return A reference to a texture that holds the animation, nullptr if such animation could
     * not be found.
     */

    [[maybe_unused]] kn::Texture& getAnimSpritesheet();

    // /**
    //  * @brief Set up the animation controller.
    //  *
    //  * @param size The size of the sprite sheet.
    //  * @param frameWidth The width of each frame.
    //  * @param frameHeight The height of each frame.
    //  *
    //  * @return true if the setup was successful, false otherwise.
    //  */
    // [[maybe_unused]] bool setup(const math::Vec2& size, int frameWidth, int frameHeight);

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

  public:
    std::string m_currentAnimationName;

    std::unordered_map<std::string, kn::Texture> m_texturesMap;
    std::unordered_map<std::string, std::vector<Rect>> m_animationsMap;
};
} // namespace kn
