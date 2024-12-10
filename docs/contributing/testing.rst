Testing Your Contributions
==========================

Before submitting a pull request, you should run tests and preview the documentation to ensure that your changes are correct.

Testing Code
----------------

If you haven't already, read through building the *test suite* in the :doc:`how_to_contribute` section.

Tests are written using the Google Test framework and can be found in the ``tests`` directory.
After making changes or adding new features, run the test suite to ensure that your changes do not break existing or new functionality.

Previewing Documentation
------------------------

1. Install the required dependencies via pip:

.. code-block:: bash

    pip install -r docs/requirements.txt

2. Generate the documentation with Doxygen:

.. code-block:: bash

    cd docs
    doxygen

1. Build the documentation:

.. code-block:: bash

    make -C docs html

You will find the generated documentation in the ``docs/_build/html`` directory.
If everything looks as intended, you can submit your pull request.
