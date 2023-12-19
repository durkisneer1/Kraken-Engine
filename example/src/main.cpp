#include <KrakenEngine.hpp>
#include <memory>
#include <iostream>

#include "../include/Player.hpp"
#include "../include/Wall.hpp"
#include "../include/Tracker.hpp"

const kn::math::Vector2 kn::SCREEN_SIZE = { 200, 150 };
float kn::GRAVITY = 980.0f;


int main() {
	kn::RenderWindow window("Game", 4);
	kn::TextureCache textureCache(window);
	kn::time::Clock clock;
	kn::Font font(window, "assets/KdamThmorPro-Regular.ttf", 34);

	textureCache.create("player", { 16, 16 }, { 255, 0, 0 });
	textureCache.create("wall", { 16, 16 }, { 0, 255, 0 });
	textureCache.create("tracker", {16, 16}, { 0, 0, 255 });
	textureCache.load("background", "assets/background.png");
	// textureCache.move("hello world", font.render("Hello, World!", true, { 255, 255, 255 }));  // FIXME: This is not working

	std::shared_ptr<kn::Texture> bgTexture = textureCache.getTexture("background");
	bgTexture->fitWidth(kn::SCREEN_SIZE.x);

	std::shared_ptr<kn::Texture> hwTexture = textureCache.getTexture("hello world");
	kn::Rect hwRect = hwTexture->getRect();
	hwRect.setCenter({0, 0});

	Player player(window, textureCache.getTexture("player"));
	Tracker tracker(window, textureCache.getTexture("tracker"));

	for (float x = 0.0f; x <= kn::SCREEN_SIZE.x - 50.0f; x += 50.0f) {
		kn::Sprite::addSprite(
			std::make_unique<Wall>(window, textureCache.getTexture("wall"), kn::math::Vector2(x, kn::SCREEN_SIZE.y))
		);
	}
	kn::Sprite::addSprite(
		std::make_unique<Wall>(window, textureCache.getTexture("wall"), kn::math::Vector2(kn::SCREEN_SIZE.x - 150.0f, kn::SCREEN_SIZE.y - 50.0f))
	);

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
		window.blit(bgTexture, bgTexture->getRect());

		for (const auto& sprite : kn::Sprite::getSprites()) {
			sprite->process(deltaTime);
		}
		// window.blit(hwTexture, hwRect);  // FIXME: This is not working
		player.process(deltaTime);
		tracker.update(deltaTime, kn::input::getMousePos(4));
		
		window.flip();
	}

	return EXIT_SUCCESS;
}
