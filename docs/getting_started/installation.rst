Installation
============

Before starting, ensure you have the Meson build system and a C++ compiler installed.

1. In your Meson project directory, create a subdirectory called ``subprojects``.

.. raw:: html

    <div class="highlight"><pre>
    <span class="nf">mkdir</span> <span class="n">subprojects</span>
    </pre></div>

2. Download the `Kraken wrap file <https://github.com/durkisneer1/Kraken-Engine/releases/download/v0.0.11/kraken-engine.wrap>`_ and place it in the ``subprojects`` directory.

3. Include the Kraken Engine dependency in your ``meson.build`` file.

.. raw:: html

    <div class="highlight"><pre>
    <span class="nf">project</span><span class="p">(</span><span class="s">'MyProject'</span><span class="p">,</span> <span class="s">'cpp'</span><span class="p">,</span> <span class="n">default_options</span><span class="o">:</span> <span class="p">[</span><span class="s">'cpp_std=c++17'</span><span class="p">,</span> <span class="s">'default_library=static'</span><span class="p">]</span><span class="p">)</span>
    <span class="n">kraken_proj</span> <span class="o">=</span> <span class="nf">subproject</span><span class="p">(</span><span class="s">'kraken-engine'</span><span class="p">)</span>
    <span class="n">kraken_dep</span> <span class="o">=</span> <span class="n">kraken_proj</span><span class="p">.</span><span class="nf">get_variable</span><span class="p">(</span><span class="s">'kraken_engine_dep'</span><span class="p">)</span>
    <span class="nf">executable</span><span class="p">(</span><span class="s">'MyProject'</span><span class="p">,</span> <span class="s">'main.cpp'</span><span class="p">,</span> <span class="n">dependencies</span><span class="o">:</span> <span class="n">kraken_dep</span><span class="p">)</span>
    </pre></div>

4. Build and compile your project using Meson after writing a ``main.cpp``:

.. raw:: html

    <div class="highlight"><pre>
    <span class="nf">meson</span> <span class="n">setup</span> <span class="n">build</span>
    <span class="nf">cd</span> <span class="n">build</span>
    <span class="nf">meson</span> <span class="n">compile</span>
    </pre></div>

You can also use the ``-j`` flag to specify the number of threads to use to speed up compilation (e.g., ``meson compile -j4``).
