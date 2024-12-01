#pragma once

#include "gtest/gtest.h"

#include "ErrorLogger.hpp"

namespace
{

class TestBase : public ::testing::Test
{
  public:
    TestBase() { kn::ErrorLogger::setConsoleOnly(); }
    ~TestBase() override = default;

  protected:
    void SetUp() override {}

    void TearDown() override {}
};

} // namespace
