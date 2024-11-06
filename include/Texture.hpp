#pragma once

#include <SDL.h>
#include <string>

#include "Constants.hpp"
#include "Rect.hpp"

namespace kn
{
namespace math
{
class Vec2;
} // namespace math

/**
 * @brief A texture object.
 */
class Texture final
{
  public:
    /**
     * @brief Constructs an empty Texture object. Note that the internal SDL_Texture* is nullptr until
     *        loadFromFile is called.
     *
     */
    explicit Texture();

    /**
     * @brief Create a solid color texture.
     *
     * @param size The size of the texture.
     * @param color The color of the texture.
     */
    Texture(const math::Vec2& size, Color color);

    /**
     * @brief Create a texture from an existing surface.
     *
     * @param sdlTexture An SDL texture object.
     */
    explicit Texture(SDL_Texture* sdlTexture);

    ~Texture()
    {
        if (texture)
            SDL_DestroyTexture(texture);
    }

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
     * @brief Get the SDL texture.
     *
     * @return The SDL texture.
     */
    [[nodiscard]] SDL_Texture* getSDLTexture() const;

    /**
     * @brief Loads the Texture from the given file
     *
     * @param path
     * @return true
     * @return false
     */
    bool loadFromFile(const std::string& path);

    /**
     * @brief Set the size of the texture rect.
     *
     * @param size The size of the texture rect.
     */
    void setSize(const math::Vec2& size);

    /**
     * @brief Scale the texture rect by a factor.
     *
     * @param factor The factor to scale by.
     */
    void scaleBy(float factor);

    /**
     * @brief Fit the texture rect to a width while maintaining the aspect ratio.
     *
     * @param width The width to fit to.
     */
    void fitWidth(float width);

    /**
     * @brief Fit the texture rect to a height while maintaining the aspect ratio.
     *
     * @param height The height to fit to.
     */
    void fitHeight(float height);

  private:
    SDL_Texture* texture = nullptr;
    Rect rect = {};

    void query();
};
} // namespace kn
