#pragma once

#include <cstdint>


namespace kn::overflow
{
//@{
/**
 * @brief Checks if an overflow would occur in summation
 *
 * @param first first value
 * @param second second value
 * @return true if sum is valid, false otherwise
 */
bool isSumValid(const double& first, const double& second);

bool isSumValid(const float& first, const float& second);

bool isSumValid(const uint32_t& first, const uint32_t& second);

bool isSumValid(const uint64_t& first, const uint64_t& second);

bool isSumValid(const int32_t& first, const int32_t& second);

bool isSumValid(const int64_t& first, const int64_t& second);
//@}

//@{
/**
 * @brief Checks if an overflow would occur in multiplication
 *
 * @param first first value
 * @param second second value
 * @return true if product is valid, false otherwise
 */
bool isProductValid(const double& first, const double& second);

bool isProductValid(const float& first, const float& second);

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
bool closeToZero(const double& value, double tolerance = 0.0001);

bool closeToZero(const float& value, float tolerance = 0.0001f);
//@}

} // namespace kn::overflow


