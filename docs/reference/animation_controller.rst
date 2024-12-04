AnimationController
===================

Description
-----------

The **AnimationController** class is used to control the playback of sprite sheet animations.
It is used to pause and resume animations, get the current frame content, and switch between animations.

What the AnimationController class does **NOT** do is provide a draw function.
This design decision is to give users the flexibility to draw the current frame in a desired position and size.

Usage
-----

.. code-block:: cpp

    // Create an AnimationController with a frame rate of 10 frames per second.
    kn::AnimationController animController(10);

    // Load animations from sprite sheets where every frame is 16x16 pixels.
    animController.addAnim("assets/idle.png", "idle", 16, 16);
    animController.addAnim("assets/walk.png", "walk", 16, 16);

    // Since the current animation set is the last one added,
    // we can switch to the first animation by name.
    animController.setAnim("idle");

    // Using AnimationController::nextFrame is simple.
    // It returns the current frame texture, srcRect, and advances the animation.
    const Frame frame = animController.nextFrame(deltaTime);

    // Draw the current frame texture at position (50, 50) and size (16, 16).
    kn::window::blit(*frame.tex, {50, 50, 16, 16}, frame.rect);

Members
-------

.. doxygenclass:: kn::AnimationController
    :members:
