#include <iostream>
#include <string>

#include <gtest/gtest.h>

#include "TestBase.hpp"
#include "Window.hpp"

namespace
{

class WindowTest : public TestBase
{
  public:
    WindowTest() : m_size(320, 240), m_scale(2), m_title("Kraken Window") {}

    ~WindowTest() override = default;

  protected:
    void SetUp() override { kn::window::init(m_size, m_title, m_scale); }

    void TearDown() override { kn::window::quit(); }

    kn::math::Vec2 m_size;
    int m_scale;
    std::string m_title;
};

TEST_F(WindowTest, WindowInit)
{
    if (kn::window::getRenderer() != nullptr)
    {
        EXPECT_EQ(kn::window::getSize().x, m_size.x);
        EXPECT_EQ(kn::window::getSize().y, m_size.y);
        EXPECT_EQ(kn::window::getScale(), m_scale);
    }
    EXPECT_EQ(kn::window::getTitle(), std::string("Kraken Window"));
}

TEST_F(WindowTest, WindowFullscreen)
{
    kn::window::setFullscreen(true);
    EXPECT_EQ(kn::window::getFullscreen(), true);
    kn::window::setFullscreen(false);
    EXPECT_EQ(kn::window::getFullscreen(), false);
}

} // namespace
