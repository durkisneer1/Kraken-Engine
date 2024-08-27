#include <KrakenEngine.hpp>

int main(int argc, char** argv)
{
    kn::window::init({800, 600});
    kn::time::Clock clock;

    kn::Texture boxTex({20, 20}, {100, 100, 100});

    bool done = false;
    while (!done)
    {
        clock.tick();

        for (const auto& event : kn::window::getEvents())
            if (event.type == kn::QUIT)
                done = true;

        kn::window::clear({20, 20, 20, 255});

        kn::window::blit(boxTex);

        kn::window::flip();
    }

    kn::window::quit();
    return EXIT_SUCCESS;
}
