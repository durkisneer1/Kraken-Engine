Kraken Engine Documentation
===========================

**Kraken Engine** is a fast, lightweight 2D game framework built on top of *SDL2*. It's designed to offer just the right balance between high-level convenience and low-level control, making it ideal for both hobbyists and experienced developers.

Whether you're crafting a minimalist arcade game or building a fully-featured side-scrolling adventure, Kraken gives you the tools to develop confidently and creatively.

Overview
--------

Kraken expands upon SDL2 with a rich set of utilities tailored for game development.
It wraps common patterns into intuitive systems while keeping you close to the metal when you need to be.
Features include:

- 🎮 **Unified Input System** – A clean abstraction over keyboard, mouse, and controller input with support for just-pressed and just-released logic, input rebinding, and axis detection.
- 🧭 **Animation Controller** – Effortlessly manage sprite sheet animations with flexible frame control and transitions.
- 🧱 **Tile Map Support** – Load and render Tiled TMX maps with support for layers, object groups, and tile flipping.
- 🔊 **Audio Management** – Stream music, trigger sound effects, and adjust volume levels with simple API calls.
- 🧮 **Math Utilities** – Includes custom Vec2, easing functions, time utilities, and other game-dev math helpers.
- 🖼️ **Texture & Font Handling** – Load images and fonts easily, render them with rotation, scaling, color tinting, and alpha control.

Getting Started
---------------

If you're new to Kraken, the best place to begin is the :doc:`getting_started/installation` guide.
The engine is written in modern C++ and requires a basic understanding of the language.
Over time, the API is evolving to be even more beginner-friendly.

Planned Features
----------------

Kraken is actively growing. Upcoming additions include:

- A 2D **physics engine** with collision detection and response
- Built-in **pathfinding** (A*, grid-based nav)
- Basic **raycasting**
- A **modular UI system** (planned)
- Multiplayer/networking utilities

The goal is to offer a full development toolkit while staying simple, performant, and hackable.

Community & Support
-------------------

Join the `Discord Community <https://discord.gg/GyyddE7AD5>`_ to connect with other developers, get help, or contribute to the engine.
Kraken is a solo passion project with an open-source spirit — contributions and feedback are always welcome!

Showcase
--------

Curious what others have made with Kraken Engine?  
Check out the top entries from our :doc:`most recent game jam <showcase/springjam25>`.

These projects highlight the creativity and flexibility Kraken offers.
Want to be featured? Submit your game to the next jam or share it on our Discord!

.. toctree::
    :hidden:
    :maxdepth: 1
    :caption: Getting Started

    getting_started/installation
    getting_started/create_window

.. toctree::
    :hidden:
    :maxdepth: 1
    :caption: Showcase
    
    showcase/springjam25

.. toctree::
    :hidden:
    :maxdepth: 1
    :caption: Manual

    manual/things_to_know
    manual/tutorials

.. toctree::
    :hidden:
    :maxdepth: 1
    :caption: Contributing

    contributing/how_to_contribute
    contributing/guidelines
    contributing/testing

.. toctree::
    :hidden:
    :maxdepth: 1
    :caption: API Reference

    reference/animation_controller
    reference/font
    reference/rect
    reference/sound
    reference/texture
    reference/tile_map
    reference/constants
    reference/controller
    reference/draw
    reference/ease
    reference/input
    reference/key
    reference/math
    reference/mouse
    reference/music
    reference/time
    reference/window
