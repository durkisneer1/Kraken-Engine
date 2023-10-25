# DurkGame
 SDL2 wrapper

Example:
```python
#include <DurkGame.hpp>


int main(int argc, char** argv) {
	DK_Init();

	SDL_Window* window = DK_Display::setMode("DurkGame", 640, 480);
	SDL_Renderer* renderer = DK_Display::setRenderer(window);
	DK_Time::Clock clock;

	SDL_Event event;
	bool run = true;
	while (run) {
		float deltaTime = clock.tick(60);
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				run = false;
			}
		}
		DK_Display::cls(renderer);
		DK_Display::flip(renderer);
	}
	DK_Quit(window, renderer);

    return 0;
}
```
