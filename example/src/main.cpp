#include <KrakenEngine.hpp>
#include <memory>
#include <iostream>

#include "../include/Player.hpp"

const kn::math::Vec2 kn::SCREEN_SIZE = { 320, 180 };
float kn::GRAVITY = 245.0f;


int main() {
	kn::RenderWindow window("Game", 4);
	kn::TextureCache textureCache(window);
	kn::time::Clock clock;

	kn::TileMap tileMap(window, textureCache, "assets/room.tmx");
	std::vector<std::shared_ptr<kn::Sprite>> walls;
	for (const auto& obj : tileMap.getObjects()) {
		if (obj.type == "Obstacle") {
			auto newSprite = std::make_shared<kn::Sprite>(window, obj.texture);
			newSprite->crop = obj.crop;
			newSprite->rect = obj.rect;
			walls.push_back(newSprite);
		}
	}

	textureCache.create("player", { 16, 16 }, { 255, 0, 0 });
	Player player(window, textureCache.getTexture("player"));

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

		tileMap.drawTiles();
		for (const auto& obj : tileMap.getObjects()) {
			window.blit(obj.texture, obj.crop, obj.rect);
		}
		player.update(deltaTime, walls);
		
		window.flip();
	}

	return EXIT_SUCCESS;
}
