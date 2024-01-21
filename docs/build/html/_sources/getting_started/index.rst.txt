===============
Getting Started
===============

Creating a Window
-----------------

After following the :doc:`../installation` guide, you are ready for your first Kraken Engine program.

.. code-block:: c++
    :linenos:

    #include <KrakenEngine.hpp>

    int main()
    {
        kn::window::init({ 800, 600 });
        kn::time::Clock clock;

        bool done = false;
        while (!done)
        {
            clock.tick();

            for (const auto &event : kn::window::getEvents())
                if (event.type == kn::QUIT)
                    done = true;

            kn::window::cls();
            kn::window::flip();
        }

        kn::window::quit();
        return EXIT_SUCCESS;
    }

This code opens a window and closes it when the user presses the window's X button.
It also clears the screen every frame and flips the buffers.
The ``clock.tick()`` function returns the time elapsed since the last call to ``clock.tick()`` in seconds.