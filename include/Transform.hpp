#pragma once

namespace kn
{
namespace math
{
class Vec2;
} // namespace math
class Surface;
namespace transform
{

/**
 * @brief Flip a surface horizontally and/or vertically.
 *
 * Creates a new Surface containing a mirrored copy of the input.
 *
 * @param surface        The source Surface to flip.
 * @param flipX          If true, flip along the X (horizontal) axis.
 * @param flipY          If true, flip along the Y (vertical) axis.
 * @return               A new Surface with the specified flips applied.
 */
Surface flip(const Surface& surface, bool flipX, bool flipY);

/**
 * @brief Scale a surface to an explicit size.
 *
 * Resizes the input surface to the given width and height, stretching or
 * shrinking as needed.
 *
 * @param surface        The source Surface to scale.
 * @param size           The target dimensions (x = width, y = height).
 * @return               A new Surface of the requested size.
 */
Surface scale(const Surface& surface, const math::Vec2& size);

/**
 * @brief Scale a surface by a uniform factor.
 *
 * Multiplies both the width and height of the input by the given factor.
 *
 * @param surface        The source Surface to scale.
 * @param factor         Scale multiplier (e.g. 0.5 shrinks to half, 2.0 doubles).
 * @return               A new Surface scaled by the factor.
 */
Surface scaleBy(const Surface& surface, double factor);

/**
 * @brief Rotate a surface by an angle around its center.
 *
 * Produces a new Surface rotated clockwise by the specified degrees.
 *
 * @param surface        The source Surface to rotate.
 * @param angle          Clockwise rotation angle in degrees.
 * @return               A new, rotated Surface (may have larger dimensions to fit).
 */
Surface rotate(const Surface& surface, double angle);

/**
 * @brief Apply a box (mean) blur to a surface.
 *
 * Performs a separable two‑pass box blur with a given radius.
 *
 * @param surface                The source Surface to blur.
 * @param radius                 Radius of the box kernel (in pixels).
 * @param repeatEdgePixels       If true, use edge‑pixel clamping rather than skipping.
 * @return                       A new Surface containing the blurred image.
 */
Surface boxBlur(const Surface& surface, int radius, bool repeatEdgePixels = true);

/**
 * @brief Apply a Gaussian blur to a surface.
 *
 * Uses a separable Gaussian kernel (σ ≈ radius/2) in two passes.
 *
 * @param surface                The source Surface to blur.
 * @param radius                 Radius of the Gaussian kernel (in pixels).
 * @param repeatEdgePixels       If true, clamp samples at the edges.
 * @return                       A new Surface containing the Gaussian‑blurred image.
 */
Surface gaussianBlur(const Surface& surface, int radius, bool repeatEdgePixels = true);

/**
 * @brief Invert the colors of a surface.
 *
 * Creates a photographic negative by flipping each pixel’s R, G, B channels.
 *
 * @param surface        The source Surface to invert.
 * @return               A new Surface with colors inverted (alpha preserved).
 */
Surface invert(const Surface& surface);

/**
 * @brief Convert a surface to grayscale.
 *
 * Applies the luminance formula (0.299 R + 0.587 G + 0.114 B) per pixel.
 *
 * @param surface        The source Surface to convert.
 * @return               A new Surface in grayscale (alpha preserved).
 */
Surface grayscale(const Surface& surface);

} // namespace transform
} // namespace kn
