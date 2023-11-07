# DurkGame
 SDL2 wrapper

Here is a basic window setup program using DurkGame:
```c++
#include <DurkGame.hpp>

const DK_Math::Vector2 WIN_SIZE = {800, 600};

int main() {
	DK_Init();

	SDL_Window* window = DK_Display::setMode("DurkGame", WIN_SIZE);
	SDL_Renderer* renderer = DK_Display::setRenderer(window);
	DK_Time::Clock clock;

	SDL_Event event;
	bool run = true;
	while (run) {
		float deltaTime = clock.tick(60) / 1000.0f;

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				run = false;
			}
		}

		DK_Display::cls(renderer);
		DK_Display::fill(renderer, {40, 40, 40});

		DK_Display::flip(renderer);
	}

	DK_Quit(window, renderer);
    return 0;
}
```
