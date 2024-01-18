#pragma once

#include "Math.hpp"

namespace kn
{

/**
 * @brief The global size of the screen. Declare this before the window is instantiated.
 *
 * @warning This is independent of the window size.
 */
extern const math::Vec2 SCREEN_SIZE;

/**
 * @brief The global gravity.
 */
extern float GRAVITY;

} // namespace kn
