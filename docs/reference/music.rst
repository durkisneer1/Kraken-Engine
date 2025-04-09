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

.. raw:: html

    <div class="highlight"><pre>
    <span class="c1">// Load a music file to stream.</span>
    <span class="nc">kn</span>::<span class="nc">music</span>::<span class="nf">load</span><span class="p">(</span><span class="s">"assets/music.ogg"</span><span class="p">);</span>

    <span class="c1">// Set the volume of the music to 50%.</span>
    <span class="nc">kn</span>::<span class="nc">music</span>::<span class="nf">setVolume</span><span class="p">(</span><span class="mf">0.5f</span><span class="p">);</span>

    <span class="c1">// Play the music indefinitely after it fades in over 2 seconds.</span>
    <span class="nc">kn</span>::<span class="nc">music</span>::<span class="nf">play</span><span class="p">(</span><span class="o">-</span><span class="mi">1</span><span class="p">,</span> <span class="mi">2000</span><span class="p">);</span>

    <span class="c1">// Fade out the music over 2 seconds.</span>
    <span class="nc">kn</span>::<span class="nc">music</span>::<span class="nf">fadeOut</span><span class="p">(</span><span class="mi">2000</span><span class="p">);</span>
    </pre></div>

Functions
---------

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
    