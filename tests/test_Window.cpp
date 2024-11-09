#include <iostream>
#include <string>

#include <gtest/gtest.h>

#include "Window.hpp"
#include "TestBase.hpp"

namespace
{

class WindowTest : public TestBase
{
  public:
    WindowTest() : TestBase(), m_size(320, 240), m_scale(2), m_title("Kraken Window") {}

    virtual ~WindowTest() {}

  protected:
    virtual void SetUp() { kn::window::init(m_size, m_title, m_scale); }

    virtual void TearDown() { kn::window::quit(); }

    kn::math::Vec2 m_size;
    int m_scale;
    std::string m_title;
};

TEST_F(WindowTest, WindowInit)
{
    if (kn::window::getRenderer() != NULL)
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
