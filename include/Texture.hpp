#pragma once

#include <SDL.h>
#include <string>

#include "Constants.hpp"
#include "Math.hpp"
#include "Rect.hpp"

namespace kn
{

/**
 * @brief A texture object.
 */
class Texture final
{
  public:
    /**
     * @brief The rotation angle of the texture, in degrees.
     */
    double angle = 0.0;

    /**
     * @brief The flip state of the texture.
     * Indicates whether the texture is flipped horizontally (x) or vertically (y).
     */
    struct Flip
    {
        bool x = false;
        bool y = false;
    } flip;

    /**
     * @brief Constructs an empty Texture object.
     * @note The internal SDL_Texture* is nullptr until loadFromFile is called.
     */
    Texture() = default;

    /**
     * @brief Create a solid color texture.
     *
     * @param size The size of the texture.
     * @param color The color of the texture.
     */
    Texture(const math::Vec2& size, Color color);

    /**
     * @brief Create a texture from an existing SDL texture pointer.
     *
     * @param sdlTexture An SDL texture object.
     *
     * @note This should rarely or never have to be used.
     */
    explicit Texture(SDL_Texture* sdlTexture);

    ~Texture();

    /**
     * @brief Get the size of the texture.
     *
     * @return The size of the texture.
     */
    [[nodiscard]] math::Vec2 getSize() const;

    /**
     * @brief Get the rect of the texture.
     *
     * @return The rect of the texture.
     */
    [[nodiscard]] Rect getRect() const;

    /**
     * @brief Get the SDL texture pointer.
     *
     * @return The SDL texture pointer.
     *
     * @note This should rarely or never have to be used.
     */
    [[nodiscard]] SDL_Texture* getSDLTexture() const;

    /**
     * @brief Loads an image from disk.
     *
     * @param filePath Path to the image file.
     *
     * @return ``true`` when successful, ``false`` on failure.
     */
    [[maybe_unused]] bool loadFromFile(const std::string& filePath);

  private:
    SDL_Texture* texture = nullptr;
    Rect rect = {};

    void query();
};
} // namespace kn
