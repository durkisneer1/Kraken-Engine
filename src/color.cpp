#include "Color.hpp"
#include "Constants.hpp"

#include <cmath>
#include <iomanip>

namespace kn::color
{

Color fromHex(std::string_view hex)
{
    if (hex.empty())
        return Color{0, 0, 0, 255};

    if (hex[0] == '#')
        hex.remove_prefix(1);

    auto hexToByte = [](std::string_view str) -> uint8_t
    {
        uint32_t byte;
        std::stringstream ss;
        ss << std::hex << str;
        ss >> byte;
        return static_cast<uint8_t>(byte);
    };

    if (hex.length() == 6)
    {
        // RRGGBB
        return Color{hexToByte(hex.substr(0, 2)), hexToByte(hex.substr(2, 2)),
                     hexToByte(hex.substr(4, 2)), 255};
    }
    else if (hex.length() == 8)
    {
        // RRGGBBAA
        return Color{hexToByte(hex.substr(0, 2)), hexToByte(hex.substr(2, 2)),
                     hexToByte(hex.substr(4, 2)), hexToByte(hex.substr(6, 2))};
    }
    else if (hex.length() == 3)
    {
        // RGB → duplicate each
        return Color{hexToByte(std::string(2, hex[0])), hexToByte(std::string(2, hex[1])),
                     hexToByte(std::string(2, hex[2])), 255};
    }
    else if (hex.length() == 4)
    {
        // RGBA → duplicate each
        return Color{hexToByte(std::string(2, hex[0])), hexToByte(std::string(2, hex[1])),
                     hexToByte(std::string(2, hex[2])), hexToByte(std::string(2, hex[3]))};
    }

    // Invalid format fallback
    return Color{0, 0, 0, 255};
}

Color fromHSV(float h, float s, float v, float a)
{
    float c = v * s;
    float x = c * (1 - std::fabs(fmod(h / 60.0f, 2) - 1));
    float m = v - c;

    float r, g, b;

    if (h < 60)
    {
        r = c;
        g = x;
        b = 0;
    }
    else if (h < 120)
    {
        r = x;
        g = c;
        b = 0;
    }
    else if (h < 180)
    {
        r = 0;
        g = c;
        b = x;
    }
    else if (h < 240)
    {
        r = 0;
        g = x;
        b = c;
    }
    else if (h < 300)
    {
        r = x;
        g = 0;
        b = c;
    }
    else
    {
        r = c;
        g = 0;
        b = x;
    }

    return {static_cast<uint8_t>((r + m) * 255), static_cast<uint8_t>((g + m) * 255),
            static_cast<uint8_t>((b + m) * 255), static_cast<uint8_t>(a * 255)};
}

Color lerp(const Color& a, const Color& b, double t)
{
    return {
        static_cast<uint8_t>(a.r + (b.r - a.r) * t), static_cast<uint8_t>(a.g + (b.g - a.g) * t),
        static_cast<uint8_t>(a.b + (b.b - a.b) * t), static_cast<uint8_t>(a.a + (b.a - a.a) * t)};
}

Color invert(const Color& color)
{
    return {static_cast<uint8_t>(255 - color.r), static_cast<uint8_t>(255 - color.g),
            static_cast<uint8_t>(255 - color.b), color.a};
}

} // namespace kn::color