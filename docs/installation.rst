============
Installation
============

Before starting, ensure you have the Meson build system and a C++ compiler installed.

1. In your Meson project directory, create a subdirectory called ``subprojects``.

    .. code-block:: bash

        mkdir subprojects

2. Run ``meson wrap install kraken-engine`` to install the latest version of Kraken Engine.

3. Include the Kraken Engine dependency in your Meson build file.

1. In your Meson project directory, create a subdirectory called ``subprojects``.

<<<<<<< HEAD
1. Clone the Kraken Engine `repository <https://github.com/durkisneer1/Kraken-Engine>`_.
2. In the top directory, run ``meson setup builddir`` twice.
3. Once that's done, navigate into the ``builddir`` folder.
4. Run ``meson compile`` to build the static library file and example exe.
=======
    .. code-block:: bash
>>>>>>> upstream/0.0.3dev

        mkdir subprojects

2. Run ``meson wrap install kraken-engine`` to install the latest version of Kraken Engine.

3. Include the Kraken Engine dependency in your Meson build file.

    .. code-block:: python

        project('MyProject', 'cpp')
        kraken_dep = dependency('kraken-engine')
        executable('MyProject', 'main.cpp', dependencies: kraken_dep)

4. Continue with the typical Meson build and compile process.

.. note::
	Currently, SDL2 builds as dynamic link libraries (DLLs). You'll need to move the SDL2 DLLs from
	``builddir/subprojects/SDL2[_image | _mixer | _ttf]`` to your executable location, usually under ``builddir``.
