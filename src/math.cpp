#include <algorithm>
#define _USE_MATH_DEFINES
#include <math.h>

#include "ErrorLogger.hpp"
#include "Math.hpp"

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

void Vec2::rotate(double angle)
{
    double rad = toRadians(angle);
    const double cosine = cos(toRadians(rad));
    const double sine = sin(rad);
    x = x * cosine - y * sine;
    y = x * sine + y * cosine;
}

void Vec2::rotateRad(double angle)
{
    const double cosine = cos(angle);
    const double sine = sin(angle);
    x = x * cosine - y * sine;
    y = x * sine + y * cosine;
}

PolarCoordinate Vec2::asPolar()
{
    const double radius = this->getLength();
    const double azimuthalAngle = toDegrees(atan2(y, x));
    return {azimuthalAngle, radius};
}

Vec2 Vec2::fromPolar(double angle, double radius)
{
    Vec2 v;
    double rad = toRadians(angle);
    v.x = radius * cos(rad);
    v.y = radius * sin(rad);
    return v;
}

void Vec2::scaleToLengthIP(double value)
{
    this->normalizeIP();
    this->x *= value;
    this->y *= value;
}

Vec2 Vec2::scaleToLength(double value)
{
    Vec2 scaled = this->normalize() * value;
    return scaled;
}

Vec2 Vec2::project(const Vec2& other)
{
    double abdot = dot(*this, other);
    double bbdot = dot(other, other);

    double frac = abdot / bbdot;

    return other * frac;
}

Vec2 Vec2::reject(const Vec2& other) { return other - this->project(other); }

Vec2 Vec2::reflect(const Vec2& other) const
{
    Vec2 otherNormalized = other.normalize();
    return *this - 2 * dot(*this, otherNormalized) * otherNormalized;
}

bool Vec2::normalizeIP()
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

Vec2 Vec2::normalize() const
{
    const double c = getLength();
    if (c <= 0.0)
    {
        WARN("Cannot normalize vector either because it is the zero vector, or it would overflow");
        return {};
    }

    const double factor = 1 / c;
    if (!isProductValid(x, factor) || !isProductValid(y, factor))
    {
        WARN("Cannot normalize vector due to overflow");
        return {};
    }

    return {x / c, y / c};
}

double Vec2::distanceTo(const Vec2& other) const
{
    if (!isSumValid(other.x, -x) || !isSumValid(other.y, -y))
    {
        WARN("Calculation would result in overflow");
        return -1.0;
    }

    return (other - *this).getLength();
}

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
    // FIXME: Not the correct lerp formula
    return a + (b - a) * t;
}

double lerp(double a, double b, double t) { return a + (b - a) * t; }

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

double remap(double in_min, double in_max, double out_min, double out_max, double value)
{
    if (in_min == in_max)
    {
        WARN("in_min and in_max must not be equal.")
        return 0.0f;
    }

    double percentage = (value - in_min) / (in_max - in_min);

    return (double)(out_max - out_min) * (percentage);
}

double toDegrees(double angle) { return angle * 180 / M_PI; }

double toRadians(double angle) { return angle * M_PI / 180; }

double dot(const Vec2& a, const Vec2& b) { return a.x * b.x + a.y * b.y; }

double cross(const Vec2& a, const Vec2& b)
{
    double product = b.getLength() * a.getLength();
    double angle = angleBetween(a, b);

    return product * sin(angle);
}

double angleBetween(const Vec2& a, const Vec2& b)
{
    const double numerator = dot(a, b);
    const double denominator = a.getLength() * b.getLength();

    return (denominator == 0.0f) ? 0.0f : acos(numerator / denominator);
}

double angleOfDifference(const Vec2& a, const Vec2& b)
{
    Vec2 dVec = a - b;

    return toDegrees(atan2(dVec.y, dVec.x));
}

} // namespace math
} // namespace kn
