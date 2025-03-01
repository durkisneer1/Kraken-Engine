draw
====

Description
-----------

The **draw** namespace provides functions to draw basic shapes and lines on the screen.

Usage
-----

.. code-block:: cpp

    // Draw a rectangle at position (50, 50) with size (16, 16).
    kn::draw::rect({50, 50, 16, 16}, kn::color::RED);

    // Draw a line from (50, 50) to (100, 100) with a thickness of 4 pixels.
    kn::draw::line({50, 50}, {100, 100}, kn::color::GREEN, 4);

    // Draw a point at position (50, 50).
    kn::draw::point({50, 50}, kn::color::BLUE);

    // Draw a circle at position (50, 50) with radius 16.
    kn::draw::circle({50, 50}, 16, kn::color::YELLOW);

Functions
---------

.. doxygenfunction:: kn::draw::rect

.. doxygenfunction:: kn::draw::line

.. doxygenfunction:: kn::draw::point

.. doxygenfunction:: kn::draw::circle

Constants
---------

.. doxygennamespace:: kn::color
