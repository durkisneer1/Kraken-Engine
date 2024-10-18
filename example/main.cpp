#include <KrakenEngine.hpp>
#include <vector>

int main()
{
    kn::window::init({300, 200}, "Kraken", 4);
    kn::time::Clock clock;

    const std::vector up{kn::S_w, kn::S_UP};
    const std::vector down{kn::S_s, kn::S_DOWN};
    const std::vector left{kn::S_a, kn::S_LEFT};
    const std::vector right{kn::S_d, kn::S_RIGHT};

    const kn::Texture texture({50, 50}, {255, 255, 255});
    kn::Rect rect = texture.getRect();
    rect.setCenter(kn::window::getSize() / 2);

    const kn::TileMap tileMap("../example/assets/room.tmx");
    const kn::Layer& wallLayer = tileMap.getLayer("Background");

    bool done = false;
    while (!done)
    {
        double dt = clock.tick();

        for (const auto& event : kn::window::getEvents())
            if (event.type == kn::QUIT)
                done = true;

        auto direction = kn::input::getVector(left, right, up, down);
        rect.setCenter(rect.getCenter() + direction * 100 * dt);

        kn::window::clear();

        for (const kn::Tile& tile : wallLayer.tiles)
            kn::window::blit(*tileMap.getTexture(), tile.rect, tile.crop);
        kn::window::blit(texture, rect);

        kn::window::flip();
    }

    kn::window::quit();
    return EXIT_SUCCESS;
}
