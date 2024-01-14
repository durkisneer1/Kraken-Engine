#ifndef MATH_OVERFLOW_HPP
#define MATH_OVERFLOW_HPP

#include <cmath>
#include <limits>
#include <stdint.h>

#include "Constants.hpp"

namespace kn
{

namespace Overflow
{

//@{
/**
 * @brief Checks if an overflow would occur in summation
 *
 * @param first first value
 * @param second second value
 * @return true if sum is valid, false otherwise
 */
bool isSumValid(const float64_t& first, const float64_t& second);

bool isSumValid(const float32_t& first, const float32_t& second);

bool isSumValid(const uint32_t& first, const uint32_t& second);

bool isSumValid(const uint64_t& first, const uint64_t& second);

bool isSumValid(const int32_t& first, const int32_t& second);

bool isSumValid(const int64_t& first, const int64_t& second);
//@}

//@{
/**
 * @brief Checks if an overflow would occur in multiplcation
 *
 * @param first first value
 * @param second second value
 * @return true if product is valid, false otherwise
 */
bool isProductValid(const float64_t& first, const float64_t& second);

bool isProductValid(const float32_t& first, const float32_t& second);

bool isProductValid(const uint32_t& first, const uint32_t& second);

bool isProductValid(const uint64_t& first, const uint64_t& second);

bool isProductValid(const int32_t& first, const int32_t& second);

bool isProductValid(const int64_t& first, const int64_t& second);
//@}

//@{
/**
 * @brief Checks if the value is close to zero
 *
 * @param value value to check
 * @param tolerance the accuracy to use, anything closer to 0 than this will be considered zero
 * @return true if close to zero, false otherwise
 */
bool closeToZero(const float64_t& value, const float64_t tolerance = 0.0001);

bool closeToZero(const float32_t& value, const float32_t tolerance = 0.0001f);
//@}

} // namespace Overflow

} // namespace kn

#endif // MATH_OVERFLOW_HPP