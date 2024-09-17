#pragma once

#include "ErrorLogger.hpp"
#include "Overflow.hpp"

namespace kn
{
using overflow::closeToZero;
using overflow::isProductValid;
using overflow::isSumValid;

namespace math
{

/**
 * @brief Polar coordinates representation.
 */
struct PolarCoordinate
{
    double angle;
    double radius;
};

/**
 * @brief A 2D vector.
 */
class Vec2
{
  public:
    double x;
    double y;

    Vec2();

    template <typename _first, typename _second>
    Vec2(_first x, _second y)
        : x(static_cast<double>(x)), y(static_cast<double>(y)), tolerance(0.0001)
    {
    }

    template <typename _first, typename _second>
    Vec2(_first x, _second y, double tolerance)
        : x(static_cast<double>(x)), y(static_cast<double>(y)), tolerance(tolerance)
    {
    }

    /**
     * @brief Get the length of the vector.
     * @return The length of the vector if no overflow happens, otherwise -1.0.
     */
    double getLength() const;

    /**
     * @brief Rotates a vector in-place by a given angle in degrees.
     * @param angle The angle in degrees.
     */
    void rotate(double angle);

    /**
     * @brief Rotates a vector in-place by a given angle in radians.
     * @param angle The angle in radians.
     */
    void rotateRad(double angle);

    /**
     * @brief Converts a vector into it's polar representation.
     * @return Returns a PolarCoordinate struct which contains an angle in degrees and the vector
     * magnitude as radius.
     */
    PolarCoordinate asPolar();

    /**
     * @brief Constructs a vector from it's polar representation.
     * @param angle The angle in degrees.
     * @param radius The radius.
     * @return Returns a vector from it's polar representation.
     */
    Vec2 fromPolar(double angle, double radius);

    /**
     * @brief Scales a vector in-place to a given scalar.
     * @param scalar The scalar to scale the vector to.
     */
    void scaleToLengthIP(double scalar);

    /**
     * @brief Scales a vector to a given value and returns it.
     * @param scalar The scalar to scale the vector to.
     * @return Returns a vector of magnitude equal to a given scalar while mantaining it's original
     * direction.
     */
    Vec2 scaleToLength(double scalar);

    /**
     * @brief Calculates the vector projection of this vector onto another vector.
     * @param other The vector to project onto.
     * @return Returns the projection of a vector onto another vector.
     */
    Vec2 project(const Vec2& other);

    /**
     * @brief Calculates the vector rejection of this vector onto another vector.
     * @param other The vector to reject onto.
     * @return Returns the vector rejection between two vectors.
     */
    Vec2 reject(const Vec2& other);

    /**
     * @brief Calculates the reflection of a vector onto another vector.
     * @param other The vector to reflect onto.
     * @return Returns the reflection of a vector onto another vector.
     */
    Vec2 reflect(const Vec2& other) const;

    /**
     * @brief Normalize the vector in-place. Fails if an overflow occurs or the vector is the zero
     * vector.
     */
    [[maybe_unused]] bool normalizeIP();

    /**
     * @brief Normalize the vector and returns it. Fails if an overflow occurs or the vector is the
     * zero vector.
     * @return A normalized vector.
     */
    Vec2 normalize() const;

    /**
     * @brief Get the distance to another vector.
     * @param other The vector to calculate the distance to.
     * @return The distance to another vector if no overflow happens, otherwise -1.0.
     */
    double distanceTo(const Vec2& other) const;

    template <typename T> Vec2 operator/(T scalar) const { return {x / scalar, y / scalar}; }

    Vec2 operator+(const Vec2& other) const;

    Vec2 operator-(const Vec2& other) const;

    Vec2& operator+=(const Vec2& other);

    bool operator==(const Vec2& other) const;

    bool operator!=(const Vec2& other) const;

  protected:
    double tolerance; //!< the accuracy with which comparisons are made
};

/**
 * @brief Clamp a vector.
 * @param vec The vector to clamp.
 * @param min The minimum value.
 * @param max The maximum value.
 * @return The clamped vector.
 */
Vec2 clampVec(const Vec2& vec, const Vec2& min, const Vec2& max);

/**
 * @brief Linearly interpolate a vector.
 * @param a The start position.
 * @param b The end position.
 * @param t The time in seconds.
 * @return The interpolated vector.
 */
Vec2 lerpVec(const Vec2& a, const Vec2& b, double t);

/**
 * @brief Linear interpolate a value
 * @param a The starting value.
 * @param b The final value.
 * @param t The time in seconds.
 * @return The interpolated value.
 */
double lerp(double a, double b, double t);

/**
 * @brief  Remaps a value from an input range to an output range
 * @param in_min The minimum value of the input range.
 * @param in_max The maximum value of the input range.
 * @param out_min The minimum value of the output range.
 * @param out_max The maximum value of the output range.
 * @param value The value to remap.
 * @return Returns a value that was mapped from [in_min, in_max] to [out_min, out_max], if in_min
 * and in_max are the same then it returns 0 and raises a WARN message.
 */
double remap(double in_min, double in_max, double out_min, double out_max, double value);

/**
 * @brief Converts radians to degrees.
 * @param angle The angle in radians.
 * @return Returns the representation of an angle in degrees.
 */
double toDegrees(double angle);

/**
 * @brief Converts degrees to radians.
 * @param angle The angle in degrees.
 * @return Returns the representation of an angle in radians.
 */
double toRadians(double angle);

/**
 * @brief Get the dot product of two vectors.
 * @param a The lhs vector.
 * @param b The rhs vector.
 * @return The dot product of two vectors.
 */
double dot(const Vec2& a, const Vec2& b);

/**
 * @brief Get the cross product of two vectors.
 * @param a The lhs vector.
 * @param b The rhs vector.
 * @return The cross product of two vectors.
 */
double cross(const Vec2& a, const Vec2& b);

/**
 * @brief Calculates the angle in radians between two vectors.
 * @param a The lhs vector.
 * @param b The rhs vector.
 * @return The angle in radians between two vectors.
 */
double angleBetween(const Vec2& a, const Vec2& b);

/**
 * @brief Calculates the angle in radians between the heads of the vectors.
 * @param a The lhs vector.
 * @param b The rhs vector.
 * @return The angle in radians between the heads of the vectors.
 */
double angleOfDifference(const Vec2& a, const Vec2& b);

template <typename T> Vec2 operator*(const T& lhs, const Vec2& rhs)
{
    if (!isProductValid(static_cast<double>(lhs), rhs.x) ||
        !isProductValid(static_cast<double>(lhs), rhs.y))
    {
        WARN("Multiplication would result in overflow");
        return {};
    }

    const double x = lhs * rhs.x;
    const double y = lhs * rhs.y;

    return Vec2(x, y);
}

template <typename T> Vec2 operator*(const Vec2& lhs, const T& rhs) { return rhs * lhs; }

} // namespace math
} // namespace kn
