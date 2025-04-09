Font
====

Description
-----------

The **Font** class is used to load ttf fonts and render textures containing text.

Usage
-----

.. raw:: html

    <div class="highlight"><pre>
    <span class="c1">// Load a font file with a point size of 16.</span>
    <span class="nc">kn</span>::<span class="nc">Font</span> <span class="n">font</span><span class="p">(</span><span class="s">"assets/font.ttf"</span><span class="p">,</span> <span class="mi">16</span><span class="p">);</span>

    <span class="c1">// Render a texture containing the text "Hello, World!" in white with no anti-aliasing.</span>
    <span class="k">const</span> <span class="nc">kn</span>::<span class="nc">Texture</span> <span class="n">text</span> <span class="o">=</span> <span class="n">font</span>.<span class="nf">render</span><span class="p">(</span><span class="s">"Hello, World!"</span><span class="p">,</span> <span class="k">false</span><span class="p">,</span> <span class="nc">kn</span>::<span class="nc">color</span>::<span class="n">WHITE</span><span class="p">);</span>

    <span class="c1">// Draw the text texture, centered, at the center of the window.</span>
    <span class="nc">kn</span>::<span class="nc">window</span>::<span class="nf">blit</span><span class="p">(</span><span class="n">text</span><span class="p">,</span> <span class="nc">kn</span>::<span class="nc">window</span>::<span class="nf">getSize</span><span class="p">(</span><span class="p">)</span> <span class="o">/</span> <span class="mi">2</span><span class="p">,</span> <span class="nc">kn</span>::<span class="n">CENTER</span><span class="p">);</span>
    </pre></div>

Members
-------

.. doxygenclass:: kn::Font
    :members: