# DurkGame
 SDL2 wrapper

Example:
```c++
#include <DurkGame.hpp>

const int WIN_WIDTH = 800;
const int WIN_HEIGHT = 600;


int main(int argc, char** argv) {
	DK_Init();

	SDL_Window* window = DK_Display::setMode("DurkGame", WIN_WIDTH, WIN_HEIGHT);
	SDL_Renderer* renderer = DK_Display::setRenderer(window);
	DK_Time::Clock clock;

	DK_Texture texture(renderer, "../assets/image.png");
	texture.scaleBy(0.25f);
	texture.setCenter({WIN_WIDTH / 2, WIN_HEIGHT / 2});

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
		texture.blit();

		DK_Display::flip(renderer);
	}
	DK_Quit(window, renderer);

    return 0;
}
```
