#pragma once

#include <SDL.h>
#include <string>

namespace kn
{
namespace math
{
class Vec2;
} // namespace math
class Rect;
struct Color;

class Surface
{
  public:
    /**
     * @brief Construct a new Surface object at the given size.
     *
     * @param size The size of the surface.
     */
    explicit Surface(const math::Vec2& size);

    /**
     * @brief Load an image from disk as a surface.
     *
     * @param filePath Path to the image file.
     */
    explicit Surface(const std::string& filePath);

    /**
     * @brief Construct a new Surface object from an existing SDL_Surface pointer.
     *
     * @param sdlSurface The SDL_Surface pointer to store in this object
     */
    explicit Surface(SDL_Surface* sdlSurface);

    Surface() = default;
    ~Surface();

    /**
     * @brief Load an image from disk as a surface.
     *
     * @param filePath Path to the image file.
     * @return ``true`` when successful, ``false`` on failure.
     */
    bool loadFromFile(const std::string& filePath);

    /**
     * @brief Create a surface of the given size.
     *
     * @param size The size of the surface.
     * @return ``true`` when successful, ``false`` on failure.
     */
    bool create(const math::Vec2& size);

    /**
     * @brief Create a surface from an existing SDL_Surface pointer.
     *
     * @param sdlSurface The SDL_Surface pointer to store in this object
     * @return ``true`` when successful, ``false`` on failure.
     */
    bool loadFromSDL(SDL_Surface* sdlSurface);

    /**
     * @brief Fill the surface with a color.
     *
     * @param color The color to fill the surface with.
     */
    void fill(const Color& color);

    /**
     * @brief Get the size of the surface.
     *
     * @return A `kn::math::Vec2` object containing the size of the surface.
     */
    math::Vec2 getSize() const;

    /**
     * @brief Get a rect object containing the size of the surface.
     *
     * @return A `kn::Rect` object.
     */
    Rect getRect() const;

    /**
     * @brief Get the pointer to the underlying SDL surface object.
     *
     * @return A pointer to the SDL surface object.
     */
    SDL_Surface* getSDL() const;

  protected:
    SDL_Surface* surface = nullptr;
};

} // namespace kn
