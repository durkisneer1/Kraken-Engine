key
===

Description
-----------

The **key** namespace contains functions to handle input from the keyboard.
The two types of key codes are `scancodes` and `keycodes`.
Scancodes are the physical location of the key on the keyboard.
Keycodes are the character that the key represents.
For example, 'W' has a scancode of ``kn::S_w`` and a keycode of ``kn::K_w``.

.. note:: A function similar to the removed ``kn::input::getVector`` will eventually be added to this namespace.

Usage
-----

.. code-block:: cpp

    // Check if the 'W' key is pressed.
    if (kn::key::isPressed(kn::S_w)) {
        // Handle 'W' key press.
    }

Functions
---------

.. doxygenfunction:: kn::key::isPressed