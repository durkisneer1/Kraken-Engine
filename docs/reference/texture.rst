Texture
=======

Description
-----------

The **Texture** class is used to load image files and apply transformations.
You can either load a texture from a file or create a texture of a solid color.

Usage
-----

.. code-block:: cpp

    // Instantiate a Texture object and load an image from a file.
    kn::Texture imageTexture("assets/image.png");

    // Create a 16x16 red texture.
    kn::Texture colorTexture({16, 16}, kn::color::RED);

    // Flip the image texture horizontally and rotate it 30 degrees.
    imageTexture.flip.x = true;
    imageTexture.angle = 30.0;

    // Draw the textures.
    kn::window::blit(imageTexture, {50, 50});
    kn::window::blit(colorTexture, {100, 100});

Members
-------

.. note:: The internal SDL_Texture* is a nullptr until ``loadFromFile`` is called.

.. doxygenclass:: kn::Texture
    :members: