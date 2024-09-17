============
Installation
============

.. note::
    Kraken Engine is still in development and is not ready for production use.
    This means that there aren't any pre-built binaries for Kraken Engine yet, so you have to build it yourself.

Before starting, ensure you have meson installed, as well as the four core SDL2 frameworks installed in any package manager.

1. Clone the Kraken Engine `repository <https://github.com/durkisneer1/Kraken-Engine>`_.
2. Run the ``setup.py`` script with optional meson setup flags to install the necessary dependencies.
3. Once that's done, navigate into the ``build`` folder.
4. Run ``meson compile`` to build the static library file and optional example exe.

You will find the compiled .a file in this folder.

.. note::
	If you run into problems building the project, please open an issue.
