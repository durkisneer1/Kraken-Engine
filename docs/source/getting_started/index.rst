===============
Getting Started
===============

Creating a Window
-----------------

After following the :doc:`../installation` guide, you are ready for your first Kraken Engine program.

.. code-block:: c
    :linenos:

    #include <KrakenEngine.hpp>

    const kn::math::Vec2 kn::SCREEN_SIZE = { 800, 600 };


    int main() {
        kn::RenderWindow& window = kn::RenderWindow::getInstance();
        kn::time::Clock clock;

        bool done = false;
        while (!done) {
            clock.tick();

            for (const auto &event : window.getEvents())
                if (event.type == kn::QUIT) done = true;

            window.cls();
            window.flip();
        }

        return EXIT_SUCCESS;
    }

This code opens a window and closes it when the user presses the window's X button.
It also clears the screen every frame and flips the buffers.
The ``clock.tick()`` function returns the time elapsed since the last call to ``clock.tick()`` in seconds.