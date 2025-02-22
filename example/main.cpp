#include <KrakenEngine.hpp>

#include "include/Player.hpp"

int main()
{
    kn::window::init({320, 180}, "Night Terror", 4);
    kn::window::setFullscreen(true);
    kn::time::Clock clock;
    kn::camera = {-32, -26};

    constexpr kn::Color bgColor = {21, 18, 37, 255};

    kn::input::bind(
        "left",
        {
            kn::InputAction(kn::S_a),
            kn::InputAction(kn::S_LEFT),
            kn::InputAction(kn::C_AXIS_LEFTX, false),
        }
    );
    kn::input::bind(
        "right",
        {
            kn::InputAction(kn::S_d),
            kn::InputAction(kn::S_RIGHT),
            kn::InputAction(kn::C_AXIS_LEFTX, true),
        }
    );
    kn::input::bind(
        "jump",
        {
            kn::InputAction(kn::S_SPACE),
            kn::InputAction(kn::C_A),
        }
    );

    kn::TileMap tileMap;
    tileMap.loadTMX("../example/assets/room.tmx");

    Player player(tileMap);

    kn::Event event;
    while (kn::window::isOpen())
    {
        const double dt = clock.tick(240) / 1000.0;

        while (kn::window::pollEvent(event))
        {
            if (event.type == kn::KEYDOWN)
            {
                if (event.key.keysym.sym == kn::K_ESCAPE)
                    kn::window::close();
            }
        }

        kn::window::clear(bgColor);

        tileMap.drawMap();
        player.update(dt);

        kn::window::flip();
    }

    kn::window::quit();
    return EXIT_SUCCESS;
}
