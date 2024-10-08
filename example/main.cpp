#include "Boat.hpp"
#include <KrakenEngine.hpp>
#include <iostream>

int main()
{
    kn::window::init({320, 180}, "Boat Sailing", 4);
    kn::time::Clock clock;

    Boat boat;

    bool done = false;
    while (!done)
    {
        double dt = clock.tick();

        for (const auto& event : kn::window::getEvents())
            if (event.type == kn::QUIT)
                done = true;
            else if (event.type == kn::MOUSEBUTTONDOWN)
            {
                if (event.button.button == kn::BUTTON_LEFT)
                    boat.setDestination(kn::input::getMousePos());
            }

        kn::window::clear({35, 137, 218, 255});
        boat.update(dt);

        kn::window::flip();
    }

    kn::window::quit();
    return EXIT_SUCCESS;
}
