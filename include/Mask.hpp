#pragma once
#include <inttypes.h>
#include <vector>

namespace kn
{
namespace math
{
class Vec2;
}
class Surface;
struct Rect;

class Mask
{
  public:
    /**
     * @brief Construct a new Mask object from a surface.
     *
     * @param surface The surface to create the mask from.
     * @param alphaThreshold The alpha threshold to use when creating the mask. Pixels with an alpha
     * value below this threshold will be considered transparent.
     */
    Mask(const Surface& surface, uint8_t alphaThreshold = 1);
    ~Mask() = default;

    /**
     * @brief Check if the mask collides with another mask at the given offset.
     *
     * @param other The other mask to check for collision with.
     * @param offset The offset to apply to the other mask.
     * @return ``true`` if the masks collide, ``false`` otherwise.
     */
    bool collideMask(const Mask& other, const math::Vec2& offset) const;

    /**
     * @brief Check if the mask collides with another mask at the given rectangles.
     * 
     * @param other The other mask to check for collision with.
     * @param rectA The rectangle of the first mask.
     * @param rectB The rectangle of the second mask.
     * @return ``true`` if the masks collide, ``false`` otherwise.
     */
    bool collideMask(const Mask& other, const Rect& rectA, const Rect& rectB) const;

    /**
     * @brief Get whether the pixel is opaque or transparent. The threshold is taken into account.
     *
     * @param x The x coordinate of the pixel.
     * @param y The y coordinate of the pixel.
     * @return ``true`` if the pixel is opaque, ``false`` if it is transparent.
     */
    bool getPixel(int x, int y) const;

  protected:
    int width, height;
    std::vector<bool> maskData;
};
} // namespace kn
