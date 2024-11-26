#pragma once

#include <string>
#include <vector>

#include <SDL.h>

#include "Constants.hpp"
#include "Math.hpp"
#include "Rect.hpp"
#include "Texture.hpp"

namespace kn
{

/**
 * @brief A global camera position.
 */
inline math::Vec2 camera;

namespace window
{
/**
 * @brief Initialize the window.
 *
 * @param resolution The size of the window.
 * @param title The title of the window.
 * @param scale The scale of the window.
 */
void init(const math::Vec2& resolution, const std::string& title = "Kraken Window", int scale = 1);

/**
 * @brief Clear the screen.
 *
 * @param color The color to clear the screen.
 */
void clear(Color color = {0, 0, 0, 255});

/**
 * @brief Flip the render frame buffer.
 */
void flip();

/**
 * @brief Draw a texture using rects.
 *
 * @param texture The texture to draw.
 * @param dstRect The rectangle to draw to.
 * @param srcRect The rectangle to draw from.
 */
void blit(const Texture& texture, const Rect& dstRect, const Rect& srcRect = {});

/**
 *  @brief Draw a texture to a position.
 *
 *  @param texture The texture to draw.
 *  @param position The position to draw at.
 */
void blit(const Texture& texture, const math::Vec2& position = {});

/**
 *  @brief Get the window renderer.
 *
 *  @return The window renderer.
 */
SDL_Renderer* getRenderer();

/**
 *  @brief Get user events.
 *
 *  @return The user events.
 */
const std::vector<Event>& getEvents();

/**
 * @brief Get whether the window is fullscreen or not.
 *
 * @return Whether the window is fullscreen or not.
 */
bool getFullscreen();

/**
 * @brief Get the scale of the window.
 *
 * @return The scale of the window.
 */
int getScale();

/**
 * @brief Get the size of the screen.
 *
 * @return The size of the screen.
 */
math::Vec2 getSize();

/**
 * @brief Set the title of the window.
 *
 * @param newTitle The new title for the window.
 */
void setTitle(const std::string& newTitle);

/**
 * @brief Get the title of the window.
 *
 * @return The title of the window.
 */
std::string getTitle();

/**
 * @brief Set whether the window is fullscreen or not.
 *
 * @param fullscreen ``true`` if setting fullscreen, ``false`` otherwise.
 */
void setFullscreen(bool fullscreen);

/**
 * @brief Quit SDL and destroy the window.
 */
void quit();

/**
 * @brief Set the window icon.
 *
 * @param path The path to the icon image file.
 */
void setIcon(const std::string& path);

} // namespace window
} // namespace kn
