#pragma once

#include <vector>
#include <memory>
#include <string>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "Texture.hpp"
#include "Math.hpp"
#include "Constants.hpp"
#include "Globals.hpp"


namespace kn {

/**
 * @brief The renderer context.
 * 
 * @warning This class must be a singleton.
 */
class RenderWindow final {
public:
    /**
     * @brief Get a reference to the instance of the singleton
     * 
     * @return reference to the instance
     */
    RenderWindow& getInstance();

    /**
     * @brief Clear the screen.
     * 
     * @param color The color to clear the screen.
     */
    void cls(SDL_Color color = { 0, 0, 0, 255 });

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
     *  @param texture The texture to draw.
     *  @param position The position to draw at.
     */
    void blit(const std::shared_ptr<Texture>& texture, const math::Vec2& position);

    /**
     *  @brief Draw a texture using rects.
     *  @param texture The texture to draw.
     *  @param crop The rectangle to draw from.
     *  @param rect The rectangle to draw to.
     *  @param angle The angle to draw the texture.
     *  @param flipX Whether to flip the texture on the x-axis.
     *  @param flipY Whether to flip the texture on the y-axis.
     */
    void blitEx(const std::shared_ptr<Texture>& texture, Rect crop, Rect rect, double angle = 0.0, bool flipX = false, bool flipY = false);

    /**
     *  @brief Draw a texture to a position.
     *  @param texture The texture to draw.
     *  @param position The position to draw at.
     *  @param angle The angle to draw the texture.
     *  @param flipX Whether to flip the texture on the x-axis.
     *  @param flipY Whether to flip the texture on the y-axis.
     */
    void blitEx(const std::shared_ptr<Texture>& texture, const math::Vec2& position, double angle = 0.0, bool flipX = false, bool flipY = false);

    /**
     *  @brief Get the window renderer.
     *  @return The window renderer.
     */
    SDL_Renderer* getRenderer() { return m_renderer; }

    /**
     *  @brief Get user events.
     *  @return The user events.
     */
    const std::vector<KN_Event>& getEvents();

    /**
     * @brief Get the title of the window
     * 
     * @return the title
     */
    const std::string getTitle() const;

    /**
     * @brief Get whether the window is fullscreen or not
     * 
     * @return true if fullscreen
     * @return false otherwise
     */
    bool getFullscreen() const;

    /**
     * @brief Get the scale of the window
     * 
     * @return the scale
     */
    static int getScale();

    /**
     * @brief Set the title of the window
     * 
     * @param newTitle the new title
     */
    void setTitle(const std::string& newTitle);

    /**
     * @brief Set whether the window is fullscreen or not
     * 
     * @param fullscreen true if setting fullscreen, false otherwise
     */
    void setFullscreen(bool fullscreen);

    /**
     * @brief Set the scale of the window. Only valid before instantiating
     * RenderWindow for the first time
     *
     * @param newScale the scale of the window
     *
     * @return true if successfully set scale
     * @return false otherwise
     */
    static bool setScale(int newScale);
    
private:
    /**
     * @brief Private constructor for singleton design pattern 
     */
    RenderWindow();

    /**
     * @brief Destructor
     */
    ~RenderWindow();

    /**
     * @brief Deleted copy constructor to prevent copy
     */
    RenderWindow(const RenderWindow& other) = delete;

    /**
     * @brief Deleted assignment operator to prevent assignment
     */
    RenderWindow& operator=(const RenderWindow& rhs) = delete;

    SDL_Renderer* m_renderer = nullptr;
    SDL_Window* m_window = nullptr;

    KN_Event m_event;
    std::vector<SDL_Event> m_events;
};

}
