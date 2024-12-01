Installation
============

Before starting, ensure you have the Meson build system and a C++ compiler installed.

1. In your Meson project directory, create a subdirectory called ``subprojects``.

.. code-block:: bash

    mkdir subprojects

2. Run ``meson wrap install kraken-engine`` to install the latest version of Kraken Engine.

3. Include the Kraken Engine dependency in your Meson build file.

.. code-block:: python

    project('MyProject', 'cpp', default_options: ['cpp_std=c++17', 'default_library=static'])
    kraken_dep = dependency('kraken-engine')
    executable('MyProject', 'main.cpp', dependencies: kraken_dep)

4. Continue with the typical Meson build and compile process.
