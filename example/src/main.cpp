#include <DurkGame.hpp>
#include <memory>
#include <iostream>

#include "../include/Player.hpp"
#include "../include/Wall.hpp"
#include "../include/Tracker.hpp"

const dk::math::Vector2 WIN_SIZE = { 800, 600 };
float GRAVITY = 980.0f;


int main() {
	dk::RenderWindow window(WIN_SIZE, "Game");
	dk::TextureCache textureCache(window);
	dk::time::Clock clock;
	dk::Font font(window, "assets/KdamThmorPro-Regular.ttf", 34);

	textureCache.create("player", { 50, 50 }, { 255, 0, 0 });
	textureCache.create("wall", { 50, 50 }, { 0, 255, 0 });
	textureCache.create("tracker", {20, 20}, { 0, 0, 255 });
	textureCache.load("background", "assets/background.png");
	textureCache.move("hello world", font.render("Hello, World!", true, { 255, 255, 255 }));

	std::shared_ptr<dk::Texture> bgTexture = textureCache.get("background");
	bgTexture->fitWidth(WIN_SIZE.x);

	std::shared_ptr<dk::Texture> hwTexture = textureCache.get("hello world");
	dk::Rect hwRect = hwTexture->getRect();
	hwRect.setCenter(WIN_SIZE / 2.0f);

	Player player(window, *textureCache.get("player"));
	Tracker tracker(window, *textureCache.get("tracker"));

	for (float x = 0.0f; x <= WIN_SIZE.x - 50.0f; x += 50.0f) {
		dk::Sprite::addSprite(std::make_unique<Wall>(window, *textureCache.get("wall"), dk::math::Vector2(x, WIN_SIZE.y)));
	}
	dk::Sprite::addSprite(std::make_unique<Wall>(window, *textureCache.get("wall"), dk::math::Vector2(WIN_SIZE.x - 50.0f, WIN_SIZE.y - 50.0f)));

	bool done = false;
	while (!done) {
		double deltaTime = clock.tick(60);

		for (const auto &event : window.getEvents()) {
			if (event.type == DK_QUIT) {
				done = true;
			} else if (event.type == DK_KEYDOWN) {
				if (event.key.keysym.sym == DKK_ESCAPE) {
					done = true;
				} else {}
			} else {}
		}
		
		window.fill({ 40, 40, 40 });
		window.blit(*bgTexture, bgTexture->getRect());

		for (const auto& sprite : dk::Sprite::getSprites()) {
			sprite->process(deltaTime);
		}
		window.blit(*hwTexture, hwRect);
		player.process(deltaTime);
		tracker.process(deltaTime);
		
		window.flip();
	}

	return EXIT_SUCCESS;
}
