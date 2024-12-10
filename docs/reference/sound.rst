Sound
=====

Description
-----------

The **Sound** class is used to load audio files into memory and play them.
You should **only** use this class to play short sound effects or sounds that you're often going to reuse.
If you need to play background music or long audio files, you may be looking for :doc:`music` instead.

The only supported audio formats are OGG Vorbis, WAV, and MP3.
It is recommended to use OGG Vorbis for the best compatibility and quality.

Usage
-----

.. code-block:: cpp

    // Create a Sound object from an audio file.
    kn::Sound sound("assets/sound.ogg");

    // Set the volume of the sound to 50%.
    sound.setVolume(0.5f);

    // Play the sound 3 times after it fades in over 2 seconds.
    sound.play(2, -1, 2000);

Members
-------

.. doxygenclass:: kn::Sound
    :members:
