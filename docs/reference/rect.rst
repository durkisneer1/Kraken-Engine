Rect
====

.. warning::

    This class may undergo changes in the near future.

Description
-----------

The **Rect** class represents a rectangle in 2D space. It is defined by its top-left corner and its size.
Its most common uses are source and destination rectangles in blitting operations, as well as collision detection.

It may be undocumented, but there are methods for all 9 anchor points and 4 sides of the rectangle, as shown below:

.. image:: ../_static/rect.png
    :alt: The anchor points and sides of a Rect
    :width: 500px

Usage
-----

.. raw:: html

    <div class="highlight"><pre>
    <span class="c1">// Instantiate a Rect.</span>
    <span class="nc">kn</span>::<span class="nc">Rect</span> <span class="n">rectA</span> <span class="o">=</span> <span class="p">{</span><span class="mi">50</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span> <span class="mi">16</span><span class="p">,</span> <span class="mi">16</span><span class="p">};</span>

    <span class="c1">// Instantiate another Rect.</span>
    <span class="nc">kn</span>::<span class="nc">Rect</span> <span class="n">rectB</span> <span class="o">=</span> <span class="p">{</span><span class="mi">100</span><span class="p">,</span> <span class="mi">100</span><span class="p">,</span> <span class="mi">12</span><span class="p">,</span> <span class="mi">12</span><span class="p">};</span>

    <span class="c1">// Check if they collide.</span>
    <span class="k">if</span> <span class="p">(</span><span class="n">rectA</span><span class="p">.</span><span class="nf">collideRect</span><span class="p">(</span><span class="n">rectB</span><span class="p">)</span><span class="p">)</span> <span class="p">{</span>
        <span class="c1">// Handle collision</span>
    <span class="p">}</span>

    <span class="c1">// Move the center of rectA to the center of the window</span>
    <span class="n">rectA</span><span class="p">.</span><span class="nf">center</span><span class="p">(</span><span class="nc">kn</span>::<span class="nc">window</span>::<span class="nf">getSize</span><span class="p">(</span><span class="p">)</span> <span class="o">/</span> <span class="mf">2.0</span><span class="p">);</span>

    <span class="c1">// Move the top left of rectB to the bottom right of rectA</span>
    <span class="n">rectB</span><span class="p">.</span><span class="nf">topLeft</span><span class="p">(</span><span class="n">rectA</span><span class="p">.</span><span class="nf">bottomRight</span><span class="p">(</span><span class="p">)</span><span class="p">);</span>

    <span class="c1">// Clamp rectA inside rectB</span>
    <span class="n">rectA</span><span class="p">.</span><span class="nf">clamp</span><span class="p">(</span><span class="n">rectB</span><span class="p">);</span>
    </pre></div>

Members
-------

.. doxygenstruct:: kn::Rect
    :members:
