#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <vector>
#include <memory>
#include "Texture.hpp"
#include "Math.hpp"
#include "Constants.hpp"


namespace kn {
	/// @brief The renderer context.
	/// @note This class is a mandatory singleton.
	class RenderWindow {
	public:
		/// @brief Create a window.
		/// @param size The size of the window.
		/// @param title The title of the window.
		RenderWindow(kn::math::Vector2 size, const std::string &title);
		~RenderWindow();
		
		/// @brief Clear the window.
		/// @param color The color to clear the window.
		void fill(SDL_Color color);

		/// @brief Flip the render frame buffer.
		void flip();

		/// @brief Draw a texture.
		/// @param texture The texture to draw.
		/// @param rect The rectangle to draw on.
		void blit(const std::shared_ptr<kn::Texture> texture, kn::Rect rect);

		/// @brief Draw a texture.
		/// @param texture The texture to draw.
		/// @param position The position to draw at.
		void blit(const std::shared_ptr<kn::Texture> texture, kn::math::Vector2 position);

		/// @brief Draw a texture.
		/// @param texture The texture to draw.
		/// @param rect The rectangle to draw on.
		/// @param angle The angle to draw the texture.
		/// @param flipX Whether to flip the texture on the x-axis.
		/// @param flipY Whether to flip the texture on the y-axis.
		void blitEx(const std::shared_ptr<kn::Texture> texture, kn::Rect rect, double angle = 0.0, bool flipX = false, bool flipY = false);

		/// @brief Draw a texture.
		/// @param texture The texture to draw.
		/// @param position The position to draw at.
		/// @param angle The angle to draw the texture.
		/// @param flipX Whether to flip the texture on the x-axis.
		/// @param flipY Whether to flip the texture on the y-axis.
		void blitEx(const std::shared_ptr<kn::Texture> texture, kn::math::Vector2 position, double angle = 0.0, bool flipX = false, bool flipY = false);

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

		void init();
	};
}
