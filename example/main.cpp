#include <KrakenEngine.hpp>
#include <vector>

#include "include/Player.hpp"

int main()
{
    kn::window::init({320, 180}, "Kraken", 4);
    kn::time::Clock clock;
    kn::camera = {-32, -26};

    const int width = 19U;
    const int height = 30U;
    const unsigned int animSpeed = 10U;

    const kn::TileMap tileMap("../example/assets/room.tmx");
    const kn::Layer* wallLayer = tileMap.getLayer("Wall");

    Player player(wallLayer);

    kn::AnimatedTexture animation(animSpeed);
    kn::AnimatedTexture animation2(animSpeed * 2);
    if (!animation.loadSpritesheet("../example/assets/astroidle.png", width, height) ||
        !animation2.loadSpritesheet("../example/assets/astroidle.png", width, height))
    {
        ERROR("Failed to load animation");
        return 1;
    }

    bool done = false;
    bool paused = false;
    uint32_t currentFPS = animSpeed;
    while (!done)
    {
        const double dt = clock.tick();

        for (const auto& event : kn::window::getEvents())
        {
            if (event.type == kn::QUIT)
                done = true;
            if ((event.type == kn::KEYDOWN))
            {
                switch (event.key.keysym.sym)
                {
                    case (kn::K_SPACE) :
                    {
                        if (paused)
                        {
                            animation.resume();
                            animation2.resume();
                        }
                        else
                        {
                            animation.pause();
                            animation2.pause();
                        }
                        paused = !paused;
                        break;
                    }
                    case (kn::K_i) :
                    {
                        currentFPS++;
                        animation.setFPS(currentFPS);
                        animation2.setFPS(currentFPS * 2);
                        animation.resume();
                        animation2.resume();
                        break;
                    }
                    case (kn::K_d) :
                    {
                        if (currentFPS > 0U)
                        {
                            currentFPS--;
                        }
                        else
                        {}
                        animation.setFPS(currentFPS);
                        animation2.setFPS(currentFPS * 2);
                        break;
                    }
                }

            }
        }

        kn::window::clear();

        tileMap.drawLayer("Background");
        tileMap.drawLayer("Wall");
        animation.render({0, 0, width, height});
        animation2.render({width, 0, width, height});

        player.update(dt);
        animation.update(dt);
        animation2.update(dt);

        kn::window::flip();
    }

    kn::window::quit();
    return EXIT_SUCCESS;
}
