controller
==========

.. warning::

    This namespace is still in development and is subject to change at any time.

Description
-----------

The **controller** namespace contains functions to handle input from a game controller.

.. note:: The default dead zone for the joysticks is 0.1f.

Usage
-----

.. raw:: html

    <div class="highlight"><pre>
    <span class="c1">// Get the direction vector of the left joystick</span>
    <span class="nc">kn</span>::<span class="nc">Vec2</span> <span class="n">leftJoystick</span> <span class="o">=</span> <span class="nc">kn</span>::<span class="nc">controller</span>::<span class="nf">getLeftJoystick</span><span class="p">(</span><span class="p">)</span><span class="p">;</span>

    <span class="c1">// Change the joysticks' dead zones</span>
    <span class="nc">kn</span>::<span class="nc">controller</span>::<span class="nf">setDeadZone</span><span class="p">(</span><span class="mf">0.2f</span><span class="p">);</span>

    <span class="c1">// Get how far the right trigger is pressed</span>
    <span class="k">if</span> <span class="p">(</span><span class="nc">kn</span>::<span class="nc">controller</span>::<span class="nf">getRightTrigger</span><span class="p">(</span><span class="p">)</span> <span class="o">&gt;</span> <span class="mf">0.5f</span><span class="p">)</span> <span class="p">{</span>
        <span class="c1">// Do something</span>
    <span class="p">}</span>

    <span class="c1">// Check if the A (bottom) button is pressed</span>
    <span class="k">if</span> <span class="p">(</span><span class="nc">kn</span>::<span class="nc">controller</span>::<span class="nf">isPressed</span><span class="p">(</span><span class="nc">kn</span>::<span class="n">C_A</span><span class="p">)</span><span class="p">)</span> <span class="p">{</span>
        <span class="c1">// Do something</span>
    <span class="p">}</span>
    </pre></div>

Functions
---------

.. doxygenfunction:: kn::controller::getLeftJoystick

.. doxygenfunction:: kn::controller::getRightJoystick

.. doxygenfunction:: kn::controller::getLeftTrigger

.. doxygenfunction:: kn::controller::getRightTrigger

.. doxygenfunction:: kn::controller::isPressed

.. doxygenfunction:: kn::controller::setDeadZone

.. doxygenfunction:: kn::controller::getDeadZone

.. note:: Functions for getting controller buttons that were just pressed or just released are planned for the future.