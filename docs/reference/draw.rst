draw
====

Description
-----------

The **draw** namespace provides functions to draw basic shapes and lines on the screen.

Usage
-----

.. raw:: html

    <div class="highlight"><pre>
    <span class="c1">// Draw a rectangle at position (50, 50) with size (16, 16).</span>
    <span class="nc">kn</span>::<span class="nc">draw</span>::<span class="nf">rect</span><span class="p">(</span><span class="p">{</span><span class="mi">50</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span> <span class="mi">16</span><span class="p">,</span> <span class="mi">16</span><span class="p">},</span> <span class="nc">kn</span>::<span class="nc">color</span>::<span class="n">RED</span><span class="p">);</span>

    <span class="c1">// Draw a line from (50, 50) to (100, 100) with a thickness of 4 pixels.</span>
    <span class="nc">kn</span>::<span class="nc">draw</span>::<span class="nf">line</span><span class="p">(</span><span class="p">{</span><span class="mi">50</span><span class="p">,</span> <span class="mi">50</span><span class="p">},</span> <span class="p">{</span><span class="mi">100</span><span class="p">,</span> <span class="mi">100</span><span class="p">},</span> <span class="nc">kn</span>::<span class="nc">color</span>::<span class="n">GREEN</span><span class="p">,</span> <span class="mi">4</span><span class="p">);</span>

    <span class="c1">// Draw a point at position (50, 50).</span>
    <span class="nc">kn</span>::<span class="nc">draw</span>::<span class="nf">point</span><span class="p">(</span><span class="p">{</span><span class="mi">50</span><span class="p">,</span> <span class="mi">50</span><span class="p">},</span> <span class="nc">kn</span>::<span class="nc">color</span>::<span class="n">BLUE</span><span class="p">);</span>

    <span class="c1">// Draw a circle at position (50, 50) with radius 16.</span>
    <span class="nc">kn</span>::<span class="nc">draw</span>::<span class="nf">circle</span><span class="p">(</span><span class="p">{</span><span class="mi">50</span><span class="p">,</span> <span class="mi">50</span><span class="p">},</span> <span class="mi">16</span><span class="p">,</span> <span class="nc">kn</span>::<span class="nc">color</span>::<span class="n">YELLOW</span><span class="p">);</span>
    </pre></div>

Functions
---------

.. doxygenfunction:: kn::draw::rect

.. doxygenfunction:: kn::draw::line

.. doxygenfunction:: kn::draw::point

.. doxygenfunction:: kn::draw::circle
