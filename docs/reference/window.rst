window
======

Description
-----------

The window namespace provides functions to create and manage a window.
It provides methods to draw onto the screen, get input events, and manage the window's properties.

You can find an example of window usage in the `Creating a Window <../getting_started/create_window.html>`_ guide.

Functions
---------

.. doxygenfunction:: kn::window::init

.. doxygenfunction:: kn::window::quit

.. doxygenfunction:: kn::window::close

.. doxygenfunction:: kn::window::isOpen

.. doxygenfunction:: kn::window::pollEvent

.. doxygenfunction:: kn::window::clear

.. doxygenfunction:: kn::window::flip

.. doxygenfunction:: kn::window::blit(const Texture &texture, const Rect &dstRect, const Rect &srcRect = {})

.. doxygenfunction:: kn::window::blit(const Texture &texture, const math::Vec2 &position = {}, Anchor anchor = TOP_LEFT)

.. doxygenfunction:: kn::window::setIcon

.. doxygenfunction:: kn::window::getFullscreen

.. doxygenfunction:: kn::window::setFullscreen

.. doxygenfunction:: kn::window::setTitle

.. doxygenfunction:: kn::window::getTitle

.. doxygenfunction:: kn::window::getScale

.. doxygenfunction:: kn::window::getSize

.. doxygenfunction:: kn::window::getRenderer
