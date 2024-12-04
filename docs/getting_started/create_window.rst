Creating a Window
=================

After following the :doc:`installation` guide, you are ready for your first Kraken Engine program.
The following code creates a window and keeps it open until the user closes it.

.. code-block:: c++
    :linenos:

    #include <KrakenEngine.hpp>

    int main()
    {
        kn::window::init({800, 600});

        kn::Event event;
        while (kn::window::isOpen())
        {
            kn::window::pollEvent(event);
            if (event.type == kn::QUIT)
                kn::window::close();

            kn::window::flip();
        }
        kn::window::quit();

        return EXIT_SUCCESS;
    }
