ease
====

Description
-----------

The **ease** namespace provides functions for various easing functions used in animations.
Easing functions are mathematical functions that create a smooth transition between two values, often used in animations to achieve more natural movement.

If you are unsure which animation to use, you can find visual examples of each easing function at `easings.net <https://easings.net/>`_.

Usage
-----

.. raw:: html

    <div class="highlight"><pre>
    <span class="c1">// Create a new easing animation object</span>
    <span class="nc">kn</span>::<span class="nc">EasingAnimation</span> <span class="n">easeAnim</span><span class="p">(</span>
        {<span class="mi">0</span>, <span class="mi">0</span>},</span> {<span class="mi">400</span>, <span class="mi">100</span>}<span class="p">,</span> <span class="mf">5.0</span><span class="p">,</span>
        <span class="nc">kn</span>::<span class="nc">ease</span>::<span class="n">inOutQuad</span>
    <span class="p">);</span>

    <span class="c1">// Reverse the animation if it ends (example)</span>
    <span class="k">if</span> <span class="p">(</span><span class="n">easeAnim</span><span class="p">.</span><span class="nf">isFinished</span><span class="p">(</span><span class="p">)</span><span class="p">)</span> <span class="p">{</span>
        <span class="n">easeAnim</span><span class="p">.</span><span class="nf">reverse</span><span class="p">(</span><span class="p">)</span><span class="p">;</span>
    <span class="p">}</span>

    <span class="c1">// Retrieve the current position in the animation</span>
    <span class="nc">kn</span>::<span class="nc">Vec2</span> <span class="n">drawPos</span> <span class="o">=</span> <span class="n">easeAnim</span><span class="p">.</span><span class="nf">update</span><span class="p">(</span><span class="n">dt</span><span class="p">);</span>
    <span class="nc">kn</span>::<span class="nc">draw</span>::<span class="nf">circle</span><span class="p">(</span><span class="n">drawPos</span><span class="p">,</span> <span class="mi">4</span><span class="p">,</span> <span class="nc">kn</span>::<span class="nc">color</span>::<span class="n">WHITE</span><span class="p">);</span>
    </pre></div>

Members
-------

.. doxygenclass:: kn::EasingAnimation
    :members:

Functions
---------

.. doxygenfunction:: kn::ease::linear

.. doxygenfunction:: kn::ease::inQuad

.. doxygenfunction:: kn::ease::outQuad

.. doxygenfunction:: kn::ease::inOutQuad

.. doxygenfunction:: kn::ease::inCubic

.. doxygenfunction:: kn::ease::outCubic

.. doxygenfunction:: kn::ease::inOutCubic

.. doxygenfunction:: kn::ease::inQuart

.. doxygenfunction:: kn::ease::outQuart

.. doxygenfunction:: kn::ease::inOutQuart

.. doxygenfunction:: kn::ease::inQuint

.. doxygenfunction:: kn::ease::outQuint

.. doxygenfunction:: kn::ease::inOutQuint

.. doxygenfunction:: kn::ease::inSine

.. doxygenfunction:: kn::ease::outSine

.. doxygenfunction:: kn::ease::inOutSine

.. doxygenfunction:: kn::ease::inCirc

.. doxygenfunction:: kn::ease::outCirc

.. doxygenfunction:: kn::ease::inOutCirc

.. doxygenfunction:: kn::ease::inExpo

.. doxygenfunction:: kn::ease::outExpo

.. doxygenfunction:: kn::ease::inOutExpo

.. doxygenfunction:: kn::ease::inElastic

.. doxygenfunction:: kn::ease::outElastic

.. doxygenfunction:: kn::ease::inOutElastic

.. doxygenfunction:: kn::ease::inBack

.. doxygenfunction:: kn::ease::outBack

.. doxygenfunction:: kn::ease::inOutBack

.. doxygenfunction:: kn::ease::inBounce

.. doxygenfunction:: kn::ease::outBounce

.. doxygenfunction:: kn::ease::inOutBounce
