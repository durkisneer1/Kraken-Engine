#include <KrakenEngine.hpp>

#include "include/Player.hpp"

int main()
{
    kn::window::init({320, 180}, "Night Terror", 4);
    kn::time::Clock clock;
    kn::camera = {-32, -26};

    const kn::TileMap tileMap("../example/assets/room.tmx");

    Player player(tileMap);

    kn::Event event;
    while (kn::window::isOpen())
    {
        const double dt = clock.tick() / 1000.0;

        while (kn::window::pollEvent(event))
        {
            if (event.type == kn::KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
                kn::window::close();
        }

        kn::window::clear({21, 18, 37});

        tileMap.drawMap();
        player.update(dt);

        kn::window::flip();
    }

    kn::window::quit();
    return EXIT_SUCCESS;
}
