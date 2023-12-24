#include <KrakenEngine.hpp>
#include <memory>
#include <iostream>

#include "../include/Player.hpp"
#include "../include/Wall.hpp"
#include "../include/Tracker.hpp"

const kn::math::Vec2 kn::SCREEN_SIZE = { 240, 160 };
float kn::GRAVITY = 245.0f;


int main() {
	kn::RenderWindow window("Game", 5);
	kn::TextureCache textureCache(window);
	kn::time::Clock clock;
	kn::Font font(window, "assets/KdamThmorPro-Regular.ttf", 16);

	textureCache.create("player", { 16, 16 }, { 255, 0, 0 });
	textureCache.create("wall", { 16, 16 }, { 0, 255, 0 });
	auto bgTexture = textureCache.load("background", "assets/background.png");
	auto hwTexture = textureCache.move("hello world", font.render("Hello, World!", false, { 255, 255, 255 }));

	bgTexture->fitWidth(kn::SCREEN_SIZE.x);

	kn::Rect hwRect = hwTexture->getRect();
	hwRect.setCenter({ kn::SCREEN_SIZE.x / 2.0f, kn::SCREEN_SIZE.y / 4.0f });

	Player player(window, textureCache.getTexture("player"));

	std::vector<std::shared_ptr<Wall>> walls;

	for (int x = 0; x < kn::SCREEN_SIZE.x; x += 16) {
		walls.push_back(
			std::make_shared<Wall>(window, textureCache.getTexture("wall"), kn::math::Vec2(x, kn::SCREEN_SIZE.y))
		);
	}
	walls.push_back(
		std::make_shared<Wall>(window, textureCache.getTexture("wall"), kn::math::Vec2(kn::SCREEN_SIZE.x - 48.0f, kn::SCREEN_SIZE.y - 16.0f))
	);

	kn::TileMap tileMap(window, textureCache, "assets/room.tmx");

	bool done = false;
	while (!done) {
		double deltaTime = clock.tick(60);

		for (const auto &event : window.getEvents()) {
			if (event.type == KN_QUIT) {
				done = true;
			} else if (event.type == KN_KEYDOWN) {
				if (event.key.keysym.sym == KNK_ESCAPE) {
					done = true;
				}
			}
		}
		
		window.cls();
		// window.blit(bgTexture, bgTexture->getRect());

		// for (const auto& wall : walls) wall->update();
		// window.blit(hwTexture, hwRect);
		player.update(deltaTime, walls);
		
		window.flip();
	}

	return EXIT_SUCCESS;
}
