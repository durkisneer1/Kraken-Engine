#include <KrakenEngine.hpp>

int main()
{
    kn::window::init({800, 600});
    kn::time::Clock clock;

    bool done = false;
    while (!done)
    {
        clock.tick();

        for (const auto& event : kn::window::getEvents())
            if (event.type == kn::QUIT)
                done = true;

        kn::window::clear();
        kn::window::flip();
    }

    kn::window::quit();
    return EXIT_SUCCESS;
}
