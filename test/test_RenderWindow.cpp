#include <iostream>
#include <string>

#include "gtest/gtest.h"

#include "ErrorLogger.hpp"
#include "Window.hpp"

#define KN_SCREEN_SIZE_DEFINED

// FIXME: Irrelevant for now
namespace kn
{

class WindowTest : public ::testing::Test
{
  protected:
    WindowTest()
    {
        // Have to set this before first test
        window::setScale(2);
    }

    virtual ~WindowTest() {}

    virtual void SetUp() {}

    virtual void TearDown() {}
};

} // namespace kn
