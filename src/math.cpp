#include <algorithm>
#include <cmath>

#include "ErrorLogger.hpp"
#include "Math.hpp"

namespace kn
{
using namespace overflow;

namespace math
{
Vec2::Vec2() : x(0.0), y(0.0), tolerance(1e-6) {}

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

double Vec2::angleTo(const Vec2& other) const
{
    const double numerator = this->dot(other);
    const double denominator = this->getLength() * other.getLength();
    if (denominator == 0.0f)
    {
        return 0.0f;
    }

    return acos(numerator / denominator);
}

double Vec2::dot(const Vec2& other) const { return x * other.x + y * other.y; }

double Vec2::cross(const Vec2& other) const
{
    double product = other.getLength() * this->getLength();
    double angle = this->angleTo(other);

    return product * sin(angle);
}

void Vec2::rotate(double angle)
{
    const double cosine = cos(angle * M_PI / 180);
    const double sine = sin(angle * M_PI / 180);
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
    double rads;
    if (x == 0)
        rads = (y > 0) ? M_PI_2 : 3 * M_PI_2;
    else
        rads = atan(y / x);

    const double azimuthalAngle = rads * 180 / M_PI;
    return {azimuthalAngle, radius};
}

Vec2 Vec2::fromPolar(double angle, double radius)
{
    Vec2 v;
    double angle = angle * M_PI / 180;
    v.x = radius * cos(angle);
    v.y = radius * sin(angle);
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
    double abdot = this->dot(other);
    double bbdot = other.dot(other);

    double frac = abdot / bbdot;

    return other * frac;
}

Vec2 Vec2::reject(const Vec2& other) { return other - this->project(other); }

Vec2 Vec2::reflect(const Vec2& other) const
{
    Vec2 otherNormalized = other.normalize();
    return *this - 2 * (this->dot(otherNormalized)) * otherNormalized;
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
        Vec2 v;
        v.x = 0;
        v.y = 0;
        return v;
    }

    const double factor = 1 / c;
    if (!isProductValid(x, factor) || !isProductValid(y, factor))
    {
        WARN("Cannot normalize vector due to overflow");
        Vec2 v;
        v.x = 0;
        v.y = 0;
        return v;
    }
    Vec2 v;
    v.x = x / c;
    v.y = x / c;

    return v;
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

} // namespace math
} // namespace kn
