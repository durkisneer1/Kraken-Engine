#include <KrakenEngine.hpp>

#include "include/Player.hpp"

int main()
{
    kn::window::init({320, 180}, "Night Terror", 4);
    kn::time::Clock clock;
    kn::camera = {-32, -26};

    constexpr kn::Color bgColor = {21, 18, 37, 255};

    kn::key::bind("left", {kn::S_LEFT, kn::S_a});
    kn::key::bind("right", {kn::S_RIGHT, kn::S_d});

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

        kn::window::clear(bgColor);

        tileMap.drawMap();
        player.update(dt);

        kn::window::flip();
    }

    kn::window::quit();
    return EXIT_SUCCESS;
}
