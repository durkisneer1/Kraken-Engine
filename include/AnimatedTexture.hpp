#pragma once

#include <stdint.h>
#include <vector>
#include <memory>

#include "Constants.hpp"
#include "ErrorLogger.hpp"
#include "Texture.hpp"

namespace kn
{

/**
 * @brief Represents a Texture loaded from a spritesheet, where each frame is a sprite in the sheet
 *
 */
class AnimatedTexture
{
  public:
    /**
     * @brief Construct a new AnimatedTexture object that runs at the given fps
     *
     * @param fps the number of frames of the animation to show per second
     */
    explicit AnimatedTexture(const uint32_t fps = 24U);

    /**
     * @brief Destroy the AnimatedTexture object
     *
     */
    virtual ~AnimatedTexture();

    /**
     * @brief Updates how long the current frame has left and increments the frame as needed
     *
     * @param dt Number of seconds since last update
     */
    void update(const double dt);

    /**
     * @brief Loads a spritesheet and the animations from it
     *
     * @param file filename of the spritesheet
     * @param width width of each frame of the animation in the spritesheet
     * @param height height of each frame of the animation in the spritesheet
     *
     * @return true when successful, false on failure
     */
    bool loadSpritesheet(const std::string& file, const uint32_t width, const uint32_t height);

    /**
     * @brief Pauses the animation, if playing
     *
     */
    void pause();

    /**
     * @brief Resumes the animation, if paused. Will not do anything if fps is set to 0
     *
     */
    void resume();

    /**
     * @brief Sets the frames per second the animation runs at. Will pause the animation if set to 0
     *
     * @param fps Number of frames to display per second
     */
    void setFPS(const uint32_t fps);

    /**
     * @brief Renders the current frame of the animation to the window
     *
     * @param dstRect location on the window to draw the frame
     */
    void render(const Rect& dstRect);

  protected:
    uint32_t m_fps;               //!< Number of frames to display per second
    uint32_t m_width;             //!< Width of each frame
    uint32_t m_height;            //!< Height of each frame
    uint32_t m_index;             //!< Current frame index
    bool m_paused;                //!< True if animation is paused, false if playing
    double m_frameMilliseconds;   //!< How many milliseconds each frame should take

    double m_timeLeftInFrame_ms;  //!< time left in frame (in milliseconds)

    // kn::Texture* m_spritesheet;   //!< Pointer to the loaded spritesheet
    std::unique_ptr<kn::Texture> m_spritesheet;

    std::vector<Rect> m_rects;    //!< Vector of rects representing each frame's location on the spritesheet
};

} // namespace kn
