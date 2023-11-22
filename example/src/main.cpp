#include <DurkGame.hpp>
#include <memory>
#include <vector>

#include "../include/Player.hpp"
#include "../include/Wall.hpp"

// Global variables
const dk::math::Vector2 WIN_SIZE = { 800, 600 };
float GRAVITY = 980.0f;


int main() {
	// Initialize DurkGame
	dk::init();
	dk::RenderWindow window(WIN_SIZE, "Game");
	dk::time::Clock clock;
	dk::Font font(window, "assets/KdamThmorPro-Regular.ttf", 34);

	// Create player
	dk::Texture playerTexture(window, { 50, 50 }, { 255, 0, 0 });
	dk::Sprite::addSprite(std::make_unique<Player>(window, playerTexture));

	// Create walls
	dk::Texture wallTexture(window, { 50, 50 }, { 0, 255, 0 });
	for (float x = 0.0f; x <= WIN_SIZE.x - wallTexture.getSize().x; x += wallTexture.getSize().x) {
		dk::Sprite::addSprite(std::make_unique<Wall>(window, wallTexture, dk::math::Vector2(x, WIN_SIZE.y)));
	}

	// Create text
	dk::Texture textTexture = font.render("Hello World!", true, { 255, 255, 255 });
	dk::Rect textRect = textTexture.getRect();
	textRect.setCenter({ WIN_SIZE.x / 2, WIN_SIZE.y / 4 });

	// Main loop
	bool done = false;
	while (!done) {
		double deltaTime = clock.tick(60);

		// Handle events
		for (const auto& event : window.getEvents()) {
			if (event.type == DK_QUIT) {
				done = true;
			} else if (event.type == DK_KEYDOWN) {
				if (event.key.keysym.sym == DKK_ESCAPE) {
					done = true;
				}
			}
		}
		
		window.fill({ 40, 40, 40 });

		// Update and draw character objects
		for (const auto& sprite : dk::Sprite::getSprites()) {
			sprite->process(deltaTime);
		}

		// Draw text
		textTexture.drawAt(textRect);
		
		// Flip frame buffer
		window.flip();
	}
	
	// Quit DurkGame
	dk::quit();
	return EXIT_SUCCESS;
}
