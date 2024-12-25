Font
====

Description
-----------

The **Font** class is used to load ttf fonts and render textures containing text.

Usage
-----

.. code-block:: cpp

    // Create a Font object with a font size of 16.
    kn::Font font("assets/font.ttf", 16);

    // Render a texture containing the text "Hello, World!" in white with no anti-aliasing.
    const kn::Texture text = font.render("Hello, World!", false, kn::color::WHITE);

    // Draw the text texture at position (50, 50).
    kn::window::blit(text, {50, 50});

Members
-------

.. doxygenclass:: kn::Font
    :members: