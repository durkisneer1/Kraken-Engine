<h1 align="center">Kraken Engine</h1>

<p align="center">
  <img src="https://img.shields.io/badge/license-MIT-blue.svg">
  <a href="https://app.codacy.com/gh/durkisneer1/Kraken-Engine/dashboard?utm_source=gh&utm_medium=referral&utm_content=&utm_campaign=Badge_grade"><img src="https://app.codacy.com/project/badge/Grade/17028e01d32f4441be4bd5e37edb94ce"/></a>
</p>

`Kraken Engine` extends SDL2 with easy-to-use features like <em>texture caching</em> and <em>collision logic</em>. Future plans include implementing handy mathematical functions such as <em>pathfinding</em>, <em>raycasting</em>, and <em>built-in physics</em>.

<h1 align="center">Documentation</h1>

You can find the latest documentation @ https://durkisneer1.github.io/kraken/html/index.html
Here is the bare window setup program using Kraken:
<br>

```c++
#include <KrakenEngine.hpp>

const kn::math::Vec2 kn::SCREEN_SIZE = { 800, 600 };


int main() {
    kn::RenderWindow window("Kraken App");
    kn::time::Clock clock;

    bool done = false;
    while (!done) {
        double deltaTime = clock.tick(60);

        for (const auto& event : window.getEvents()) {
            if (event.type == KN_QUIT) done = true;
        }

        window.cls();
        window.flip();
    }

    return EXIT_SUCCESS;
}
```

To view a more in-depth use of the library, I am working on a small tech demo in the [example](https://github.com/durkisneer1/Kraken-Engine/tree/main/example) folder.

<h1 align="center">Licensing</h1>

[MIT](LICENSE) @ Derrick Martinez

`Kraken Engine` is a non-profit, free, and open-source framework.
