#pragma once

#include <memory>
#include <string>
#include <vector>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include "Constants.hpp"
#include "Math.hpp"
#include "Rect.hpp"
#include "Texture.hpp"

namespace kn
{
namespace window
{
/**
 * @brief Initialize the window.
 *
 * @param size The size of the window.
 * @param title The title of the window.
 */
void init(const math::Vec2& size, const std::string& title = "Kraken Window");

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
void blit(const Texture& texture, const math::Vec2& position = {0, 0});

/**
 *  @brief Draw a texture using rects.
 *
 *  @param texture The texture to draw.
 *  @param dstRect The rectangle to draw to.
 *  @param srcRect The rectangle to draw from.
 *  @param angle The angle to draw the texture.
 *  @param flipX Whether to flip the texture on the x-axis.
 *  @param flipY Whether to flip the texture on the y-axis.
 */
void blitEx(const Texture& texture, const Rect& dstRect, const Rect& srcRect = {},
            double angle = 0.0, bool flipX = false, bool flipY = false);

/**
 *  @brief Draw a texture to a position.
 *
 *  @param texture The texture to draw.
 *  @param position The position to draw at.
 *  @param angle The angle to draw the texture.
 *  @param flipX Whether to flip the texture on the x-axis.
 *  @param flipY Whether to flip the texture on the y-axis.
 */
void blitEx(const Texture& texture, const math::Vec2& position, double angle = 0.0,
            bool flipX = false, bool flipY = false);

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
const std::vector<kn::Event>& getEvents();

/**
 * @brief Get whether the window is fullscreen or not.
 *
 * @return Whether the window is fullscreen or not.
 */
bool getFullscreen();

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

} // namespace window
} // namespace kn
