#include <cstdint>

#include <gtest/gtest.h>

#include "Constants.hpp"
#include "Overflow.hpp"
#include "TestBase.hpp"

namespace
{
using kn::overflow::isProductValid;
using kn::overflow::isSumValid;

class DoubleOverflowTest : public TestBase
{
  protected:
    DoubleOverflowTest() : doubleMax(std::numeric_limits<double>::max()) {}

    ~DoubleOverflowTest() override = default;

    void SetUp() override {}

    void TearDown() override {}

    const double doubleMax;
};

TEST_F(DoubleOverflowTest, SumOfDoubleMax) { EXPECT_FALSE(isSumValid(doubleMax, doubleMax)); }

TEST_F(DoubleOverflowTest, SumOfNegativeDoubleMax)
{
    EXPECT_FALSE(isSumValid(-doubleMax, -doubleMax));
}

TEST_F(DoubleOverflowTest, SumOfHalfAndThreeFifthsDoubleMax)
{
    const double half = doubleMax / 2.0;
    const double threeFifths = 3.0 / 5.0 * doubleMax;
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
    const double twoFifths = 2.0 / 5.0 * doubleMax;

    EXPECT_TRUE(isSumValid(twoFifths, twoFifths));
}

class FloatOverflowTest : public ::testing::Test
{
  protected:
    FloatOverflowTest() : floatMax(std::numeric_limits<float>::max()) {}

    ~FloatOverflowTest() override = default;

    void SetUp() override {}

    void TearDown() override {}

    const float floatMax;
};

TEST_F(FloatOverflowTest, SumOfFloatMax) { EXPECT_FALSE(isSumValid(floatMax, floatMax)); }

TEST_F(FloatOverflowTest, SumOfNegativeFloatMax) { EXPECT_FALSE(isSumValid(-floatMax, -floatMax)); }

TEST_F(FloatOverflowTest, SumOfHalfAndThreeFifthsFloatMax)
{
    const float half = floatMax / 2.0f;
    const float threeFifths = 3.0f / 5.0f * floatMax;
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
    const float twoFifths = 2.0f / 5.0f * floatMax;

    EXPECT_TRUE(isSumValid(twoFifths, twoFifths));
}

class UnsignedFourByteIntTest : public ::testing::Test
{
  protected:
    UnsignedFourByteIntTest()
        : max(std::numeric_limits<uint32_t>::max()), min(std::numeric_limits<uint32_t>::min())
    {
    }

    ~UnsignedFourByteIntTest() override = default;

    void SetUp() override {}

    void TearDown() override {}

    const uint32_t max;
    const uint32_t min;
};

TEST_F(UnsignedFourByteIntTest, SumOfMaxValues) { EXPECT_FALSE(isSumValid(max, max)); }

TEST_F(UnsignedFourByteIntTest, SumOfMinValues) { EXPECT_TRUE(isSumValid(min, min)); }

TEST_F(UnsignedFourByteIntTest, SumOfHalfAndThreeFifthsMax)
{
    const uint32_t threeFifths = 3.0 / 5 * max;
    const uint32_t half = 1.0 / 2 * max;

    EXPECT_FALSE(isSumValid(threeFifths, half));
}

TEST_F(UnsignedFourByteIntTest, SumOfTwoFifthsMax)
{
    const uint32_t twoFifths = 2.0 / 5 * max;

    EXPECT_TRUE(isSumValid(twoFifths, twoFifths));
}

class UnsignedEightByteIntTest : public ::testing::Test
{
  public:
    UnsignedEightByteIntTest()
        : max(std::numeric_limits<uint64_t>::max()), min(std::numeric_limits<uint64_t>::min())
    {
    }

    ~UnsignedEightByteIntTest() override = default;

  protected:
    void SetUp() override {}

    void TearDown() override {}

    const uint64_t max;
    const uint64_t min;
};

TEST_F(UnsignedEightByteIntTest, SumOfMaxValues) { EXPECT_FALSE(isSumValid(max, max)); }

TEST_F(UnsignedEightByteIntTest, SumOfMinValues) { EXPECT_TRUE(isSumValid(min, min)); }

TEST_F(UnsignedEightByteIntTest, SumOfHalfAndThreeFifthsMax)
{
    const uint64_t threeFifths = 3.0 / 5 * max;
    const uint64_t half = 1.0 / 2 * max;

    EXPECT_FALSE(isSumValid(threeFifths, half));
}

TEST_F(UnsignedEightByteIntTest, SumOfTwoFifthsMax)
{
    const uint64_t twoFifths = 2.0 / 5 * max;

    EXPECT_TRUE(isSumValid(twoFifths, twoFifths));
}

class SignedFourByteIntTest : public ::testing::Test
{
  protected:
    SignedFourByteIntTest()
        : max(std::numeric_limits<int32_t>::max()), min(std::numeric_limits<int32_t>::min())
    {
    }

    ~SignedFourByteIntTest() override = default;

    void SetUp() override {}

    void TearDown() override {}

    const int32_t max;
    const int32_t min;
};

TEST_F(SignedFourByteIntTest, SumOfMaxValues) { EXPECT_FALSE(isSumValid(max, max)); }

TEST_F(SignedFourByteIntTest, SumOfMinValues) { EXPECT_FALSE(isSumValid(min, min)); }

TEST_F(SignedFourByteIntTest, SumOfHalfAndThreeFifthsMax)
{
    const int32_t threeFifths = 3.0 / 5 * max;
    const int32_t half = 1.0 / 2 * max;

    EXPECT_FALSE(isSumValid(threeFifths, half));
}

TEST_F(SignedFourByteIntTest, SumOfTwoFifthsMax)
{
    const int32_t twoFifths = 2.0 / 5 * max;

    EXPECT_TRUE(isSumValid(twoFifths, twoFifths));
}

TEST_F(SignedFourByteIntTest, SumOfHalfMaxAndHalfMin)
{
    const int32_t halfMax = 1.0 / 2 * max;
    const int32_t halfMin = 1.0 / 2 * min;

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

    ~SignedEightByteIntTest() override = default;

    void SetUp() override {}

    void TearDown() override {}

    const int64_t max;
    const int64_t min;
};

TEST_F(SignedEightByteIntTest, SumOfMaxValues) { EXPECT_FALSE(isSumValid(max, max)); }

TEST_F(SignedEightByteIntTest, SumOfMinValues) { EXPECT_FALSE(isSumValid(min, min)); }

TEST_F(SignedEightByteIntTest, SumOfHalfAndThreeFifthsMax)
{
    const int64_t threeFifths = 3.0 / 5 * max;
    const int64_t half = 1.0 / 2 * max;

    EXPECT_FALSE(isSumValid(threeFifths, half));
}

TEST_F(SignedEightByteIntTest, SumOfTwoFifthsMax)
{
    const int64_t twoFifths = 2.0 / 5 * max;

    EXPECT_TRUE(isSumValid(twoFifths, twoFifths));
}

TEST_F(SignedEightByteIntTest, SumOfHalfMaxAndHalfMin)
{
    const int64_t halfMax = 1.0 / 2 * max;
    const int64_t halfMin = 1.0 / 2 * min;

    EXPECT_TRUE(isSumValid(halfMax, halfMin));
}

TEST_F(SignedEightByteIntTest, SumOfMaxAndMin) { EXPECT_TRUE(isSumValid(max, min)); }

} // namespace