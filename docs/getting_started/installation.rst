Installation
============

Before starting, ensure you have the Meson build system and a C++ compiler installed.

1. In your Meson project directory, create a subdirectory called ``subprojects``.

.. code-block:: bash

    mkdir subprojects

2. Use the following command to install the latest version of Kraken Engine:

.. code-block:: bash

    meson wrap install kraken-engine

3. Include the Kraken Engine dependency in your Meson build file (usually ``meson.build``).

.. raw:: html

    <div class="highlight"><pre>
    <span class="nf">project</span>(<span class="s">'MyProject'</span>, <span class="s">'cpp'</span>, <span class="n">default_options</span>: [<span class="s">'cpp_std=c++17'</span>, <span class="s">'default_library=static'</span>])
    <span class="n">kraken_dep</span> <span class="o">=</span> <span class="nf">dependency</span>(<span class="s">'kraken-engine'</span>)
    <span class="nf">executable</span>(<span class="s">'MyProject'</span>, <span class="s">'main.cpp'</span>, <span class="n">dependencies</span>: <span class="n">kraken_dep</span>)
    </pre></div>

4. Build and compile your project using Meson:

.. code-block:: bash

    meson setup build
    cd build
    meson compile

You can also use the ``-j`` flag to specify the number of threads to use to speed up compilation (e.g., ``meson compile -j4``).

Updating
--------

To update Kraken Engine to the latest version, use the following command:

.. code-block:: bash

    meson wrap update kraken-engine
