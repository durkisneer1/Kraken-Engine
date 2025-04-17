#pragma once

#include <SDL.h>
#include <string>

#include "Constants.hpp"
#include "Math.hpp"
#include "Rect.hpp"

namespace kn
{
class Surface;

class Texture
{
  public:
    /**
     * @brief The rotation angle of the texture, in degrees.
     */
    double angle = 0.0;

    struct Flip
    {
        /**
         * @brief Whether to flip the texture horizontally.
         */
        bool h = false;
        /**
         * @brief Whether to flip the texture vertically.
         */
        bool v = false;
    } flip;

    /**
     * @brief Create a texture from an existing SDL texture pointer.
     *
     * @param sdlTexture An SDL texture object.
     */
    explicit Texture(SDL_Texture* sdlTexture);

    /**
     * @brief Construct a new Texture object from a Surface object.
     * 
     * @param surface The surface to load the texture from.
     * @note If the surface fails to load, a `kn::Exception` will be thrown.
     */
    explicit Texture(const Surface& surface);

    /**
     * @brief Loads an image from disk.
     *
     * @param filePath Path to the image file.
     *
     * @note If the image file fails to load, a `kn::Exception` will be thrown.
     */
    explicit Texture(const std::string& filePath);

    /**
     * @brief Create a solid color texture.
     *
     * @param size The size of the texture.
     * @param color The color of the texture.
     */
    Texture(const math::Vec2& size, Color color);

    /**
     * @brief Load a texture from an array of pixel data.
     *
     * @param pixelData The pixel data.
     * @param size The size of the texture.
     * @param depth The depth of the pixel data.
     *
     * @note If the pixel data fails to load, a `kn::Exception` will be thrown.
     */
    Texture(const void* pixelData, const math::Vec2& size, int depth = 32);

    Texture() = default;
    ~Texture();

    /**
     * @brief Loads an image from disk.
     *
     * @param filePath Path to the image file.
     *
     * @return ``true`` when successful, ``false`` on failure.
     */
    [[maybe_unused]] bool loadFromFile(const std::string& filePath);

    /**
     * @brief Create a solid color texture.
     *
     * @param size The size of the texture.
     * @param color The color of the texture.
     */
    [[maybe_unused]] bool create(const math::Vec2& size, Color color);

    /**
     * @brief Load a texture from an array of pixel data.
     *
     * @param pixelData The pixel data.
     * @param size The size of the texture.
     * @param depth The depth of the pixel data.
     *
     * @return ``true`` when successful, ``false`` on failure.
     */
    [[maybe_unused]] bool loadFromArray(const void* pixelData, const math::Vec2& size,
                                        int depth = 32);

    /**
     * @brief Load a texture from a Surface object.
     * 
     * @param surface The surface to load the texture from.
     * @return ``true`` when successful, ``false`` on failure.
     */
    [[maybe_unused]] bool loadFromSurface(const Surface& surface);

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
     * @brief Set the rgb mods for the texture.
     *
     * @param colorMod The values to multiply texture color pixels by during rendering.
     */
    void setColorMod(Color colorMod) const;

    /**
     * @brief Get the rgb mods for the texture.
     *
     * @return The values used to multiply texture color pixels during rendering.
     */
    Color getColorMod() const;

    /**
     * @brief Set the alpha mod for the texture.
     *
     * @param alphaMod The value to multiply texture pixel alpha values by during rendering.
     */
    void setAlphaMod(uint8_t alphaMod) const;

    /**
     * @brief Get the alpha mod for the texture.
     *
     * @return The value used to multiply texture pixel alpha values during rendering.
     */
    uint8_t getAlphaMod() const;

    /**
     * @brief Get the SDL texture pointer.
     *
     * @return The SDL texture pointer.
     */
    [[nodiscard]] SDL_Texture* getSDL() const;

  protected:
    SDL_Texture* texture = nullptr;
};
} // namespace kn
