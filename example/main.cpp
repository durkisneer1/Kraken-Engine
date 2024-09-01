#include <KrakenEngine.hpp>

int main()
{
    const kn::math::Vec2 WIN_SIZE = {800, 600};
    kn::window::init(WIN_SIZE);
    kn::time::Clock clock;

    kn::Texture boxTex({100, 100}, {100, 100, 100});
    kn::Rect boxRect = boxTex.getRect();
    boxRect.setCenter(WIN_SIZE / 2);

    bool done = false;
    while (!done)
    {
        clock.tick();

        for (const auto& event : kn::window::getEvents())
            if (event.type == kn::QUIT)
                done = true;

        kn::window::clear({20, 20, 20, 255});

        kn::window::blit(boxTex, boxRect);

        kn::window::flip();
    }

    kn::window::quit();
    return EXIT_SUCCESS;
}
