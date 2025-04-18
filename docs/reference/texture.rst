Texture
=======

Description
-----------

The **Texture** class is used to load image files and apply transformations.
You can either load a texture from a file or create a texture of a solid color.

Usage
-----

.. raw:: html

    <div class="highlight"><pre>
    <span class="c1">// Instantiate a Texture object and load an image from a file.</span>
    <span class="nc">kn</span>::<span class="nc">Texture</span> <span class="n">imageTexture</span><span class="p">(</span><span class="s">"assets/image.png"</span><span class="p">);</span>

    <span class="c1">// Create a 16x16 red texture.</span>
    <span class="nc">kn</span>::<span class="nc">Texture</span> <span class="n">colorTexture</span><span class="p">(</span><span class="p">{</span><span class="mi">16</span><span class="p">,</span> <span class="mi">16</span><span class="p">}</span><span class="p">,</span> <span class="nc">kn</span>::<span class="nc">color</span>::<span class="n">RED</span><span class="p">);</span>

    <span class="c1">// Flip the image texture horizontally and rotate it 30 degrees.</span>
    <span class="n">imageTexture</span>.<span class="n">flip</span>.<span class="n">h</span> <span class="o">=</span> <span class="kc">true</span><span class="p">;</span>
    <span class="n">imageTexture</span>.<span class="n">angle</span> <span class="o">=</span> <span class="mf">30.0</span><span class="p">;</span>

    <span class="c1">// Draw the textures.</span>
    <span class="nc">kn</span>::<span class="nc">window</span>::<span class="nf">blit</span><span class="p">(</span><span class="n">imageTexture</span><span class="p">,</span> <span class="p">{</span><span class="mi">50</span><span class="p">,</span> <span class="mi">50</span><span class="p">});</span>
    <span class="nc">kn</span>::<span class="nc">window</span>::<span class="nf">blit</span><span class="p">(</span><span class="n">colorTexture</span><span class="p">,</span> <span class="p">{</span><span class="mi">100</span><span class="p">,</span> <span class="mi">100</span><span class="p">});</span>
    </pre></div>

Members
-------

.. note:: The internal SDL_Texture* is a nullptr until ``loadFromFile`` is called.

.. doxygenclass:: kn::Texture
    :members: