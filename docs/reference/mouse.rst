mouse
=====

Description
-----------

The **mouse** namespace contains functions to handle input from the mouse.

Usage
-----

.. code-block:: cpp

    // Check if the user left clicked.
    const auto mousePressed = kn::mouse::getPressed();
    if (mousePressed == kn::MOUSE_LEFT) {
        // Handle left mouse button press.
    }

    // Get the mouse position and draw a circle at that position.
    kn::math::Vec2 mousePos = kn::mouse::getPos();
    kn::draw::circle(mousePos, 10, kn::color::RED);

Functions
---------

.. doxygenfunction:: kn::mouse::getPos

.. doxygenfunction:: kn::mouse::getRel

.. doxygenfunction:: kn::mouse::getPressed

.. doxygenfunction:: kn::mouse::lock

.. doxygenfunction:: kn::mouse::unlock

.. doxygenfunction:: kn::mouse::isLocked

.. doxygenfunction:: kn::mouse::hide

.. doxygenfunction:: kn::mouse::show

.. doxygenfunction:: kn::mouse::isHidden

.. note:: Functions for getting mouse buttons that were just pressed or just released are planned for the future.