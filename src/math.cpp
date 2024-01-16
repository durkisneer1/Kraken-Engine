#include <algorithm>
#include <cmath>

#include "ErrorLogger.hpp"
#include "Math.hpp"

namespace kn
{

using overflow::closeToZero;
using overflow::isProductValid;
using overflow::isSumValid;

namespace math
{

Vec2::Vec2() : x(0.0), y(0.0), tolerance(0.0001) {}

Vec2 Vec2::ZERO() { return Vec2(); }

double Vec2::getLength() const
{
    if (!isProductValid(x, x) || !isProductValid(y, y))
    {
        WARN("Calculation of magnitude would result in overflow");
        return -1.0;
    }

    const double first = x * x;
    const double second = y * y;

    if (!isSumValid(first, second))
    {
        WARN("Calculation of magnitude would result in overflow");
        return -1.0;
    }

    return sqrt(first + second);
}

bool Vec2::normalize()
{
    const double c = getLength();
    if (c <= 0.0)
    {
        WARN("Cannot normalize vector either because it is the zero vector, or it would overflow");
        return false;
    }

    const double factor = 1 / c;
    if (!isProductValid(x, factor) || !isProductValid(y, factor))
    {
        WARN("Cannot normalize vector due to overflow");
        return false;
    }

    x /= c;
    y /= c;

    return true;
}

double Vec2::distanceTo(const Vec2& other) const
{
    if (!isSumValid(other.x, -x) || !isSumValid(other.y, -y))
    {
        WARN("Calculation would result in overflow");
        return -1.0;
    }

    const double dx = other.x - x;
    const double dy = other.y - y;

    return Vec2(dx, dy).getLength();
}

Vec2 Vec2::operator+(const Vec2& other) const { return Vec2(x + other.x, y + other.y); }

Vec2 Vec2::operator-(const Vec2& other) const { return *this + (-1.0 * other); }

Vec2& Vec2::operator+=(const Vec2& other)
{
    x += other.x;
    y += other.y;

    return *this;
}

bool Vec2::operator==(const Vec2& other) const
{
    if (!isSumValid(x, -other.x) || !isSumValid(y, -other.y))
    {
        TRACE("Vector comparison would result in overflow, they can't be the same");
        return false;
    }

    if (!closeToZero(x - other.x, tolerance) || !closeToZero(y - other.y, tolerance))
        return false;

    return true;
}

bool Vec2::operator!=(const Vec2& other) const { return !(*this == other); }

Vec2 clampVec(const Vec2& vec, const Vec2& min, const Vec2& max)
{
    Vec2 retVec;

    retVec.x = std::clamp(vec.x, min.x, max.x);
    retVec.y = std::clamp(vec.y, min.y, max.y);

    return retVec;
}

Vec2 lerpVec(const Vec2& a, const Vec2& b, double t)
{
    // TODO: figure out a way to signal if an overflow happens
    return a + (b - a) * t;
}

} // namespace math
} // namespace kn
