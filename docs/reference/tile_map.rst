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

.. code-block:: cpp

    // Load a tile map from a tmx file where its tileset has a 1px border around each tile.
    kn::TileMap tileMap("assets/map.tmx", 1);

    // Get the layer named "ground" from the tile map.
    const kn::Layer* groundLayer = tileMap.getLayer("ground");

    // Iterate over the tiles in the ground layer to check for collisions.
    for (const kn::Tile& tile : groundLayer.tiles) {
        if (player.rect.collideRect(tile.collider)) {
            // Handle collision.

            // You can even check if the tile is in a targeted layer.
            if (tile->layer.name == "lava") {
                // Handle collision with the lava layer.
            }
        }
    }

    // If you need to get a collection of tiles from multiple layers.
    std::vector<kn::Tile> tiles = tileMap.getTileCollection({"levers", "doors"});

    // Render the tile map or a specific layer.
    tileMap.drawMap();
    tileMap.drawLayer("walls");

Members
-------

.. doxygenstruct:: kn::Tile
    :members:

.. doxygenstruct:: kn::Layer
    :members:

.. doxygenclass:: kn::TileMap
    :members:
