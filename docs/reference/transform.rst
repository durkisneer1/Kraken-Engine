transform
=========

Description
-----------

The **transform** namespace contains functions to manipulate Surface objects.
This is useful for achieving advanced effects that cannot be done on Texture objects alone.

Usage
-----

.. raw:: html

    <div class="highlight"><pre>
    <span class="c1">// Load a surface for transformation</span>
    <span class="nc">kn</span>::<span class="nc">Surface</span> <span class="n">originalSurf</span> <span class="o">=</span> <span class="nc">kn</span>::<span class="nc">Surface</span><span class="p">(</span><span class="s">"assets/image.png"</span><span class="p">)</span><span class="p">;</span>

    <span class="c1">// Scaled up by a factor of 2, flipped horizontally, and blurred with a Gaussian filter</span>
    <span class="nc">kn</span>::<span class="nc">Surface</span> <span class="n">scaledSurf</span> <span class="o">=</span> <span class="nc">kn</span>::<span class="nc">transform</span>::<span class="nf">scaleBy</span><span class="p">(</span><span class="n">originalSurf</span><span class="p">,</span> <span class="mf">2.0</span><span class="p">)</span><span class="p">;</span>
    <span class="nc">kn</span>::<span class="nc">Surface</span> <span class="n">flippedSurf</span> <span class="o">=</span> <span class="nc">kn</span>::<span class="nc">transform</span>::<span class="nf">flip</span><span class="p">(</span><span class="n">scaledSurf</span><span class="p">,</span> <span class="kc">true</span><span class="p">,</span> <span class="kc">false</span><span class="p">)</span><span class="p">;</span>
    <span class="nc">kn</span>::<span class="nc">Surface</span> <span class="n">invertedSurf</span> <span class="o">=</span> <span class="nc">kn</span>::<span class="nc">transform</span>::<span class="nf">gaussianBlur</span><span class="p">(</span><span class="n">flippedSurf</span><span class="p">,</span> <span class="mf">5.0</span><span class="p">)</span><span class="p">;</span>
    </pre></div>

Functions
---------

.. doxygenfunction:: kn::transform::flip

.. doxygenfunction:: kn::transform::scale

.. doxygenfunction:: kn::transform::scaleBy

.. doxygenfunction:: kn::transform::rotate

.. doxygenfunction:: kn::transform::boxBlur

.. doxygenfunction:: kn::transform::gaussianBlur

.. doxygenfunction:: kn::transform::invert

.. doxygenfunction:: kn::transform::grayscale