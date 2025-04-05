TileMap
=======

.. warning::

    This class is still in development and is subject to change at any time.

Description
-----------

The **TileMap** class is used to load tile maps from a Tiled tmx file and render them.
It also allows for getting a layer or a collection of tiles from one or more layers.

What the TileMap class does **NOT** support at the moment is the use of more than one tile set.

.. note:: It is recommended to have a border around the tiles to prevent texture bleeding.

Usage
-----

.. raw:: html

    <div class="highlight"><pre>
    <span class="c1">// Load a tile map from a tmx file where its tileset has a 1px border around each tile.</span>
    <span class="nc">kn</span>::<span class="nc">TileMap</span> <span class="n">tileMap</span> <span class="o">=</span> <span class="nc">kn</span>::<span class="nc">TileMap</span><span class="p">(</span><span class="s">"assets/map.tmx"</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span>

    <span class="c1">// Get the layer named "ground" from the tile map.</span>
    <span class="k">const</span> <span class="nc">kn</span>::<span class="nc">Layer</span><span class="o">*</span> <span class="n">groundLayer</span> <span class="o">=</span> <span class="n">tileMap</span>.<span class="nf">getLayer</span><span class="p">(</span><span class="s">"ground"</span><span class="p">);</span>

    <span class="c1">// Iterate over the tiles in the ground layer to check for collisions.</span>
    <span class="k">for</span> <span class="p">(</span><span class="k">const</span> <span class="nc">kn</span>::<span class="nc">Tile</span><span class="o">&amp;</span> <span class="n">tile</span> <span class="o">:</span> <span class="n">groundLayer</span><span class="p">.</span><span class="n">tiles</span><span class="p">)</span> <span class="p">{</span>
        <span class="k">if</span> <span class="p">(</span><span class="n">player</span><span class="p">.</span><span class="n">rect</span><span class="p">.</span><span class="nf">collideRect</span><span class="p">(</span><span class="n">tile</span><span class="p">.</span><span class="n">collider</span><span class="p">)</span><span class="p">)</span> <span class="p">{</span>
            <span class="c1">// Handle collision.</span>

            <span class="c1">// You can even check if the tile is in a targeted layer.</span>
            <span class="k">if</span> <span class="p">(</span><span class="n">tile</span><span class="p">-></span><span class="n">layer</span><span class="p">.</span><span class="n">name</span> <span class="o">==</span> <span class="s">"lava"</span><span class="p">)</span> <span class="p">{</span>
                <span class="c1">// Handle collision with the lava layer.</span>
            <span class="p">}</span>
        <span class="p">}</span>
    <span class="p">}</span>

    <span class="c1">// If you need to get a collection of tiles from multiple layers.</span>
    <span class="nc">std</span><span class="p">::</span><span class="nc">vector</span><span class="p">&lt;</span><span class="nc">kn</span>::<span class="nc">Tile</span><span class="p">&gt;</span> <span class="n">tiles</span> <span class="o">=</span> <span class="n">tileMap</span>.<span class="nf">getTileCollection</span><span class="p">(</span><span class="p">{</span><span class="s">"levers"</span><span class="p">,</span> <span class="s">"doors"</span><span class="p">}</span><span class="p">);</span>

    <span class="c1">// Render the tile map or a specific layer.</span>
    <span class="n">tileMap</span><span class="p">.</span><span class="nf">drawMap</span><span class="p">(</span><span class="p">)</span><span class="p">;</span>
    <span class="n">tileMap</span><span class="p">.</span><span class="nf">drawLayer</span><span class="p">(</span><span class="s">"walls"</span><span class="p">);</span>
    </pre></div>

Members
-------

.. doxygenstruct:: kn::Tile
    :members:

.. doxygenstruct:: kn::Layer
    :members:

.. doxygenclass:: kn::TileMap
    :members:
