#pragma once

#include <vector>

#include <SDL.h>

#include "Constants.hpp"
#include "Math.hpp"

namespace kn
{
namespace input
{

/**
 * @brief Get the mouse position.
 *
 * @return The mouse position.
 */
math::Vec2 getMousePos();

/**
 * @brief Get the mouse button pressed.
 *
 * @return The mouse button pressed.
 */
const int getMouseButtonPressed();

/**
 * @brief Get the keys pressed.
 *
 * @return The keys pressed.
 */
const Uint8* getKeysPressed();

/**
 * @brief Get the vector of the keys pressed.
 *
 * @param left The keys to move left.
 * @param right The keys to move right.
 * @param up The keys to move up.
 * @param down The keys to move down.
 *
 * @return The vector of the keys pressed.
 */
math::Vec2 getVector(const std::vector<KEYS>& left = {}, const std::vector<KEYS>& right = {},
                     const std::vector<KEYS>& up = {}, const std::vector<KEYS>& down = {});

} // namespace input
} // namespace kn
