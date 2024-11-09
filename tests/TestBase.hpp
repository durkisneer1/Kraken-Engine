#pragma once

#include "gtest/gtest.h"

#include "ErrorLogger.hpp"

namespace
{

class TestBase : public ::testing::Test
{
  public:
    TestBase() { kn::ErrorLogger::setConsoleOnly(); }
    virtual ~TestBase() {}

  protected:
    virtual void SetUp() {}

    virtual void TearDown() {}
};

} // namespace
