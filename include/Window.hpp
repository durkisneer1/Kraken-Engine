#pragma once

#include <string>

#include <SDL.h>

#include "Constants.hpp"
#include "Rect.hpp"

namespace kn
{

class Texture;

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
 *
 * @return Whether the window was successfully initialized.
 */
[[maybe_unused]] bool init(const math::Vec2& resolution, const std::string& title = "Kraken Window",
                           int scale = 1);

/**
 * @brief Get whether the window is open.
 *
 * @return Whether the window is open.
 */
[[nodiscard]] bool isOpen();

/**
 * @brief Close the window.
 */
void close();

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
 *  @param anchor The anchor point to draw from.
 */
void blit(const Texture& texture, const math::Vec2& position = {}, Anchor anchor = TOP_LEFT);

/**
 *  @brief Get the window renderer.
 *
 *  @return The window renderer.
 */
[[nodiscard]] SDL_Renderer* getRenderer();

/**
 *  @brief Populate the event object with the concurrent user events.
 *
 *  @param event The event object to populate.
 *
 *  @return
 */
int pollEvent(Event& event);

/**
 * @brief Get whether the window is fullscreen or not.
 *
 * @return Whether the window is fullscreen or not.
 */
[[nodiscard]] bool getFullscreen();

/**
 * @brief Get the scale of the window.
 *
 * @return The scale of the window.
 */
[[nodiscard]] int getScale();

/**
 * @brief Get the size of the screen.
 *
 * @return The size of the screen.
 */
[[nodiscard]] math::Vec2 getSize();

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
[[nodiscard]] std::string getTitle();

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
