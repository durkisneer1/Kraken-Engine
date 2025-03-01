Font
====

Description
-----------

The **Font** class is used to load ttf fonts and render textures containing text.

Usage
-----

.. code-block:: cpp

    // Load a font file with a point size of 16.
    kn::Font font("assets/font.ttf", 16);

    // Render a texture containing the text "Hello, World!" in white with no anti-aliasing.
    const kn::Texture text = font.render("Hello, World!", false, kn::color::WHITE);

    // Draw the text texture, centered, at the center of the window.
    kn::window::blit(text, kn::window::getSize() / 2, kn::CENTER);

Members
-------

.. doxygenclass:: kn::Font
    :members: