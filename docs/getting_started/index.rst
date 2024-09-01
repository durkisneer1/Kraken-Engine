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
        kn::window::init({800, 600});
        kn::time::Clock clock;

        bool done = false;
        while (!done)
        {
            clock.tick();

            for (const auto &event : kn::window::getEvents())
                if (event.type == kn::QUIT)
                    done = true;

            kn::window::clear();
            kn::window::flip();
        }

        kn::window::quit();
        return EXIT_SUCCESS;
    }
