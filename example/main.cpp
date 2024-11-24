#include <KrakenEngine.hpp>

#include "include/Player.hpp"

int main()
{
    kn::window::init({320, 180}, "Night Terror", 4);
    kn::time::Clock clock;
    kn::camera = {-32, -26};

    const kn::TileMap tileMap("../example/assets/room.tmx");

    Player player(tileMap);

    bool done = false;
    while (!done)
    {
        const double dt = clock.tick();

        for (const auto& event : kn::window::getEvents())
        {
            if (event.type == kn::QUIT ||
                (event.type == kn::KEYDOWN && event.key.keysym.sym == kn::K_ESCAPE))
                done = true;
        }

        kn::window::clear({21, 18, 37});

        tileMap.drawMap();
        player.update(dt);

        kn::window::flip();
    }

    kn::window::quit();
    return EXIT_SUCCESS;
}
