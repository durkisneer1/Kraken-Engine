============
Installation
============

Kraken Engine as of now has only been tested and confirmed to work on the following systems using `mingw64 <https://github.com/niXman/mingw-builds-binaries/releases>`_:

* Windows 10/11
* Manjaro (Arch), Ubuntu (Debian)

.. note::
    Kraken Engine is still in development and is not ready for production use.
    This means that there aren't any pre-built binaries for Kraken Engine yet, so you have to build it yourself.

Before starting, ensure you have a C++ compiler, `cmake <https://cmake.org/download/>`_, and `git <https://www.git-scm.com/downloads>`_ installed.

1. Clone repository.
2. Open install directory in cmd.
3. Enter these commands into your terminal:

.. code-block:: console

    md build
    cd build
    cmake -G "Unix Makefiles" -D CMAKE_CXX_COMPILER=x86_64-w64-mingw32-g++ ..
    make

4. Drag ``.dll`` files from ``/bin`` next to your program executable.

.. note::
    You may use your own generator and compiler as long as it compiles to 64-bit.

.. warning::
    The ``CMakeLists.txt`` file is still under development as it is currently a difficult process to include and link dependencies.
    As of now, you must include these directories:

    * ``Kraken-Engine/build/_deps/sdl-src/include``
    * ``Kraken-Engine/build/_deps/sdl_ttf-src``
    * ``Kraken-Engine/build/_deps/sdl_mixer-src/include``
    * ``Kraken-Engine/build/_deps/sdl_image-src/include``
    * ``Kraken-Engine/build/_deps/tmxlite-src/tmxlite/include``
    * ``Kraken-Engine/include``

    And for linking, you must use these directories:

    * ``Kraken-Engine/build``
    * ``Kraken-Engine/bin``
    * ``Kraken-Engine/build/_deps/sdl_image-build``
    * ``Kraken-Engine/build/_deps/sdl_mixer-build``
    * ``Kraken-Engine/build/_deps/sdl_ttf-build``
    * ``Kraken-Engine/build/_deps/freetype-build``