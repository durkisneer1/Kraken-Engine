<h1 align="center">Kraken Engine</h1>

<p align="center">
  <img src="https://img.shields.io/badge/license-MIT-blue.svg">
  <a href="https://app.codacy.com/gh/durkisneer1/DurkGame/dashboard?utm_source=gh&utm_medium=referral&utm_content=&utm_campaign=Badge_grade"><img src="https://app.codacy.com/project/badge/Grade/17028e01d32f4441be4bd5e37edb94ce"/></a>
</p>

`Kraken Engine` extends SDL2 with easy-to-use features like <em>texture caching</em> and <em>collision logic</em>. Future plans include implementing handy mathematical functions such as <em>pathfinding</em>, <em>raycasting</em>, and <em>built-in physics</em>.

<h1 align="center">Documentation</h1>

I don't have a documentation page yet, but I plan on making one soon.
In the very least, here is a basic window setup program using Kraken:
<br>

```c++
#include <KrakenEngine.hpp>

const kn::math::Vector2 WIN_SIZE = { 800, 600 };


int main() {
    kn::RenderWindow window(WIN_SIZE, "Kraken App");
    kn::time::Clock clock;

    bool done = false;
    while (!done) {
        double deltaTime = clock.tick(60) / 1000.0f;

        for (const auto& event : window.getEvents()) {
            if (event.type == KN_QUIT) done = true;
        }

        window.fill({ 40, 40, 40 });
        window.flip();
    }

    return EXIT_SUCCESS;
}
```

To view a more in-depth use of the library, I am working on a small tech demo in the [example](https://github.com/durkisneer1/Kraken-Engine/tree/main/example) folder.

<h1 align="center">Licensing</h1>

[MIT](LICENSE) @ Derrick Martinez

`Kraken Engine` is a non-profit, free, and open-source framework.
