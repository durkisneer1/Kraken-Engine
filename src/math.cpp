#include "Math.hpp"
#include "ErrorLogger.hpp"
#include <algorithm>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

namespace kn
{
using namespace overflow;

namespace math
{
Vec2::Vec2() : x(0.0), y(0.0), tolerance(1e-6) {}

double Vec2::getLength() const
{
    if (!isProductValid(x, x) || !isProductValid(y, y))
    {
        WARN("Calculation of magnitude would result in overflow")
        return -1.0;
    }

    const double first = x * x;
    const double second = y * y;

    if (!isSumValid(first, second))
    {
        WARN("Calculation of magnitude would result in overflow")
        return -1.0;
    }

    return sqrt(first + second);
}

double Vec2::getAngle() const { return toDegrees(atan2(y, x)); }

void Vec2::rotate(const double angle) { rotateRad(toRadians(angle)); }

void Vec2::rotateRad(const double angle)
{
    const double cosine = cos(angle);
    const double sine = sin(angle);
    const double oldX = x;

    x = oldX * cosine - y * sine;
    y = oldX * sine + y * cosine;
}

PolarCoordinate Vec2::asPolar() const
{
    const double radius = this->getLength();
    const double azimuthalAngle = toDegrees(atan2(y, x));
    return {azimuthalAngle, radius};
}

void Vec2::scaleToLength(const double scalar)
{
    this->normalize();
    this->x *= scalar;
    this->y *= scalar;
}

Vec2 Vec2::project(const Vec2& other) const
{
    const double abDot = dot(*this, other);
    const double bbDot = dot(other, other);

    const double frac = abDot / bbDot;

    return other * frac;
}

Vec2 Vec2::reject(const Vec2& other) const { return other - this->project(other); }

Vec2 Vec2::reflect(const Vec2& other) const
{
    const Vec2 otherNormalized = math::normalize(other);
    return *this - 2 * dot(*this, otherNormalized) * otherNormalized;
}

bool Vec2::normalize()
{
    const double c = getLength();
    if (c <= 0.0)
    {
        WARN("Cannot normalize vector either because it is the zero vector, or it would overflow")
        return false;
    }

    if (const double factor = 1 / c; !isProductValid(x, factor) || !isProductValid(y, factor))
    {
        WARN("Cannot normalize vector due to overflow")
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
        WARN("Calculation would result in overflow")
        return -1.0;
    }

    return (other - *this).getLength();
}

Vec2 normalize(const Vec2& vec)
{
    const double c = vec.getLength();
    if (c <= 0.0)
    {
        WARN("Cannot normalize vector either because it is the zero vector, or it would overflow")
        return {};
    }

    if (const double factor = 1 / c;
        !isProductValid(vec.x, factor) || !isProductValid(vec.y, factor))
    {
        WARN("Cannot normalize vector due to overflow")
        return {};
    }

    return {vec.x / c, vec.y / c};
}

Vec2 scaleToLength(const Vec2& vec, const double scalar)
{
    const Vec2 scaled = normalize(vec) * scalar;
    return scaled;
}

Vec2 fromPolar(const double angle, const double radius)
{
    const double rad = toRadians(angle);
    double x = radius * cos(rad);
    double y = radius * sin(rad);
    return {x, y};
}

Vec2 clampVec(const Vec2& vec, const Vec2& min, const Vec2& max)
{
    double x = std::clamp(vec.x, min.x, max.x);
    double y = std::clamp(vec.y, min.y, max.y);

    return {x, y};
}

Vec2 lerpVec(const Vec2& a, const Vec2& b, const double t)
{
    // TODO: figure out a way to signal if an overflow happens
    return a + (b - a) * t;
}

double lerp(const double a, const double b, const double t) { return a + (b - a) * t; }

Vec2 Vec2::operator+(const Vec2& other) const { return {x + other.x, y + other.y}; }

Vec2 Vec2::operator-(const Vec2& other) const { return *this + -1.0 * other; }

Vec2 Vec2::operator-() const { return {-x, -y}; }

Vec2& Vec2::operator+=(const Vec2& other)
{
    x += other.x;
    y += other.y;

    return *this;
}

Vec2& Vec2::operator-=(const Vec2& other)
{
    x -= other.x;
    y -= other.y;

    return *this;
}

bool Vec2::operator==(const Vec2& other) const
{
    if (!isSumValid(x, -other.x) || !isSumValid(y, -other.y))
    {
        TRACE("Vector comparison would result in overflow, they can't be the same")
        return false;
    }

    if (!closeToZero(x - other.x, tolerance) || !closeToZero(y - other.y, tolerance))
        return false;

    return true;
}

bool Vec2::operator!=(const Vec2& other) const { return !(*this == other); }

bool Vec2::operator<(const Vec2& other) const { return (x < other.x && y < other.y); }

bool Vec2::operator>(const Vec2& other) const { return (x > other.x && y > other.y); }

bool Vec2::operator<=(const Vec2& other) const { return !(*this > other); }

bool Vec2::operator>=(const Vec2& other) const { return !(*this < other); }

double remap(const double in_min, const double in_max, const double out_min, const double out_max,
             const double value)
{
    if (in_min == in_max)
    {
        WARN("in_min and in_max must not be equal.")
        return 0.0f;
    }

    const double percentage = (value - in_min) / (in_max - in_min);

    return (out_max - out_min) * percentage;
}

double toDegrees(const double angle) { return angle * 180 / M_PI; }

double toRadians(const double angle) { return angle * M_PI / 180; }

double dot(const Vec2& a, const Vec2& b) { return a.x * b.x + a.y * b.y; }

double cross(const Vec2& a, const Vec2& b)
{
    const double product = b.getLength() * a.getLength();
    const double angle = angleBetween(a, b);

    return product * sin(angle);
}

double angleBetween(const Vec2& a, const Vec2& b)
{
    const double numerator = dot(a, b);
    const double denominator = a.getLength() * b.getLength();

    return (denominator == 0.0f) ? 0.0f : acos(numerator / denominator);
}

std::ostream& operator<<(std::ostream& os, const Vec2& vec)
{
    os << '(' << vec.x << ", " << vec.y << ')';
    return os;
}

} // namespace math
} // namespace kn
