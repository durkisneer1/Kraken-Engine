Mask
====

.. warning::

    This class is still in development and is subject to change at any time.

Description
-----------

The `Mask` class is used to create a mask from a surface.
It is currently only capable of pixel-perfect collision detection, but more features are on the way.

Usage
-----

.. raw:: html

    <div class="highlight"><pre>
    <span class="c1">// Load an image as a surface</span>
    <span class="nc">kn</span>::<span class="nc">Surface</span> <span class="n">surf</span>(<span class="s">"assets/player.png"</span>);

    <span class="c1">// Create a mask and rect from the surface</span>
    <span class="nc">kn</span>::<span class="nc">Mask</span> <span class="n">maskA</span>(<span class="n">surf</span>);
    <span class="nc">kn</span>::<span class="nc">Rect</span> <span class="n">rectA</span> <span class="o">=</span> <span class="n">surf</span>.<span class="nf">getRect</span>();

    <span class="nc">kn</span>::<span class="nc">Mask</span> <span class="n">maskB</span>(<span class="n">surf</span>);
    <span class="nc">kn</span>::<span class="nc">Rect</span> <span class="n">rectB</span> <span class="o">=</span> <span class="n">surf</span>.<span class="nf">getRect</span>();

    <span class="c1">// Check for rect collision before mask collision for performance</span>
    <span class="k">if</span> (<span class="n">rectA</span>.<span class="nf">collideRect</span>(<span class="n">rectB</span>)) {
        <span class="k">if</span> (<span class="n">maskA</span>.<span class="nf">collideMask</span>(<span class="n">maskB</span>, <span class="n">rectA</span>, <span class="n">rectB</span>)) {
            <span class="c1">// Do something with mask collision</span>
        }
        <span class="c1">// Can also handle rect collision here</span>
    }
    </pre></div>

Members
-------

.. doxygenclass:: kn::Mask
    :members: