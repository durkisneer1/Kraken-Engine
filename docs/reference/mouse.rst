mouse
=====

Description
-----------

The **mouse** namespace contains functions to handle input from the mouse.

Usage
-----

.. code-block:: cpp

    // Check if the left mouse button is pressed.
    if (kn::mouse::isPressed(kn::BUTTON_LEFT)) {
        // Handle left mouse button press.
    }

    // Get the mouse position and draw a circle at that position.
    kn::math::Vec2 mousePos = kn::mouse::getPos();
    kn::draw::circle(mousePos, 10, {255, 0, 0});

Functions
---------

.. doxygenfunction:: kn::mouse::getPos

.. doxygenfunction:: kn::mouse::isPressed