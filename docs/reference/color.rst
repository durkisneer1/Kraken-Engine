color
=====

Description
-----------

The color module provides a set of functions for manipulating colors in various formats.

Usage
-----

.. raw:: html

    <div class="highlight"><pre>
    <span class="c1">// Create color from hexadecimal strings</span>
    <span class="nc">kn</span>::<span class="nc">Color</span> <span class="n">black</span> <span class="o">=</span> <span class="nc">kn</span>::<span class="nc">color</span>::<span class="nf">fromHex</span><span class="p">(</span><span class="s">"#000"</span><span class="p">)</span><span class="p">;</span>
    <span class="nc">kn</span>::<span class="nc">Color</span> <span class="n">white</span> <span class="o">=</span> <span class="nc">kn</span>::<span class="nc">color</span>::<span class="nf">fromHex</span><span class="p">(</span><span class="s">"FFFFFF"</span><span class="p">)</span><span class="p">;</span>

    <span class="c1">// Invert a color</span>
    <span class="nc">kn</span>::<span class="nc">Color</span> <span class="n">inverted</span> <span class="o">=</span> <span class="nc">kn</span>::<span class="nc">color</span>::<span class="nf">invert</span><span class="p">(</span><span class="nc">kn</span>::<span class="nc">color</span>::<span class="n">GREEN</span><span class="p">)</span><span class="p">;</span>
    </pre></div>

Members
-------

.. doxygenstruct:: kn::Color
    :members:

Functions
---------

.. doxygenfunction:: kn::color::fromHex

.. doxygenfunction:: kn::color::fromHSV

.. doxygenfunction:: kn::color::lerp

.. doxygenfunction:: kn::color::invert

Constants
---------

.. doxygenvariable:: kn::color::BLACK
.. doxygenvariable:: kn::color::WHITE
.. doxygenvariable:: kn::color::RED
.. doxygenvariable:: kn::color::GREEN
.. doxygenvariable:: kn::color::BLUE
.. doxygenvariable:: kn::color::YELLOW
.. doxygenvariable:: kn::color::MAGENTA
.. doxygenvariable:: kn::color::CYAN
.. doxygenvariable:: kn::color::GRAY
.. doxygenvariable:: kn::color::GREY
.. doxygenvariable:: kn::color::DARK_GRAY
.. doxygenvariable:: kn::color::DARK_GREY
.. doxygenvariable:: kn::color::LIGHT_GRAY
.. doxygenvariable:: kn::color::LIGHT_GREY
.. doxygenvariable:: kn::color::ORANGE
.. doxygenvariable:: kn::color::BROWN
.. doxygenvariable:: kn::color::PINK
.. doxygenvariable:: kn::color::PURPLE
.. doxygenvariable:: kn::color::NAVY
.. doxygenvariable:: kn::color::TEAL
.. doxygenvariable:: kn::color::OLIVE