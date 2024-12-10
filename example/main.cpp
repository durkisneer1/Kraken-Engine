#include <KrakenEngine.hpp>

int main()
{
    kn::window::init({320, 180}, "Night Terror", 4);
    kn::time::Clock clock;

    kn::Event event;
    while (kn::window::isOpen())
    {
        clock.tick(30); // comment this out for the controller input to work

        kn::window::pollEvent(event);
        if (event.type == kn::KEYDOWN && event.key.keysym.sym == kn::K_ESCAPE)
            kn::window::close();

        kn::window::clear({21, 18, 37});

        const auto inputDir = kn::input::getVector();
        kn::draw::circle(inputDir * 50 + kn::window::getSize() / 2, 10, {255, 255, 255});

        kn::window::flip();
    }

    kn::window::quit();
    return EXIT_SUCCESS;
}
