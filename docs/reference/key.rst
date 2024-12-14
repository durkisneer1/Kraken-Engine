key
===

Description
-----------

The **key** namespace contains functions to handle input from the keyboard.
The two types of key codes are `scancodes` and `keycodes`.
Scancodes are the physical location of the key on the keyboard.
Keycodes are the character that the key represents.
For example, 'W' has a scancode of ``kn::S_w`` and a keycode of ``kn::K_w``.

Keycodes are more for text input, while scancodes are more for game input.

.. note:: A function similar to the removed ``kn::input::getVector`` will eventually be added to this namespace.

Usage
-----

.. code-block:: cpp

    // Get all currently pressed keys.
    const auto* keys = kn::key::getPressed();

    // Check if the 'W' key is pressed.
    if (keys[kn::S_w]) {
        // Handle 'W' key press.
    }

    // Bind keys to the name "up".
    kn::key::bind("up", {kn::S_w, kn::S_UP});

    // Check if any of the "up" binds are pressed.
    if (kn::key::isPressed("up")) {
        // Handle "up" bind.
    }

    // Make three more binds for left, right, and down.
    kn::key::bind("left", {kn::S_a, kn::S_LEFT});
    kn::key::bind("right", {kn::S_d, kn::S_RIGHT});
    kn::key::bind("down", {kn::S_s, kn::S_DOWN});

    // Get the direction of the four binds.
    auto direction = kn::key::getDirection("left", "right", "up", "down");

Functions
---------

.. doxygenfunction:: kn::key::getPressed

.. doxygenfunction:: kn::key::isPressed

.. doxygenfunction:: kn::key::bind

.. doxygenfunction:: kn::key::unbind

.. doxygenfunction:: kn::key::getDirection