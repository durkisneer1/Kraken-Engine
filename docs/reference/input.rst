input
=====

Description
-----------

The **input** namespace contains functions to get input from the keyboard and mouse.
:code:`kn::input::getVector` is going to be your best friend when you need to get 8-directional input.
This function is planned to also support controller joystick input in the future.

Usage
-----

.. code-block:: cpp

    // Check if the left mouse button is pressed.
    if (kn::input::isMouseButtonPressed(kn::BUTTON_LEFT)) {
        // Handle left mouse button press.
    }

    // Check if the 'W' key is pressed.
    if (kn::input::isKeyPressed(kn::S_w)) {
        // Handle 'W' key press.
    }

    // Using the getVector function to get 8-directional input.
    std::vector<kn::KEYS> left = {kn::S_a, kn::S_LEFT};
    std::vector<kn::KEYS> right = {kn::S_d, kn::S_RIGHT};
    std::vector<kn::KEYS> up = {kn::S_w, kn::S_UP};
    std::vector<kn::KEYS> down = {kn::S_s, kn::S_DOWN};

    kn::math::Vec2 inputDir = kn::input::getVector(left, right, up, down);

.. doxygenfunction:: kn::input::getMousePos

.. doxygenfunction:: kn::input::isMouseButtonPressed

.. doxygenfunction:: kn::input::isKeyPressed

.. doxygenfunction:: kn::input::getVector