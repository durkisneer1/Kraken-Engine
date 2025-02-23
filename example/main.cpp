#include <KrakenEngine.hpp>

#include "include/Player.hpp"

// clang-format off
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

    kn::TileMap tileMap("../example/assets/room.tmx");

    Player player(tileMap);

    const int width = 100;
    const int height = 100;
    Uint32 rgbArray[width * height];
    for (int i = 0; i < width * height; ++i)
    {
        Uint8 r = rand() % 256;
        Uint8 g = rand() % 256;
        Uint8 b = rand() % 256;
        Uint8 a = 50;
        // Combine channels into a single 32-bit value
        rgbArray[i] = (r << 24) | (g << 16) | (b << 8) | a;
    }
    kn::Texture randTex(rgbArray, {width, height});

    for (int i = 0; i < width * height; ++i)
    {
        Uint8 r = rand() % 256;
        Uint8 g = r;
        Uint8 b = g;
        Uint8 a = 255;
        // Combine channels into a single 32-bit value
        rgbArray[i] = (r << 24) | (g << 16) | (b << 8) | a;
    }
    kn::Texture randTex2(rgbArray, {width, height});

    kn::Rect testRect = {0, 0, 100, 100};

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
        kn::window::blit(randTex);
        kn::window::blit(randTex2, {100, 0});

        // tileMap.drawMap();
        // player.update(dt);

        testRect.center(kn::mouse::getPos());
        kn::draw::rect(testRect, {255, 0, 0, 50});

        kn::window::flip();
    }

    kn::window::quit();
    return EXIT_SUCCESS;
}
