AnimationController
===================

.. warning::

    This class is still in development and is subject to change at any time.

Description
-----------

The **AnimationController** class is used to control the playback of animations.
It can pause and resume animations, get the current frame content, and switch between animations.

What the AnimationController class does **NOT** do is provide a draw function.
This design decision is to give users the flexibility to draw the current frame in a desired position and size.

Usage
-----

.. code-block:: cpp

    // Instantiate an AnimationController.
    kn::AnimationController animController;

    // Load animations from a sprite sheet where every frame is 16x16 pixels and a directory.
    animController.loadSpriteSheet("idle", "assets/idle.png", {16, 16}, 5);  // 5fps
    animController.loadFolder("walk", "assets/walk", 10);  // 10fps

    // Since the current animation set is the last one added,
    // we can switch to the first animation by name.
    animController.setAnim("idle");

    // Change the animation controller's playback speed.
    animController.setPlaybackSpeed(-1.5f);  // Reverse playback at 1.5x speed.

    // Using AnimationController::nextFrame is simple.
    // It returns the current frame texture, srcRect, and advances the animation.
    const kn::Frame frame = animController.nextFrame(deltaTime);

    // Draw the current frame texture at position (50, 50) and size (16, 16).
    kn::window::blit(*frame.tex, {50, 50, 16, 16}, frame.rect);

Members
-------

.. doxygenstruct:: kn::Frame
    :members:
    :undoc-members:

.. doxygenstruct:: kn::Animation
    :members:
    :undoc-members:

.. doxygenclass:: kn::AnimationController
    :members:
