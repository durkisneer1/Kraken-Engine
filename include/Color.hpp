#pragma once

#include <string_view>

namespace kn
{

struct Color
{
    /**
     * @brief The red value [0, 255]
     */
    uint8_t r = 0;
    /**
     * @brief The green value [0, 255]
     */
    uint8_t g = 0;
    /**
     * @brief The blue value [0, 255]
     */
    uint8_t b = 0;
    /**
     * @brief The alpha value [0, 255]
     */
    uint8_t a = 255;

    constexpr Color() = default;

    constexpr Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255)
        : r(red), g(green), b(blue), a(alpha)
    {
    }

    operator SDL_Color() const { return SDL_Color{r, g, b, a}; }
};

namespace color
{

/**
 * @brief Create a Color from a hexadecimal string.
 *
 * @param hex A hexadecimal color string.
 *            Supported formats include "#RRGGBB", "RRGGBB", "#RGB", or "RGB".
 * @return A Color object corresponding to the parsed hex value.
 */
Color fromHex(std::string_view hex);

/**
 * @brief Create a Color from HSV (hue, saturation, value) components.
 *
 * @param h Hue component, typically in [0.0f, 360.0f).
 * @param s Saturation component, in [0.0f, 1.0f].
 * @param v Value (brightness) component, in [0.0f, 1.0f].
 * @param a Alpha (opacity) component, in [0.0f, 1.0f]; defaults to 1.0f (fully opaque).
 * @return A Color object converted from the specified HSV(A) values.
 */
Color fromHSV(float h, float s, float v, float a = 1.0f);

/**
 * @brief Linearly interpolate between two Colors.
 *
 * @param a The start Color.
 * @param b The end Color.
 * @param t Interpolation factor, typically in [0.0, 1.0].
 *          A value of 0.0 yields Color a, 1.0 yields Color b.
 * @return A new Color that is the blend of a and b by factor t.
 */
Color lerp(const Color& a, const Color& b, double t);

/**
 * @brief Invert a Color by flipping its RGB components (alpha remains unchanged).
 *
 * @param color The Color to invert.
 * @return A new Color with each RGB channel set to (1.0 – original), preserving alpha.
 */
Color invert(const Color& color);

constexpr Color BLACK = {0, 0, 0};
constexpr Color WHITE = {255, 255, 255};
constexpr Color RED = {255, 0, 0};
constexpr Color GREEN = {0, 255, 0};
constexpr Color BLUE = {0, 0, 255};
constexpr Color YELLOW = {255, 255, 0};
constexpr Color MAGENTA = {255, 0, 255};
constexpr Color CYAN = {0, 255, 255};
constexpr Color GRAY = {128, 128, 128};
constexpr Color GREY = GRAY;
constexpr Color DARK_GRAY = {64, 64, 64};
constexpr Color DARK_GREY = DARK_GRAY;
constexpr Color LIGHT_GRAY = {192, 192, 192};
constexpr Color LIGHT_GREY = LIGHT_GRAY;
constexpr Color ORANGE = {255, 165, 0};
constexpr Color BROWN = {139, 69, 19};
constexpr Color PINK = {255, 192, 203};
constexpr Color PURPLE = {128, 0, 128};
constexpr Color NAVY = {0, 0, 128};
constexpr Color TEAL = {0, 128, 128};
constexpr Color OLIVE = {128, 128, 0};

} // namespace color
} // namespace kn
