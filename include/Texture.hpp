#pragma once

#include <SDL.h>
#include <string>

#include "Constants.hpp"
#include "Math.hpp"
#include "Rect.hpp"

namespace kn
{

class Texture final
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
        bool x = false;
        /**
         * @brief Whether to flip the texture vertically.
         */
        bool y = false;
    } flip;

    /**
     * @brief Create a texture from an existing SDL texture pointer.
     *
     * @param sdlTexture An SDL texture object.
     */
    explicit Texture(SDL_Texture* sdlTexture);

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
     */
    [[nodiscard]] SDL_Texture* getSDLTexture() const;

  private:
    SDL_Texture* texture = nullptr;
    Rect rect = {};

    void query();
};
} // namespace kn
