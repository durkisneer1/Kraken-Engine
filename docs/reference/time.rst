time
====

Description
-----------

The **time** namespace contains the :code:`kn::time::Clock` class which is used to measure time in your game.
It is recommended to use this class to get the delta time between frames and to get the time since program initialization.

Usage
-----

.. code-block:: cpp

    // Create a Clock object.
    kn::time::Clock clock;

    // Get the time since the last frame with a maximum frame rate of 144 fps.
    double deltaTime = clock.tick(144);

    // Get the time since Kraken was initialized.
    double elapsedTime = kn::time::getTicks();

Members
-------

.. doxygenclass:: kn::time::Clock
    :members:

Functions
---------

.. doxygenfunction:: kn::time::getTicks
