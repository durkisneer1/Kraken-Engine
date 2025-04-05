AnimationController
===================

.. warning::

    This class is still in development and is subject to change at any time.

Description
-----------

The **AnimationController** class is used to control the playback of animations.
It can pause and resume animations, get the current frame content, and switch between animations.

What the AnimationController class does **NOT** do is provide a draw function.
This design decision is to give users the flexibility to draw the current frame in a desired position and size.

Usage
-----

.. raw:: html

    <div class="highlight"><pre>
    <span class="c1">// Instantiate an AnimationController.</span>
    <span class="nc">kn</span>::<span class="nc">AnimationController</span> <span class="n">animController</span><span class="p">;</span>

    <span class="c1">// Load animations from a sprite sheet where every frame is 16x16 pixels and a directory.</span>
    <span class="n">animController</span>.<span class="nf">loadSpriteSheet</span><span class="p">(</span><span class="s">"idle"</span><span class="p">,</span> <span class="s">"assets/idle.png"</span><span class="p">,</span> <span class="p">{</span><span class="mi">16</span><span class="p">,</span> <span class="mi">16</span><span class="p">}</span><span class="p">,</span> <span class="mi">5</span><span class="p">);</span>  <span class="c1">// 5fps</span>
    <span class="n">animController</span>.<span class="nf">loadFolder</span><span class="p">(</span><span class="s">"walk"</span><span class="p">,</span> <span class="s">"assets/walk"</span><span class="p">,</span> <span class="mi">10</span><span class="p">);</span>  <span class="c1">// 10fps</span>

    <span class="c1">// Since the current animation set is the last one added,</span>
    <span class="c1">// we can switch to the first animation by name.</span>
    <span class="n">animController</span>.<span class="nf">setAnim</span><span class="p">(</span><span class="s">"idle"</span><span class="p">);</span>

    <span class="c1">// Change the animation controller's playback speed.</span>
    <span class="n">animController</span>.<span class="nf">setPlaybackSpeed</span><span class="p">(</span><span class="o">-</span><span class="mf">1.5f</span><span class="p">);</span>  <span class="c1">// Reverse playback at 1.5x speed.</span>

    <span class="c1">// Using AnimationController::nextFrame is simple.</span>
    <span class="c1">// It returns the current frame texture, srcRect, and advances the animation.</span>
    <span class="k">const</span> <span class="nc">kn</span>::<span class="nc">Frame</span><span class="o">*</span> <span class="n">frame</span> <span class="o">=</span> <span class="n">animController</span>.<span class="nf">nextFrame</span><span class="p">(</span><span class="n">deltaTime</span><span class="p">);</span>

    <span class="c1">// Draw the current frame texture at position (50, 50) and size (16, 16).</span>
    <span class="nc">kn</span>::<span class="nc">window</span>::<span class="nf">blit</span><span class="p">(</span><span class="o">*</span><span class="n">frame</span><span class="p">-></span><span class="n">tex</span><span class="p">,</span> <span class="p">{</span><span class="mi">50</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span> <span class="mi">16</span><span class="p">,</span> <span class="mi">16</span><span class="p">},</span> <span class="n">frame</span><span class="p">-></span><span class="n">rect</span><span class="p">);</span>
    </pre></div>

Members
-------

.. doxygenstruct:: kn::Frame
    :members:
    :undoc-members:

.. doxygenstruct:: kn::Animation
    :members:
    :undoc-members:

.. doxygenclass:: kn::AnimationController
    :members:
