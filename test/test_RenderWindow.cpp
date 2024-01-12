#include <iostream>
#include <string>

#include "gtest/gtest.h"

#include "ErrorLogger.hpp"
#include "RenderWindow.hpp"

#define KN_SCREEN_SIZE_DEFINED
const kn::math::Vec2 kn::SCREEN_SIZE = {100, 100};

namespace
{
using kn::RenderWindow;

class RenderWindowTest : public ::testing::Test
{
  protected:
    RenderWindowTest()
    {
        // Have to set this before first test
        RenderWindow::setScale(2);
        TRACE("This and the next message should go to file");
        TRACE("Setting scale to " + std::to_string(RenderWindow::getScale()));
        kn::ErrorLogger::setConsoleOnly();
        DEBUG("This DEBUG message appears in console");
    }

    virtual ~RenderWindowTest() {}

    virtual void SetUp() {}

    virtual void TearDown() {}
};

TEST_F(RenderWindowTest, SingletonPointersEqual)
{
    const RenderWindow* window1 = &RenderWindow::getInstance();
    const RenderWindow* window2 = &RenderWindow::getInstance();

    EXPECT_EQ(window1, window2);
}
}