#include "gtest/gtest.h"

#include "Math.hpp"

using kn::math::Vec2;

namespace
{

class MathTest : public ::testing::Test
{
  protected:
    MathTest() {}
    ~MathTest() {}

    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(MathTest, Vec2DefaultConstructor)
{
    Vec2 vec;

    EXPECT_EQ(vec.x, 0.0);
    EXPECT_EQ(vec.y, 0.0);
}

TEST_F(MathTest, Vec2TwoArgConstructor)
{
    Vec2 vec = Vec2(1.0, 2.0);

    EXPECT_EQ(vec.x, 1.0);
    EXPECT_EQ(vec.y, 2.0);
}

TEST_F(MathTest, EqualityOperator)
{
    Vec2 first = Vec2(1.0, 2.0);
    Vec2 second = Vec2(1.0, 2.0);
    Vec2 third = Vec2(2.0, 1.0);
    Vec2 fourth = Vec2(1.0, 3.0);

    EXPECT_EQ(first, second);
    EXPECT_NE(first, third);
    EXPECT_NE(second, fourth);
    EXPECT_NE(third, fourth);
}

TEST_F(MathTest, Vec2ThreeArgConstructor)
{
    Vec2 first = Vec2(1.0, 2.0, 0.5);
    Vec2 second = Vec2(1.0, 1.60);

    // tolerance of first is set to 0.5, which is super large
    // but that should make these appear equal when using first's
    // operator==. Second's operator== uses the default tolerance
    // of 0.0001, which means that they should appear not equal
    EXPECT_EQ(first, second);
    EXPECT_NE(second, first);
}

TEST_F(MathTest, AdditionOperator)
{
    Vec2 first = Vec2(1.0, 2.0);
    Vec2 second = Vec2(-1.0, 2.0);
    Vec2 third = Vec2(900.6, 322.5);

    EXPECT_EQ(first + second, Vec2(0.0, 4.0));
    EXPECT_EQ(Vec2() + third, third);
    EXPECT_EQ(second + third, Vec2(899.6, 324.5));
}

TEST_F(MathTest, MultiplyOperator)
{
    Vec2 first = Vec2(1.0, 2.0);
    Vec2 second = Vec2(2.0, 4.0);
    Vec2 third = Vec2(-1.0, -2.0);

    EXPECT_EQ(2 * first, first * 2.0);
    EXPECT_EQ(2.0f * first, second);
    EXPECT_EQ(first * -1, third);
    EXPECT_EQ(second * 0.5, Vec2() - third);
}

TEST_F(MathTest, CopyConstructor)
{
    // Copy constructor is not explicitly defined
    // and is defined by the compiler
    Vec2 original = Vec2(1.0, 2.0);
    Vec2 copy = original;

    EXPECT_EQ(original, copy);
    EXPECT_NE(&original, &copy);
    EXPECT_NE(&(original.x), &(copy.x));
    EXPECT_NE(&(original.y), &(copy.y));
}

TEST_F(MathTest, GetLength)
{
    Vec2 first = Vec2();
    Vec2 second = Vec2(3.0, 4.0);
    Vec2 third = Vec2(INFINITY, INFINITY);
    Vec2 fourth = Vec2(4.0, 3.0);

    EXPECT_EQ(first.getLength(), 0.0);
    EXPECT_EQ(second.getLength(), 5.0);
    EXPECT_EQ(second.getLength(), fourth.getLength());
    EXPECT_EQ(third.getLength(), -1.0);
}

TEST_F(MathTest, Normalize)
{
    Vec2 first = Vec2();
    Vec2 second = Vec2(3.0, 4.0);
    Vec2 third = Vec2(INFINITY, INFINITY);

    EXPECT_EQ(first.normalize(), false);
    EXPECT_EQ(first, Vec2::ZERO());
    EXPECT_EQ(second.normalize(), true);
    EXPECT_EQ(second, Vec2(0.6, 0.8));
    EXPECT_EQ(third.normalize(), false);
    EXPECT_EQ(third.x, std::numeric_limits<double>::infinity());
    EXPECT_EQ(third.y, std::numeric_limits<double>::infinity());
}

} // namespace
