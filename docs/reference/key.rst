key
===

Description
-----------

The **key** namespace contains functions to handle input from the keyboard.
If you aren't familiar with the usage of keycodes and scancodes, please refer to the `Things To Know <../manual/things_to_know.html>`_ section.

Usage
-----

.. code-block:: cpp

    // Get all currently pressed keys.
    const auto* keys = kn::key::getPressed();

    // Check if the 'W' key is pressed.
    if (keys[kn::S_w]) {
        // Handle 'W' key press.
    }

Functions
---------

.. doxygenfunction:: kn::key::getPressed

.. note:: Functions for getting keys that were just pressed or just released are planned for the future.