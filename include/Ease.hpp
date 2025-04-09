#pragma once

#include "Math.hpp"
#include <functional>

namespace kn
{

using EasingFunction = std::function<double(double)>;

class EasingAnimation
{
  public:
    /**
     * @brief Construct an easing animation.
     *
     * @param start The starting position of the animation.
     * @param end The ending position of the animation.
     * @param duration The duration of the animation in seconds.
     * @param easeFunc The easing function to use (found in the `kn::ease` namespace).
     */
    EasingAnimation(const Vec2& start, const Vec2& end, double duration, EasingFunction easeFunc);
    ~EasingAnimation() = default;

    /**
     * @brief Update the progress of the animation.
     *
     * @param deltaTime The time since the last frame in seconds.
     *
     * @return The current position of the animation.
     */
    [[nodiscard]] Vec2 update(double deltaTime);

    /**
     * @brief Pause the animation.
     */
    void pause();

    /**
     * @brief Resume the animation.
     * Only works if the animation isn't finished.
     */
    void resume();

    /**
     * @brief Restart the animation.
     */
    void restart();

    /**
     * @brief Reverse the animation direction.
     */
    void reverse();

    /**
     * @brief Check if the animation is finished.
     *
     * @return ``true`` if the animation is finished, ``false`` otherwise.
     */
    [[nodiscard]] bool isFinished();

  private:
    enum class State
    {
        PLAYING,
        PAUSED,
        FINISHED,
    };

    Vec2 startPos;
    Vec2 endPos;
    double duration;
    double elapsedTime = 0.0;
    EasingFunction easingFunc;
    State state = State::PLAYING;
    bool forward = true;

    Vec2 getCurrentPosition() const;
};

namespace ease
{

/**
 * @brief Performs linear easing.
 * 
 * @param t Normalized time (0.0 to 1.0).
 * @return The linear interpolation result.
 */
double linear(double t);

/**
 * @brief Performs quadratic easing in (accelerating from zero).
 * 
 * @param t Normalized time (0.0 to 1.0).
 * @return The eased value.
 */
double inQuad(double t);

/**
 * @brief Performs quadratic easing out (decelerating to zero).
 * 
 * @param t Normalized time (0.0 to 1.0).
 * @return The eased value.
 */
double outQuad(double t);

/**
 * @brief Performs quadratic easing in and out (accelerating then decelerating).
 * 
 * @param t Normalized time (0.0 to 1.0).
 * @return The eased value.
 */
double inOutQuad(double t);

/**
 * @brief Performs cubic easing in (accelerating from zero).
 * 
 * @param t Normalized time (0.0 to 1.0).
 * @return The eased value.
 */
double inCubic(double t);

/**
 * @brief Performs cubic easing out (decelerating to zero).
 * 
 * @param t Normalized time (0.0 to 1.0).
 * @return The eased value.
 */
double outCubic(double t);

/**
 * @brief Performs cubic easing in and out (accelerating then decelerating).
 * 
 * @param t Normalized time (0.0 to 1.0).
 * @return The eased value.
 */
double inOutCubic(double t);

/**
 * @brief Performs quartic easing in (accelerating from zero).
 * 
 * @param t Normalized time (0.0 to 1.0).
 * @return The eased value.
 */
double inQuart(double t);

/**
 * @brief Performs quartic easing out (decelerating to zero).
 * 
 * @param t Normalized time (0.0 to 1.0).
 * @return The eased value.
 */
double outQuart(double t);

/**
 * @brief Performs quartic easing in and out (accelerating then decelerating).
 * 
 * @param t Normalized time (0.0 to 1.0).
 * @return The eased value.
 */
double inOutQuart(double t);

/**
 * @brief Performs quintic easing in (accelerating from zero).
 * 
 * @param t Normalized time (0.0 to 1.0).
 * @return The eased value.
 */
double inQuint(double t);

/**
 * @brief Performs quintic easing out (decelerating to zero).
 * 
 * @param t Normalized time (0.0 to 1.0).
 * @return The eased value.
 */
double outQuint(double t);

/**
 * @brief Performs quintic easing in and out (accelerating then decelerating).
 * 
 * @param t Normalized time (0.0 to 1.0).
 * @return The eased value.
 */
double inOutQuint(double t);

/**
 * @brief Performs sine easing in (accelerating from zero) based on a sine function.
 * 
 * @param t Normalized time (0.0 to 1.0).
 * @return The eased value.
 */
double inSine(double t);

/**
 * @brief Performs sine easing out (decelerating to zero) based on a sine function.
 * 
 * @param t Normalized time (0.0 to 1.0).
 * @return The eased value.
 */
double outSine(double t);

/**
 * @brief Performs sine easing in and out (accelerating then decelerating) based on a sine function.
 * 
 * @param t Normalized time (0.0 to 1.0).
 * @return The eased value.
 */
double inOutSine(double t);

/**
 * @brief Performs circular easing in (accelerating from zero) using a circular function.
 * 
 * @param t Normalized time (0.0 to 1.0).
 * @return The eased value.
 */
double inCirc(double t);

/**
 * @brief Performs circular easing out (decelerating to zero) using a circular function.
 * 
 * @param t Normalized time (0.0 to 1.0).
 * @return The eased value.
 */
double outCirc(double t);

/**
 * @brief Performs circular easing in and out (accelerating then decelerating) using a circular function.
 * 
 * @param t Normalized time (0.0 to 1.0).
 * @return The eased value.
 */
double inOutCirc(double t);

/**
 * @brief Performs exponential easing in (accelerating from zero) using an exponential function.
 * 
 * @param t Normalized time (0.0 to 1.0).
 * @return The eased value.
 */
double inExpo(double t);

/**
 * @brief Performs exponential easing out (decelerating to zero) using an exponential function.
 * 
 * @param t Normalized time (0.0 to 1.0).
 * @return The eased value.
 */
double outExpo(double t);

/**
 * @brief Performs exponential easing in and out (accelerating then decelerating) using an exponential function.
 * 
 * @param t Normalized time (0.0 to 1.0).
 * @return The eased value.
 */
double inOutExpo(double t);

/**
 * @brief Performs elastic easing in (overshooting slightly as it accelerates) using an elastic function.
 * 
 * @param t Normalized time (0.0 to 1.0).
 * @return The eased value.
 */
double inElastic(double t);

/**
 * @brief Performs elastic easing out (overshooting slightly as it decelerates) using an elastic function.
 * 
 * @param t Normalized time (0.0 to 1.0).
 * @return The eased value.
 */
double outElastic(double t);

/**
 * @brief Performs elastic easing in and out (combining elastic acceleration and deceleration).
 * 
 * @param t Normalized time (0.0 to 1.0).
 * @return The eased value.
 */
double inOutElastic(double t);

/**
 * @brief Performs back easing in (overshooting in the reverse direction before accelerating) using a back function.
 * 
 * @param t Normalized time (0.0 to 1.0).
 * @return The eased value.
 */
double inBack(double t);

/**
 * @brief Performs back easing out (overshooting in the forward direction as it decelerates) using a back function.
 * 
 * @param t Normalized time (0.0 to 1.0).
 * @return The eased value.
 */
double outBack(double t);

/**
 * @brief Performs back easing in and out (combining back easing in and out).
 * 
 * @param t Normalized time (0.0 to 1.0).
 * @return The eased value.
 */
double inOutBack(double t);

/**
 * @brief Performs bounce easing in (bouncing effect as it accelerates from zero) using a bounce function.
 * 
 * @param t Normalized time (0.0 to 1.0).
 * @return The eased value.
 */
double inBounce(double t);

/**
 * @brief Performs bounce easing out (bouncing effect as it decelerates to zero) using a bounce function.
 * 
 * @param t Normalized time (0.0 to 1.0).
 * @return The eased value.
 */
double outBounce(double t);

/**
 * @brief Performs bounce easing in and out (combining bounce effects on both ends).
 * 
 * @param t Normalized time (0.0 to 1.0).
 * @return The eased value.
 */
double inOutBounce(double t);

} // namespace ease
} // namespace kn