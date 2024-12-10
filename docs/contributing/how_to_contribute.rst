How To Contribute
=================

Welcome!
Your contributions help make Kraken Engine better for everyone,
whether it's fixing a bug, adding a feature, or improving the documentation.

Prerequisites
-------------

Before you begin, ensure you have:

- A GitHub account
- Git installed locally
- A C/C++ compiler (e.g., GCC, Clang, MSVC)
- Python 3.9 or later
- Doxygen
- Familiarity with our :doc:`guidelines`

Setting Up
----------

The Kraken Engine repository uses a `dev` branch (e.g., ``0.0.6dev``) for upcoming releases. 
Base your work on this branch.

1. Fork and clone the current `dev` branch.
2. Run ``pip install -r requirements.txt`` to install dependencies.

Compiling
---------

To control which of the following targets you want to build, change the options in ``meson_options.txt``.
For example, both ``build_example`` and ``build_tests`` set to ``false`` builds only the library.
Then, run either of the following commands:

Library Only
~~~~~~~~~~~~

.. code-block:: bash

   meson setup build
   meson compile kraken -C build

Library + Example Demo
~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: bash

    meson setup build
    meson compile krakenapp -C build

Library + Test Suite
~~~~~~~~~~~~~~~~~~~~

.. code-block:: bash

    meson setup build
    meson compile krakentests -C build


Making Changes
--------------

*Before making changes to Kraken, please read the* :doc:`guidelines`.

1. Commit and push your changes to your fork.
2. Submit a pull request to the `dev` branch of the Kraken Engine repository.
3. Address any feedback from maintainers.
4. Once approved, your changes will be merged, and you will be credited in the changelog.

Thank you for contributing to Kraken Engine!
