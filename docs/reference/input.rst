input
=====

.. warning::

    This namespace is still in development and is subject to change at any time.

Description
-----------

The **input** namespace lets you create binds for different kinds of input.

Usage
-----

.. raw:: html

    <div class="highlight"><pre>
    <span class="c1">/* Bind the 'left' action to:</span>
    <span class="c1">   - The 'a' key</span>
    <span class="c1">   - The left arrow key</span>
    <span class="c1">   - The left stick (negative direction) on a controller</span>
    <span class="c1">*/</span>
    <span class="nc">kn</span>::<span class="nc">input</span>::<span class="nf">bind</span><span class="p">(</span><span class="s">"left"</span><span class="p">,</span>
    <span class="p">    {</span>
            <span class="nc">kn</span>::<span class="nf">InputAction</span><span class="p">(</span><span class="nc">kn</span>::<span class="n">S_a</span><span class="p">),</span>
            <span class="nc">kn</span>::<span class="nf">InputAction</span><span class="p">(</span><span class="nc">kn</span>::<span class="n">S_LEFT</span><span class="p">),</span>
            <span class="nc">kn</span>::<span class="nf">InputAction</span><span class="p">(</span><span class="nc">kn</span>::<span class="n">C_AXIS_LEFTX</span><span class="p">,</span> <span class="kc">false</span><span class="p">),</span>
    <span class="p">    }</span>
    <span class="p">);</span>

    <span class="c1">/* Bind the 'right' action to:</span>
    <span class="c1">   - The 'd' key</span>
    <span class="c1">   - The right arrow key</span>
    <span class="c1">   - The left stick (positive direction) on a controller</span>
    <span class="c1">*/</span>
    <span class="nc">kn</span>::<span class="nc">input</span>::<span class="nf">bind</span><span class="p">(</span><span class="s">"right"</span><span class="p">,</span>
    <span class="p">    {</span>
            <span class="nc">kn</span>::<span class="nf">InputAction</span><span class="p">(</span><span class="nc">kn</span>::<span class="n">S_d</span><span class="p">),</span>
            <span class="nc">kn</span>::<span class="nf">InputAction</span><span class="p">(</span><span class="nc">kn</span>::<span class="n">S_RIGHT</span><span class="p">),</span>
            <span class="nc">kn</span>::<span class="nf">InputAction</span><span class="p">(</span><span class="nc">kn</span>::<span class="n">C_AXIS_LEFTX</span><span class="p">,</span> <span class="kc">true</span><span class="p">),</span>
    <span class="p">    }</span>
    <span class="p">);</span>

    <span class="c1">/* Bind the 'jump' action to:</span>
    <span class="c1">   - The space key</span>
    <span class="c1">   - The south/bottom button on a controller</span>
    <span class="c1">*/</span>
    <span class="nc">kn</span>::<span class="nc">input</span>::<span class="nf">bind</span><span class="p">(</span><span class="s">"jump"</span><span class="p">,</span>
    <span class="p">    {</span>
            <span class="nc">kn</span>::<span class="nf">InputAction</span><span class="p">(</span><span class="nc">kn</span>::<span class="n">S_SPACE</span><span class="p">),</span>
            <span class="nc">kn</span>::<span class="nf">InputAction</span><span class="p">(</span><span class="nc">kn</span>::<span class="n">C_SOUTH</span><span class="p">),</span>
    <span class="p">    }</span>
    <span class="p">);</span>

    <span class="c1">// Check if the 'jump' action was just pressed</span>
    <span class="k">if</span> <span class="p">(</span><span class="n">onGround</span><span class="p">)</span> <span class="p">{</span>
        <span class="k">if</span> <span class="p">(</span><span class="nc">kn</span>::<span class="nc">input</span>::<span class="nf">isJustPressed</span><span class="p">(</span><span class="s">"jump"</span><span class="p">)</span><span class="p">)</span> <span class="p">{</span>
            <span class="n">onGround</span> <span class="o">=</span> <span class="kc">false</span><span class="p">;</span>
            <span class="c1">// Handle jump action</span>
        <span class="p">}</span>
    <span class="p">}</span>

    <span class="c1">// Get the direction of the 'left' and 'right' actions</span>
    <span class="k">const</span> <span class="k">double</span> <span class="n">xDirection</span> <span class="o">=</span> <span class="nc">kn</span>::<span class="nc">input</span>::<span class="nf">getAxis</span><span class="p">(</span><span class="s">"left"</span><span class="p">,</span> <span class="s">"right"</span><span class="p">)</span><span class="p">;</span>
    </pre></div>

Members
-------

.. doxygenstruct:: kn::InputAction
    :members:

Functions
---------

.. doxygenfunction:: kn::input::bind

.. doxygenfunction:: kn::input::unbind

.. doxygenfunction:: kn::input::getDirection

.. doxygenfunction:: kn::input::getAxis

.. doxygenfunction:: kn::input::isPressed

.. doxygenfunction:: kn::input::isJustPressed

.. doxygenfunction:: kn::input::isJustReleased
