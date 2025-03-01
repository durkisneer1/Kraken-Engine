Things To Know
==============

This section contains information that you should be aware of when using Kraken Engine.

Constant Prefixes
~~~~~~~~~~~~~~~~~

When working with keyboard, mouse, and controller input, you will notice that the constants for the keys and buttons have prefixes.
The prefixes are as follows:

- ``K_`` for keyboard keycode constants
- ``S_`` for keyboard scancode constants
- ``M_`` for mouse button constants
- ``C_`` for controller button constants

For example, to check if the ``A`` button on a controller is pressed, you would use the following code:

.. code-block:: cpp

    if (kn::controller::isPressed(kn::C_A)) {
        std::cout << "A button is pressed!\n";
    }

Keycode VS Scancode
~~~~~~~~~~~~~~~~~~~

Kraken Engine uses keycodes and scancodes to represent keyboard input.
Keycodes are the character that the key represents, while scancodes are the physical location of the key on the keyboard.
For example, the ``A`` key on a QWERTY keyboard has a keycode of ``K_a`` and a scancode of ``S_a``.

If you are unsure which one to use, it is recommended to use keycodes in the event loop and scancodes for gameplay input.

Here is a comparison of keycodes and scancodes for different scenarios:

.. list-table::
    :widths: 25 50 50
    :header-rows: 1

    * - Scenario
      - Keycode (``K_``)
      - Scancode (``S_``)
    * - Menu navigation
      - ✅ Layout-specific (intuitive keys)
      - ❌ Might mismatch user expectations
    * - Text input
      - ✅ Matches user's layout
      - ❌ Breaks for non-QWERTY layouts
    * - Gameplay movement
      - ❌ Layout-dependent inconsistency
      - ✅ Consistent across layouts
    * - Debug tools
      - ❌ User layout might vary
      - ✅ Always maps to physical key

Camera
~~~~~~

There is a global ``kn::camera`` vector that you can use to offset rendering.
This is useful for creating a camera system that follows the player or to pan around the game world.

In the example usage below, the rectangle's top left corner is visually at ``(150, 150)``:

.. code-block:: cpp

    kn::camera = {-100, -100};
    kn::draw::rect({50, 50, 16, 16}, kn::color::RED);

Color Constants
~~~~~~~~~~~~~~~

Kraken Engine provides a set of predefined color constants that you can use to set drawing colors easily. These constants use the syntax ``kn::color::[COLOR]``, for example:

.. code-block:: cpp

    kn::Texture yellowTex({16, 16}, kn::color::YELLOW);

All available color constants can be seen in :doc:`../reference/draw`.

.. note:: This page is a work in progress and will be updated as more information becomes available.
