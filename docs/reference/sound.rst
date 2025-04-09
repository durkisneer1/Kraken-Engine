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

.. raw:: html

    <div class="highlight"><pre>
    <span class="c1">// Create a Sound object from an audio file.</span>
    <span class="nc">kn</span>::<span class="nc">Sound</span> <span class="n">sfx</span><span class="p">(</span><span class="s">"assets/sfx.ogg"</span><span class="p">);</span>

    <span class="c1">// Set the volume of the sound to 50%.</span>
    <span class="n">sfx</span>.<span class="nf">setVolume</span><span class="p">(</span><span class="mf">0.5f</span><span class="p">);</span>

    <span class="c1">// Play the sound 3 times after it fades in over 2 seconds.</span>
    <span class="n">sfx</span>.<span class="nf">play</span><span class="p">(</span><span class="mi">2</span><span class="p">,</span> <span class="o">-</span><span class="mi">1</span><span class="p">,</span> <span class="mi">2000</span><span class="p">);</span>
    </pre></div>

Members
-------

.. doxygenclass:: kn::Sound
    :members:
