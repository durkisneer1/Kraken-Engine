#include "MathOverflow.hpp"

namespace kn
{

namespace Overflow
{

bool isSumValid(const float64_t& first, const float64_t& second)
{
    if (first >= 0)
    {
        // check for overflowing the float64_t maximum
        if (second >= 0 && (first > std::numeric_limits<float64_t>::max() - second))
        {
            return false;
        }
    }
    else
    {
        // check for overflowing the negative of the float64_t max
        // note that std::numeric_limits<float64_t>::min() doesn't return a negative
        // but instead returns the minimum representable value that is as close to
        // zero as doubles can get without becoming zero
        if (second < 0 && (first < -std::numeric_limits<float64_t>::max() - second))
        {
            return false;
        }
    }

    return true;
}

bool isSumValid(const float32_t& first, const float32_t& second)
{
    if (first >= 0)
    {
        // check for overflowing the float32_t maximum
        if (second >= 0 && (first > std::numeric_limits<float32_t>::max() - second))
        {
            return false;
        }
    }
    else
    {
        // check for overflowing the negative of the float32_t max
        // note that std::numeric_limits<float32_t>::min() doesn't return a negative
        // but instead returns the minimum representable value that is as close to
        // zero as floats can get without becoming zero
        if (second < 0 && (first < -std::numeric_limits<float32_t>::max() - second))
        {
            return false;
        }
    }
    return true;
}

bool isSumValid(const uint32_t& first, const uint32_t& second)
{
    if (first > std::numeric_limits<uint32_t>::max() - second)
    {
        return false;
    }
    return true;
}

bool isSumValid(const uint64_t& first, const uint64_t& second)
{
    if (first > std::numeric_limits<uint64_t>::max() - second)
    {
        return false;
    }
    return true;
}

bool isSumValid(const int32_t& first, const int32_t& second)
{
    if (first >= 0)
    {
        // check for overflowing the int32_t maximum
        if (second >= 0 && (first > std::numeric_limits<int32_t>::max() - second))
        {
            return false;
        }
    }
    else
    {
        // check for overflowing the int32_t min
        if (second < 0 && (first < std::numeric_limits<int32_t>::min() - second))
        {
            return false;
        }
    }
    return true;
}

bool isSumValid(const int64_t& first, const int64_t& second)
{
    if (first >= 0)
    {
        // check for overflowing the int64_t maximum
        if (second >= 0 && (first > std::numeric_limits<int64_t>::max() - second))
        {
            return false;
        }
    }
    else
    {
        // check for overflowing the int64_t min
        if (second < 0 && (first < std::numeric_limits<int64_t>::min() - second))
        {
            return false;
        }
    }
    return true;
}

bool isProductValid(const float64_t& first, const float64_t& second)
{
    if (!std::isfinite(first) || !std::isfinite(second))
    {
        // one of them is NaN or inf
        return false;
    }

    float64_t absFirst = std::fabs(first);
    float64_t absSecond = std::fabs(second);

    if (absFirst > 1.0 && absSecond > 1.0)
    {
        if (absFirst > std::numeric_limits<float64_t>::max() / absSecond)
        {
            return false;
        }
    }

    return true;
}

bool isProductValid(const float32_t& first, const float32_t& second)
{
    if (!std::isfinite(first) || !std::isfinite(second))
    {
        // one of them is NaN or inf
        return false;
    }

    float32_t absFirst = std::fabs(first);
    float32_t absSecond = std::fabs(second);

    if (absFirst > 1.0 && absSecond > 1.0)
    {
        if (absFirst > std::numeric_limits<float32_t>::max() / absSecond)
        {
            return false;
        }
    }

    return true;
}

bool isProductValid(const uint32_t& first, const uint32_t& second)
{
    if (first > 0U && second > 0U)
    {
        if (first > std::numeric_limits<uint32_t>::max() / second)
        {
            return false;
        }
    }

    return true;
}

bool isProductValid(const uint64_t& first, const uint64_t& second)
{
    if (first > 0U && second > 0U)
    {
        if (first > std::numeric_limits<uint64_t>::max() / second)
        {
            return false;
        }
    }

    return true;
}

bool isProductValid(const int32_t& first, const int32_t& second)
{
    if (first != 0 && second != 0)
    {
        if ((first > 0 && second > 0) || (first < 0 && second < 0))
        {
            // result is positive, so check max
            if (first > std::numeric_limits<int32_t>::max() / second)
            {
                return false;
            }
            else if (first > 0)
            {
                if (second < -std::numeric_limits<int32_t>::max() / first)
                {
                    return false;
                }
            }
            else
            {
                if (first < -std::numeric_limits<int32_t>::max() / second)
                {
                    return false;
                }
            }
        }
    }

    return true;
}

bool isProductValid(const int64_t& first, const int64_t& second)
{
    if (first != 0 && second != 0)
    {
        if ((first > 0 && second > 0) || (first < 0 && second < 0))
        {
            // result is positive, so check max
            if (first > std::numeric_limits<int64_t>::max() / second)
            {
                return false;
            }
            else if (first > 0)
            {
                // must divide by positive
                if (second < std::numeric_limits<int64_t>::min() / first)
                {
                    return false;
                }
            }
            else
            {
                // must divide by positive
                if (first < std::numeric_limits<int64_t>::min() / second)
                {
                    return false;
                }
            }
        }
    }

    return true;
}

bool closeToZero(const float64_t& value, const float64_t tolerance)
{
    if (std::fabs(value) < tolerance)
    {
        return true;
    }

    return false;
}

bool closeToZero(const float32_t& value, const float32_t tolerance)
{
    if (std::fabs(value) < tolerance)
    {
        return true;
    }

    return false;
}

} // namespace Overflow
} // namespace kn