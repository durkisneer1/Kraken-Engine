#pragma once

#include <vector>
#include <memory>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "Texture.hpp"
#include "Math.hpp"
#include "Constants.hpp"
#include "Globals.hpp"


namespace kn {

/// @brief The renderer context.
/// @warning This class must be a singleton.
class RenderWindow final {
public:
	/// @brief Create a window.
	/// @param title The title of the window.
	/// @param scale The scale of the window.
	/// @param fullscreen Whether to make the window fullscreen.
	RenderWindow(const std::string &title = "Kraken", int scale = 1, bool fullscreen = false);
	~RenderWindow();
	
	/// @brief Clear the screen.
	/// @param color The color to clear the screen.
	void cls(SDL_Color color = { 0, 0, 0, 255 });

	/// @brief Flip the render frame buffer.
	void flip();

	/// @brief Draw a texture using rects.
	/// @param texture The texture to draw.
	/// @param crop The rectangle to draw from.
	/// @param rect The rectangle to draw to.
	void blit(const std::shared_ptr<Texture>& texture, Rect crop, Rect rect);

	/// @brief Draw a texture to a position.
	/// @param texture The texture to draw.
	/// @param position The position to draw at.
	void blit(const std::shared_ptr<Texture>& texture, const math::Vec2& position);

	/// @brief Draw a texture using rects.
	/// @param texture The texture to draw.
	/// @param crop The rectangle to draw from.
	/// @param rect The rectangle to draw to.
	/// @param angle The angle to draw the texture.
	/// @param flipX Whether to flip the texture on the x-axis.
	/// @param flipY Whether to flip the texture on the y-axis.
	void blitEx(const std::shared_ptr<Texture>& texture, Rect crop, Rect rect, double angle = 0.0, bool flipX = false, bool flipY = false);

	/// @brief Draw a texture to a position.
	/// @param texture The texture to draw.
	/// @param position The position to draw at.
	/// @param angle The angle to draw the texture.
	/// @param flipX Whether to flip the texture on the x-axis.
	/// @param flipY Whether to flip the texture on the y-axis.
	void blitEx(const std::shared_ptr<Texture>& texture, const math::Vec2& position, double angle = 0.0, bool flipX = false, bool flipY = false);

	/// @brief Get the window renderer.
	/// @return The window renderer.
	SDL_Renderer* getRenderer() { return renderer; }

	/// @brief Get user events.
	/// @return The user events.
	const std::vector<KN_Event>& getEvents();
	
private:
	SDL_Renderer* renderer = nullptr;
	SDL_Window* window = nullptr;

	KN_Event event;
	std::vector<SDL_Event> events;
};

}
