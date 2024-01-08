===============
Getting Started
===============

Hello World
-----------

After following the :doc:`installation` guide, you are ready for your first Kraken Engine program.

.. code-block:: c
    :linenos:

    #include <KrakenEngine.hpp>

    const kn::math::Vec2 kn::SCREEN_SIZE = { 800, 600 };


    int main() {
        kn::RenderWindow window("Hello World");
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

This code opens a window and closes it when the user presses the window's X button.
It also clears the screen every frame and flips the buffers.
The ``clock.tick()`` function returns the time elapsed since the last call to ``clock.tick()`` in seconds.
The ``60`` parameter is the capped frame rate.