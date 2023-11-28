#include <DurkGame.hpp>
#include <memory>
#include <vector>
#include <iostream>

#include "../include/Player.hpp"
#include "../include/Wall.hpp"
#include "../include/Button.hpp"

const dk::math::Vector2 WIN_SIZE = { 800, 600 };
float GRAVITY = 980.0f;


int main() {
	dk::RenderWindow window(WIN_SIZE, "Game");
	dk::time::Clock clock;
	dk::Font font(window, "assets/KdamThmorPro-Regular.ttf", 34);

	// Player
	dk::Texture playerTexture(window, { 50, 50 }, { 255, 0, 0 });
	dk::Sprite::addSprite(std::make_unique<Player>(window, playerTexture));

	// Walls
	dk::Texture wallTexture(window, { 50, 50 }, { 0, 255, 0 });
	for (float x = 0.0f; x <= WIN_SIZE.x - wallTexture.getSize().x; x += wallTexture.getSize().x) {
		dk::Sprite::addSprite(std::make_unique<Wall>(window, wallTexture, dk::math::Vector2(x, WIN_SIZE.y)));
	}

	// Text
	dk::Texture textTexture = font.render("Hello World!", true, { 255, 255, 255 });
	dk::Rect textRect = textTexture.getRect();
	textRect.setCenter({ WIN_SIZE.x / 2, WIN_SIZE.y / 4 });

	// Button
	auto button = std::make_unique<Button>(window);

	bool done = false;
	while (!done) {
		double deltaTime = clock.tick(60);

		for (const auto& event : window.getEvents()) {
			if (event.type == DK_QUIT) {
				done = true;
			} else if (event.type == DK_KEYDOWN) {
				if (event.key.keysym.sym == DKK_ESCAPE) {
					done = true;
				} else {}
			} else {}
		}
		
		window.fill({ 40, 40, 40 });

		for (const auto& sprite : dk::Sprite::getSprites()) {
			sprite->process(deltaTime);
		}
		button->update();
		textTexture.drawAt(textRect);
		
		window.flip();
	}

	return EXIT_SUCCESS;
}
