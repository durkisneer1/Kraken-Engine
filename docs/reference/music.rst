music
=====

Description
-----------

The **music** namespace contains functions to load and stream music files.
You should use this namespace to play background music or long audio files.
If you need to play short sound effects or sounds that you're often going to reuse, you may be looking for :doc:`sound` instead.

The only supported audio formats are OGG Vorbis, WAV, and MP3.
It is recommended to use OGG Vorbis for the best compatibility and quality.

Usage
-----

.. code-block:: cpp

    // Load a music file to stream.
    kn::music::load("assets/music.ogg");

    // Set the volume of the music to 50%.
    kn::music::setVolume(0.5f);

    // Play the music indefinitely after it fades in over 2 seconds.
    kn::music::play(-1, 2000);

    // Fade out the music over 2 seconds.
    kn::music::fadeOut(2000);

.. doxygenfunction:: kn::music::load

.. doxygenfunction:: kn::music::unload

.. doxygenfunction:: kn::music::play

.. doxygenfunction:: kn::music::rewind

.. doxygenfunction:: kn::music::stop

.. doxygenfunction:: kn::music::pause

.. doxygenfunction:: kn::music::resume

.. doxygenfunction:: kn::music::fadeOut

.. doxygenfunction:: kn::music::setVolume

.. doxygenfunction:: kn::music::getVolume
    