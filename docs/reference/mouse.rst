mouse
=====

Description
-----------

The **mouse** namespace contains functions to handle input from the mouse.

Usage
-----

.. raw:: html

    <div class="highlight"><pre>
    <span class="c1">// Check if the user just left clicked.</span>
    <span class="k">if</span> <span class="p">(</span><span class="nc">kn</span>::<span class="nc">mouse</span>::<span class="nf">isJustPressed</span><span class="p">(</span><span class="nc">kn</span>::<span class="n">M_LEFT</span><span class="p"><span class="p">)</span>)</span> <span class="p">{</span>
        <span class="c1">// Handle left mouse button press.</span>
    <span class="p">}</span>

    <span class="c1">// Get the mouse position and draw a circle at that position.</span>
    <span class="nc">kn</span>::<span class="nc">draw</span>::<span class="nf">circle</span><span class="p">(</span><span class="nc">kn</span>::<span class="nc">mouse</span>::<span class="nf">getPos</span><span class="p">(</span><span class="p">)</span><span class="p">,</span> <span class="mi">10</span><span class="p">,</span> <span class="nc">kn</span>::<span class="nc">color</span>::<span class="n">RED</span><span class="p">);</span>
    </pre></div>

Functions
---------

.. doxygenfunction:: kn::mouse::isPressed

.. doxygenfunction:: kn::mouse::isJustPressed

.. doxygenfunction:: kn::mouse::isJustReleased

.. doxygenfunction:: kn::mouse::getPos

.. doxygenfunction:: kn::mouse::getRel

.. doxygenfunction:: kn::mouse::lock

.. doxygenfunction:: kn::mouse::unlock

.. doxygenfunction:: kn::mouse::isLocked

.. doxygenfunction:: kn::mouse::hide

.. doxygenfunction:: kn::mouse::show

.. doxygenfunction:: kn::mouse::isHidden
