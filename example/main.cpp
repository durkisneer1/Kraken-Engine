#include <KrakenEngine.hpp>

#include "include/Player.hpp"

// clang-format off
int main()
{
    kn::window::init({320, 180}, "Night Terror", 4);
    kn::window::setFullscreen(true);
    kn::time::Clock clock;
    kn::camera::pos({128, 64});

    constexpr kn::Color bgColor = {21, 18, 37, 255};

    // Bind input actions
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

    // Generate static animation with a random grayscale noise texture
    const int width = 320;
    const int height = 180;
    Uint32 rgbArray[width * height];

    kn::AnimationController staticAnimation;
    std::vector<std::shared_ptr<kn::Texture>> staticFrames;
    const Uint8 a = 4;
    for (int i = 0; i < 10; ++i)  // 10 anim frames
    {
        for (int j = 0; j < width * height; ++j)
        {
            const Uint8 value = rand() % 256;
            rgbArray[j] = (value << 24) | (value << 16) | (value << 8) | a;
        }
        staticFrames.push_back(std::make_shared<kn::Texture>(rgbArray, kn::math::Vec2{width, height}));
    }
    staticAnimation.loadTextures("static", staticFrames, 10);

    kn::Event event;
    float rotation = 0.0f;
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
            else if (event.type == kn::MOUSEWHEEL)
            {
                rotation += event.wheel.y * 5.0f;
                kn::camera::rot(rotation);
            }
        }

        kn::window::clear(bgColor);

        tileMap.drawMap();
        player.update(dt);

        const kn::Frame* frame = staticAnimation.nextFrame(dt);
        frame->tex->angle = -rotation;  // stabilize the noise texture
        kn::window::blit(*frame->tex, kn::camera::pos());

        kn::window::flip();
    }

    kn::window::quit();
    return EXIT_SUCCESS;
}
