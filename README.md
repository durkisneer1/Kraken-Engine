# DurkGame
 SDL2 wrapper

Here is a basic window setup program using DurkGame:
```c++
#include <DurkGame.hpp>

// Constants
const int WIN_WIDTH = 800;
const int WIN_HEIGHT = 600;


int main() {
	// Window Setup
	DK_Init();
	SDL_Window* window = DK_Display::setMode("DurkGame", WIN_WIDTH, WIN_HEIGHT);
	SDL_Renderer* renderer = DK_Display::setRenderer(window);
	DK_Time::Clock clock;

	// Main Loop
	SDL_Event event;
	bool run = true;
	while (run) {
		// Tool Updates
		float deltaTime = clock.tick(60) / 1000.0f;

		// Event Handling
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				run = false;
			}
		}

		// Buffer Draw and Flip
		DK_Display::cls(renderer);
		DK_Display::flip(renderer);
	}

	// Cleanup
	DK_Quit(window, renderer);
    return 0;
}
```
