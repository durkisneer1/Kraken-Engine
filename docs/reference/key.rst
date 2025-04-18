key
===

Description
-----------

The **key** namespace contains functions to handle input from the keyboard.
If you aren't familiar with the usage of keycodes and scancodes, please refer to the `Things To Know <../manual/things_to_know.html>`_ section.

Usage
-----

.. raw:: html

    <div class="highlight"><pre>
    <span class="c1">// Check if the 'W' key is currently pressed.</span>
    <span class="k">if</span> <span class="p">(</span><span class="nc">kn</span>::<span class="nc">key</span>::<span class="nf">isPressed</span><span class="p">(</span><span class="nc">kn</span>::<span class="n">S_w</span><span class="p">)</span><span class="p">)</span> <span class="p">{</span>
        <span class="c1">// Handle 'W' key press.</span>
    <span class="p">}</span>

    <span class="c1">// Check if the escape key was just pressed.</span>
    <span class="k">if</span> <span class="p">(</span><span class="nc">kn</span>::<span class="nc">key</span>::<span class="nf">isJustPressed</span><span class="p">(</span><span class="nc">kn</span>::<span class="n">K_ESC</span><span class="p">)</span><span class="p">)</span> <span class="p">{</span>
        <span class="nc">kn</span>::<span class="nc">window</span>::<span class="nf">close</span><span class="p">(</span><span class="p">);</span>
    <span class="p">}</span>
    </pre></div>

Functions
---------

.. doxygenfunction:: kn::key::isPressed(Scancode)

.. doxygenfunction:: kn::key::isPressed(Keycode)

.. doxygenfunction:: kn::key::isJustPressed(Scancode)

.. doxygenfunction:: kn::key::isJustPressed(Keycode)

.. doxygenfunction:: kn::key::isJustReleased(Scancode)

.. doxygenfunction:: kn::key::isJustReleased(Keycode)

