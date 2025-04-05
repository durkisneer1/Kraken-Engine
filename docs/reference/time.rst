time
====

Description
-----------

The **time** namespace contains the :code:`kn::time::Clock` class which is used to measure time in your game.
It is recommended to use this class to get the delta time between frames and to get the time since program initialization.

Usage
-----

.. raw:: html

    <div class="highlight"><pre>
    <span class="c1">// Create a Clock object.</span>
    <span class="nc">kn</span>::<span class="nc">time</span>::<span class="nc">Clock</span> <span class="n">clock</span><span class="p">;</span>

    <span class="c1">// Get the time since the last frame with a maximum frame rate of 144 fps.</span>
    <span class="kt">double</span> <span class="n">deltaTime</span> <span class="o">=</span> <span class="n">clock</span>.<span class="nf">tick</span><span class="p">(</span><span class="mi">144</span><span class="p">)</span> <span class="o">/</span> <span class="mf">1000.0</span><span class="p">;</span>

    <span class="c1">// Get the time since Kraken was initialized.</span>
    <span class="kt">double</span> <span class="n">elapsedTime</span> <span class="o">=</span> <span class="nc">kn</span>::<span class="nc">time</span>::<span class="nf">getTicks</span><span class="p">(</span><span class="p">)</span><span class="p">;</span>
    </pre></div>

Members
-------

.. doxygenclass:: kn::time::Clock
    :members:

Functions
---------

.. doxygenfunction:: kn::time::getTicks
