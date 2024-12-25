input
=====

.. warning::

    This namespace is still in development and is subject to change at any time.

Description
-----------

The **input** namespace lets you create binds for different kinds of input.

Usage
-----

.. code-block:: cpp

    /* Bind the 'left' action to:
        - The 'a' key
        - The left arrow key
        - The left stick (negative direction) on a controller
    */
    kn::input::bind(
        "left",
        {
            kn::InputAction(kn::S_a),
            kn::InputAction(kn::S_LEFT),
            kn::InputAction(kn::C_AXIS_LEFTX, false),
        }
    );

    /* Bind the 'right' action to:
        - The 'd' key
        - The right arrow key
        - The left stick (positive direction) on a controller
    */
    kn::input::bind(
        "right",
        {
            kn::InputAction(kn::S_d),
            kn::InputAction(kn::S_RIGHT),
            kn::InputAction(kn::C_AXIS_LEFTX, true),
        }
    );

    /* Bind the 'jump' action to:
        - The space key
        - The 'a' button on a controller
    */
    kn::input::bind(
        "jump",
        {
            kn::InputAction(kn::S_SPACE),
            kn::InputAction(kn::C_A),
        }
    );

    // Check if the 'jump' action is pressed
    if (onGround) {
        if (kn::input::isPressed("jump")) {
            onGround = false;
            // Handle jump action
        }
    }

    // Get the direction of the 'left' and 'right' actions
    const double xDirection = kn::input::getDirection("left", "right").x;

Members
-------

.. doxygenstruct:: kn::InputAction
    :members:

Functions
---------

.. doxygenfunction:: kn::input::bind

.. doxygenfunction:: kn::input::unbind

.. doxygenfunction:: kn::input::getDirection

.. doxygenfunction:: kn::input::isPressed

.. note:: Functions for getting input actions that were just pressed or just released are planned for the future.