controller
==========

.. warning::

    This namespace is still in development and is subject to change at any time.

Description
-----------

The **controller** namespace contains functions to handle input from a game controller.

.. note:: The default dead zone for the joysticks is 0.1f.

Usage
-----

.. code-block:: cpp

    // Get the vector of the left joystick
    kn::Vec2 leftJoystick = kn::controller::getLeftJoystick();

    // Change the joysticks' dead zones
    kn::controller::setDeadZone(0.2f);

    // Get how far the right trigger is pressed
    if (kn::controller::getRightTrigger() > 0.5f) {
        // Do something
    }

    // Check if the A button is pressed
    if (kn::controller::isPressed(kn::CONTROLLER_A)) {
        // Do something
    }

Functions
---------

.. doxygenfunction:: kn::controller::getLeftJoystick

.. doxygenfunction:: kn::controller::getRightJoystick

.. doxygenfunction:: kn::controller::getLeftTrigger

.. doxygenfunction:: kn::controller::getRightTrigger

.. doxygenfunction:: kn::controller::isPressed

.. doxygenfunction:: kn::controller::setDeadZone

.. doxygenfunction:: kn::controller::getDeadZone
