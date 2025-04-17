Surface
=======

.. warning::

    This class is still in development and is subject to change at any time.

Description
-----------

The **Surface** class is used to load image files and apply transformations.
You can either load a surface from a file or create a surface of a solid color.
The surface is a 2D image that can be manipulated before being converted to a texture for rendering.

Usage
-----

.. raw:: html

    <div class="highlight"><pre>
    <span class="c1">// Create a 16x16 surface then fill it with red color.</span>
    <span class="nc">kn</span>::<span class="nc">Surface</span> <span class="n">surface</span><span class="p">(</span><span class="p">{</span><span class="mi">16</span><span class="p">,</span> <span class="mi">16</span><span class="p">}</span><span class="p">);</span>
    <span class="n">surface</span><span class="p">.</span><span class="nf">fill</span><span class="p">(</span><span class="nc">kn</span>::<span class="nc">color</span>::<span class="n">RED</span><span class="p">);</span>

    <span class="c1">// Get a rect representing the surface dimensions.</span>
    <span class="nc">kn</span>::<span class="nc">Rect</span> <span class="n">rect</span> <span class="o">=</span> <span class="n">surface</span><span class="p">.</span><span class="nf">getRect</span><span class="p">(</span><span class="p">)</span><span class="p">;</span>
    <span class="n">rect</span><span class="p">.</span><span class="nf">center</span><span class="p">(</span><span class="p">{</span><span class="mi">100</span><span class="p">,</span> <span class="mi">100</span><span class="p">}</span><span class="p">);</span>

    <span class="c1">// Instantiate a Texture object from the surface.</span>
    <span class="nc">kn</span>::<span class="nc">Texture</span> <span class="n">texture</span><span class="p">(</span><span class="n">surface</span><span class="p">);</span>

    <span class="c1">// Draw the surface.</span>
    <span class="nc">kn</span>::<span class="nc">window</span>::<span class="nf">blit</span><span class="p">(</span><span class="n">texture</span><span class="p">,</span> <span class="n">rect</span><span class="p">);</span>
    </pre></div>

Members
-------

.. note:: The internal SDL_Surface* is a nullptr until any loader method is called.

.. doxygenclass:: kn::Surface
    :members: