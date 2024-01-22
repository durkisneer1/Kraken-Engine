#pragma once

#include <memory>
#include <string>
#include <vector>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include "Constants.hpp"
#include "Texture.hpp"

namespace kn
{
namespace window
{

/**
 * @brief Initialize the window.
 *
 * @param size The size of the window.
 * @param scale The scale of the window.
 */
void init(math::Vec2 size, int scale = 1);

/**
 * @brief Clear the screen.
 *
 * @param color The color to clear the screen.
 */
void cls(Color color = {0, 0, 0, 255});

/**
 * @brief Flip the render frame buffer.
 */
void flip();

/**
 * @brief Draw a texture using rects.
 *
 * @param texture The texture to draw.
 * @param crop The rectangle to draw from.
 * @param rect The rectangle to draw to.
 */
void blit(const std::shared_ptr<Texture>& texture, Rect crop, Rect rect);

/**
 *  @brief Draw a texture to a position.
 *
 *  @param texture The texture to draw.
 *  @param position The position to draw at.
 */
void blit(const std::shared_ptr<Texture>& texture, const math::Vec2& position);

/**
 *  @brief Draw a texture using rects.
 *
 *  @param texture The texture to draw.
 *  @param crop The rectangle to draw from.
 *  @param rect The rectangle to draw to.
 *  @param angle The angle to draw the texture.
 *  @param flipX Whether to flip the texture on the x-axis.
 *  @param flipY Whether to flip the texture on the y-axis.
 */
void blitEx(const std::shared_ptr<Texture>& texture, Rect crop, Rect rect, double angle = 0.0,
            bool flipX = false, bool flipY = false);

/**
 *  @brief Draw a texture to a position.
 *
 *  @param texture The texture to draw.
 *  @param position The position to draw at.
 *  @param angle The angle to draw the texture.
 *  @param flipX Whether to flip the texture on the x-axis.
 *  @param flipY Whether to flip the texture on the y-axis.
 */
void blitEx(const std::shared_ptr<Texture>& texture, const math::Vec2& position, double angle = 0.0,
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

} // namespace window
} // namespace kn
