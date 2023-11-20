# DurkGame
<p align="center">
  <img src="https://img.shields.io/badge/license-MIT-blue.svg">
  <a href="https://app.codacy.com/gh/durkisneer1/DurkGame/dashboard?utm_source=gh&utm_medium=referral&utm_content=&utm_campaign=Badge_grade"><img src="https://app.codacy.com/project/badge/Grade/17028e01d32f4441be4bd5e37edb94ce"/></a>
</p>
DurkGame is an extention of SDL2. There will be different object types to inherit from in the future such as `CharacterBody`s, `StaticBody`s, and `PhysicsBody`s. Eventually, I plan to also implement handy mathematical functions such as pathfinding and raycasting.

# Documentation
I don't have a documentation page yet, but I plan on making one soon.
In the very least, here is a basic window setup program using DurkGame:
```c++
#include <DurkGame.hpp>

const dk::math::Vector2 WIN_SIZE = { 800, 600 };


int main() {
    dk::init();
    dk::RenderWindow window(WIN_SIZE, "DurkGame App");
    dk::time::Clock clock;

    bool done = false;
    while (!done) {
        double deltaTime = clock.tick(60);

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
        window.flip();
    }

    dk::quit();
    return EXIT_SUCCESS;
}
```
To view a more in-depth use of the library, I am working on a small tech demo in the [example](https://github.com/durkisneer1/DurkGame/tree/main/example) folder.

# License
[MIT](LICENSE) @ Derrick Martinez

DurkGame is a non-profit, free, and open-source extended library for SDL2.
