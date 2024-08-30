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
     * @brief Get a vector with all components set to 0.
     *
     * @return The zero vector.
     */
    static Vec2 ZERO();

    /**
     * @brief Get the length of the vector.
     * @return The length of the vector if no overflow happens, otherwise -1.0
     */
    double getLength() const;

    /**
     * @brief Normalize the vector in-place. Fails if an overflow occurs or the vector is the zero
     * vector
     */
    [[maybe_unused]] bool normalize();

    /**
     * @brief Get the distance to another vector.
     *
     * @param other The other vector.
     *
     * @return The distance to another vector if no overflow happens, otherwise -1.0
     */
    double distanceTo(const Vec2& other) const;

    template <typename T> Vec2 operator/(T scalar) const { return Vec2(x / scalar, y / scalar); }

    /**
     * @brief Adds two vectors
     *
     * @param other the other vector
     * @return a vector sum of the other two, or the zero vector on overflow
     */
    Vec2 operator+(const Vec2& other) const;

    /**
     * @brief Subtracts two vectors
     *
     * @param other the subtracted vector
     * @return a vector difference of the other two, or the zero vector on overflow
     */
    Vec2 operator-(const Vec2& other) const;

    /**
     * @brief in-place addition of another vector to this
     *
     * @param other the other vector
     * @return reference to *this
     */
    Vec2& operator+=(const Vec2& other);

    /**
     * @brief Checks if two vectors are the same
     *
     * @param other the vector to compare to
     * @return true if the vectors are close to the same, false otherwise
     */
    bool operator==(const Vec2& other) const;

    /**
     * @brief Checks if two vectors are different
     *
     * @param other the vector to compare to
     * @return true if the vectors are not close to the same, false otherwise
     */
    bool operator!=(const Vec2& other) const;

  protected:
    double tolerance; //!< the accuracy with which comparisons are made
};

/**
 * @brief Clamp a vector.
 *
 * @param vec The vector to clamp.
 * @param min The minimum value.
 * @param max The maximum value.
 *
 * @return The clamped vector.
 */
Vec2 clampVec(const Vec2& vec, const Vec2& min, const Vec2& max);

/**
 * @brief Linearly interpolate a vector.
 *
 * @param a The first vector.
 * @param b The second vector.
 * @param t The time.
 *
 * @return The interpolated vector.
 */
Vec2 lerpVec(const Vec2& a, const Vec2& b, double t);

/**
 * @brief Multiplies a vector by a constant
 *
 * @tparam T type of the constant
 * @param lhs the constant
 * @param rhs the vector
 * @return A vector scaled by the constant
 */
template <typename T> Vec2 operator*(const T& lhs, const Vec2& rhs)
{
    if (!isProductValid(static_cast<double>(lhs), rhs.x) ||
        !isProductValid(static_cast<double>(lhs), rhs.y))
    {
        WARN("Multiplication would result in overflow");
        return Vec2::ZERO();
    }

    const double x = lhs * rhs.x;
    const double y = lhs * rhs.y;

    return Vec2(x, y);
}

/**
 * @brief Multiplies a vector by a constant
 *
 * @tparam T type of the constant
 * @param lhs the vector
 * @param rhs the constant
 * @return A vector scaled by the constant
 */
template <typename T> Vec2 operator*(const Vec2& lhs, const T& rhs) { return rhs * lhs; }

} // namespace math
} // namespace kn
