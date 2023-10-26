# DurkGame
 SDL2 wrapper

Here is an example program showing off most of the current library features:
```c++
#include <DurkGame.hpp>

// Constants
const int WIN_WIDTH = 800;
const int WIN_HEIGHT = 600;
const int MOVE_SPEED = 250;


int main() {
	// Window Setup
	DK_Init();
	SDL_Window* window = DK_Display::setMode("DurkGame", WIN_WIDTH, WIN_HEIGHT);
	SDL_Renderer* renderer = DK_Display::setRenderer(window);
	DK_Time::Clock clock;
	DK_Math::Vector2i mousePos;

	// Player Setup
	DK_Texture playerImage(renderer, "../assets/image.png");
	playerImage.scaleBy(0.25f);
	DK_Math::Vector2f playerPosition = {WIN_WIDTH / 2, WIN_HEIGHT / 2};
	DK_Math::Vector2f playerDirection;

	// Main Loop
	SDL_Event event;
	bool run = true;
	while (run) {
		// Tool Updates
		SDL_GetMouseState(&mousePos.x, &mousePos.y);
		float deltaTime = clock.tick(60) / 1000.0f;

		// Event Handling
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				run = false;
			}
		}

		// Player Movement
		playerDirection = DK_Input::getVector(SDL_SCANCODE_W, SDL_SCANCODE_S, SDL_SCANCODE_A, SDL_SCANCODE_D);
		playerPosition += playerDirection * MOVE_SPEED * deltaTime;
		playerImage.setCenterF(playerPosition);

		// Buffer Draw and Flip
		DK_Display::cls(renderer);
		DK_Display::fill(renderer, {40, 40, 40});
		playerImage.blit();
		DK_Display::flip(renderer);
	}

	// Cleanup
	DK_Quit(window, renderer);
    return 0;
}
```
