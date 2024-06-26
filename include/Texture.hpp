#pragma once

#include <SDL.h>

#include "Math.hpp"
#include "Rect.hpp"

namespace kn
{
namespace math
{
class Vec2;
};

/**
 * @brief A texture object.
 */
class Texture final
{
  public:
    /**
     * @brief Create a texture.
     *
     * @param texture The SDL texture.
     *
     * @note This function is not meant to be used by the user.
     *
     * @see kn::cache::load()
     * @see kn::cache::create()
     * @see kn::cache::move()
     */
    explicit Texture(SDL_Texture* texture);

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
    math::Vec2 getSize() const;

    /**
     * @brief Get the rect of the texture.
     *
     * @return The rect of the texture.
     */
    Rect getRect() const;

    /**
     * @brief Get the SDL texture.
     *
     * @return The SDL texture.
     *
     * @note This function is not meant to be used by the user.
     */
    SDL_Texture* getSDLTexture() const;

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
