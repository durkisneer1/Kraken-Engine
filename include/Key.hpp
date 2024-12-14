#pragma once

#include "Constants.hpp"

#include <string>
#include <vector>

namespace kn
{
namespace math
{
class Vec2;
} // namespace math

namespace key
{
/**
 * @brief Get the keys that are currently pressed.
 *
 * @return The keys that are currently pressed.
 */
const uint8_t* getPressed();

/**
 * @brief Check if the argument key is pressed.
 *
 * @param name The name of the key binding.
 *
 * @return If the argument key is pressed.
 */
bool isPressed(const std::string& name);

/**
 * @brief Bind a vector of keys to a string.
 *
 * @param name The name of the key binding.
 * @param keys The keys to bind.
 *
 * @note If the name is empty, the function will return without binding the keys.
 */
void bind(const std::string& name, const std::vector<Scancode>& keys);

/**
 * @brief Unbind the keys bound to the argument name.
 *
 * @param name The name of the key binding.
 */
void unbind(const std::string& name);

/**
 * @brief Get the direction vector from the keys bound to the argument name.
 *
 * @param left The name of the key bindings for left movement.
 * @param right The name of the key bindings for right movement.
 * @param up The name of the key bindings for up movement.
 * @param down The name of the key bindings for down movement.
 *
 * @return A direction vector.
 */
math::Vec2 getDirection(const std::string& left = "", const std::string& right = "",
                        const std::string& up = "", const std::string& down = "");
} // namespace key
} // namespace kn