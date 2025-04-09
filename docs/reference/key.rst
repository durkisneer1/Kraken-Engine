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
    <span class="c1">// Get all currently pressed keys.</span>
    <span class="k">const</span> <span class="k">auto</span><span class="o">*</span> <span class="n">keys</span> <span class="o">=</span> <span class="nc">kn</span>::<span class="nc">key</span>::<span class="nf">getPressed</span><span class="p">(</span><span class="p">)</span><span class="p">;</span>

    <span class="c1">// Check if the 'W' key is pressed.</span>
    <span class="k">if</span> <span class="p">(</span><span class="n">keys</span><span class="p">[</span><span class="nc">kn</span>::<span class="n">S_w</span><span class="p">]</span><span class="p">)</span> <span class="p">{</span>
        <span class="c1">// Handle 'W' key press.</span>
    <span class="p">}</span>
    </pre></div>

Functions
---------

.. doxygenfunction:: kn::key::getPressed

.. note:: Functions for getting keys that were just pressed or just released are planned for the future.