#include <stdint.h>

#include <gtest/gtest.h>

#include "Constants.hpp"
#include "Overflow.hpp"

namespace
{
using kn::overflow::isProductValid;
using kn::overflow::isSumValid;

class DoubleOverflowTest : public ::testing::Test
{
  protected:
    DoubleOverflowTest() : doubleMax(std::numeric_limits<double>::max()) {}

    virtual ~DoubleOverflowTest() {}

    virtual void SetUp() {}

    virtual void TearDown() {}

    const double doubleMax;
};

TEST_F(DoubleOverflowTest, SumOfDoubleMax) { EXPECT_FALSE(isSumValid(doubleMax, doubleMax)); }

TEST_F(DoubleOverflowTest, SumOfNegativeDoubleMax)
{
    EXPECT_FALSE(isSumValid(-doubleMax, -doubleMax));
}

TEST_F(DoubleOverflowTest, SumOfHalfAndThreeFifthsDoubleMax)
{
    const double half = doubleMax / 2;
    const double threeFifths = (double)3 / 5 * doubleMax;
    EXPECT_FALSE(isSumValid(half, threeFifths));
}

TEST_F(DoubleOverflowTest, SumOfDoubleMaxAndNegativeDoubleMax)
{
    EXPECT_TRUE(isSumValid(doubleMax, -doubleMax));
}

TEST_F(DoubleOverflowTest, SumOfNegativeDoubleMaxAndDoubleMax)
{
    EXPECT_TRUE(isSumValid(-doubleMax, doubleMax));
}

TEST_F(DoubleOverflowTest, SumOfZeroAndDoubleMax) { EXPECT_TRUE(isSumValid(0.0, doubleMax)); }

TEST_F(DoubleOverflowTest, SumOfDoubleMaxAndZero) { EXPECT_TRUE(isSumValid(doubleMax, 0.0)); }

TEST_F(DoubleOverflowTest, SumOfTwoFifthsDoubleMax)
{
    const double twoFifths = (double)2 / 5 * doubleMax;

    EXPECT_TRUE(isSumValid(twoFifths, twoFifths));
}

class FloatOverflowTest : public ::testing::Test
{
  protected:
    FloatOverflowTest() : floatMax(std::numeric_limits<float>::max()) {}

    virtual ~FloatOverflowTest() {}

    virtual void SetUp() {}

    virtual void TearDown() {}

    const float floatMax;
};

TEST_F(FloatOverflowTest, SumOfFloatMax) { EXPECT_FALSE(isSumValid(floatMax, floatMax)); }

TEST_F(FloatOverflowTest, SumOfNegativeFloatMax) { EXPECT_FALSE(isSumValid(-floatMax, -floatMax)); }

TEST_F(FloatOverflowTest, SumOfHalfAndThreeFifthsFloatMax)
{
    const float half = floatMax / 2;
    const float threeFifths = (float)3 / 5 * floatMax;
    EXPECT_FALSE(isSumValid(half, threeFifths));
}

TEST_F(FloatOverflowTest, SumOfFloatMaxAndNegativeFloatMax)
{
    EXPECT_TRUE(isSumValid(floatMax, -floatMax));
}

TEST_F(FloatOverflowTest, SumOfNegativeFloatMaxAndFloatMax)
{
    EXPECT_TRUE(isSumValid(-floatMax, floatMax));
}

TEST_F(FloatOverflowTest, SumOfZeroAndFloatMax) { EXPECT_TRUE(isSumValid(0.0f, floatMax)); }

TEST_F(FloatOverflowTest, SumOfFloatMaxAndZero) { EXPECT_TRUE(isSumValid(floatMax, 0.0f)); }

TEST_F(FloatOverflowTest, SumOfTwoFifthsFloatMax)
{
    const float twoFifths = (float)2 / 5 * floatMax;

    EXPECT_TRUE(isSumValid(twoFifths, twoFifths));
}

class UnsignedFourByteIntTest : public ::testing::Test
{
  protected:
    UnsignedFourByteIntTest()
        : max(std::numeric_limits<uint32_t>::max()), min(std::numeric_limits<uint32_t>::min())
    {
    }

    virtual ~UnsignedFourByteIntTest() {}

    virtual void SetUp() {}

    virtual void TearDown() {}

    const uint32_t max;
    const uint32_t min;
};

TEST_F(UnsignedFourByteIntTest, SumOfMaxValues) { EXPECT_FALSE(isSumValid(max, max)); }

TEST_F(UnsignedFourByteIntTest, SumOfMinValues) { EXPECT_TRUE(isSumValid(min, min)); }

TEST_F(UnsignedFourByteIntTest, SumOfHalfAndThreeFifthsMax)
{
    const uint32_t threeFifths = (double)3 / 5 * max;
    const uint32_t half = (double)1 / 2 * max;

    EXPECT_FALSE(isSumValid(threeFifths, half));
}

TEST_F(UnsignedFourByteIntTest, SumOfTwoFifthsMax)
{
    const uint32_t twoFifths = (double)2 / 5 * max;

    EXPECT_TRUE(isSumValid(twoFifths, twoFifths));
}

class UnsignedEightByteIntTest : public ::testing::Test
{
  protected:
    UnsignedEightByteIntTest()
        : max(std::numeric_limits<uint64_t>::max()), min(std::numeric_limits<uint64_t>::min())
    {
    }

    virtual ~UnsignedEightByteIntTest() {}

    virtual void SetUp() {}

    virtual void TearDown() {}

    const uint64_t max;
    const uint64_t min;
};

TEST_F(UnsignedEightByteIntTest, SumOfMaxValues) { EXPECT_FALSE(isSumValid(max, max)); }

TEST_F(UnsignedEightByteIntTest, SumOfMinValues) { EXPECT_TRUE(isSumValid(min, min)); }

TEST_F(UnsignedEightByteIntTest, SumOfHalfAndThreeFifthsMax)
{
    const uint64_t threeFifths = (double)3 / 5 * max;
    const uint64_t half = (double)1 / 2 * max;

    EXPECT_FALSE(isSumValid(threeFifths, half));
}

TEST_F(UnsignedEightByteIntTest, SumOfTwoFifthsMax)
{
    const uint64_t twoFifths = (double)2 / 5 * max;

    EXPECT_TRUE(isSumValid(twoFifths, twoFifths));
}

class SignedFourByteIntTest : public ::testing::Test
{
  protected:
    SignedFourByteIntTest()
        : max(std::numeric_limits<int32_t>::max()), min(std::numeric_limits<int32_t>::min())
    {
    }

    virtual ~SignedFourByteIntTest() {}

    virtual void SetUp() {}

    virtual void TearDown() {}

    const int32_t max;
    const int32_t min;
};

TEST_F(SignedFourByteIntTest, SumOfMaxValues) { EXPECT_FALSE(isSumValid(max, max)); }

TEST_F(SignedFourByteIntTest, SumOfMinValues) { EXPECT_FALSE(isSumValid(min, min)); }

TEST_F(SignedFourByteIntTest, SumOfHalfAndThreeFifthsMax)
{
    const int32_t threeFifths = (double)3 / 5 * max;
    const int32_t half = (double)1 / 2 * max;

    EXPECT_FALSE(isSumValid(threeFifths, half));
}

TEST_F(SignedFourByteIntTest, SumOfTwoFifthsMax)
{
    const int32_t twoFifths = (double)2 / 5 * max;

    EXPECT_TRUE(isSumValid(twoFifths, twoFifths));
}

TEST_F(SignedFourByteIntTest, SumOfHalfMaxAndHalfMin)
{
    const int32_t halfMax = (double)1 / 2 * max;
    const int32_t halfMin = (double)1 / 2 * min;

    EXPECT_TRUE(isSumValid(halfMax, halfMin));
}

TEST_F(SignedFourByteIntTest, SumOfMaxAndMin) { EXPECT_TRUE(isSumValid(max, min)); }

class SignedEightByteIntTest : public ::testing::Test
{
  protected:
    SignedEightByteIntTest()
        : max(std::numeric_limits<int64_t>::max()), min(std::numeric_limits<int64_t>::min())
    {
    }

    virtual ~SignedEightByteIntTest() {}

    virtual void SetUp() {}

    virtual void TearDown() {}

    const int64_t max;
    const int64_t min;
};

TEST_F(SignedEightByteIntTest, SumOfMaxValues) { EXPECT_FALSE(isSumValid(max, max)); }

TEST_F(SignedEightByteIntTest, SumOfMinValues) { EXPECT_FALSE(isSumValid(min, min)); }

TEST_F(SignedEightByteIntTest, SumOfHalfAndThreeFifthsMax)
{
    const int64_t threeFifths = (double)3 / 5 * max;
    const int64_t half = (double)1 / 2 * max;

    EXPECT_FALSE(isSumValid(threeFifths, half));
}

TEST_F(SignedEightByteIntTest, SumOfTwoFifthsMax)
{
    const int64_t twoFifths = (double)2 / 5 * max;

    EXPECT_TRUE(isSumValid(twoFifths, twoFifths));
}

TEST_F(SignedEightByteIntTest, SumOfHalfMaxAndHalfMin)
{
    const int64_t halfMax = (double)1 / 2 * max;
    const int64_t halfMin = (double)1 / 2 * min;

    EXPECT_TRUE(isSumValid(halfMax, halfMin));
}

TEST_F(SignedEightByteIntTest, SumOfMaxAndMin) { EXPECT_TRUE(isSumValid(max, min)); }

} // namespace