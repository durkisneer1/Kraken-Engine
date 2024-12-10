Coding Guidelines
=================

This document outlines the coding guidelines for Kraken Engine.
These guidelines are intended to ensure that Kraken stays in its best shape and documentation is consistent and easy to read.

General Principles
------------------

- **Consistency**: Follow the style of the surrounding code. This is elaborated in the next section.
- **Clarity**: Write code that's easy to read and understand. This means using descriptive names for variables, functions, and classes.
- **Documentation**: Write clear, concise, and useful comments.
- **Testing**: Write tests for your code (you may ask an experienced contributor to assist you).
- **Error Handling**: Check for errors and handle them appropriately.


Style Guidelines
----------------

Kraken Engine uses a consistent code style defined by the ``.clang-format`` file in the root directory. Additionally, the ``.pre-commit-config.yaml`` file automatically runs clang-format on staged files before committing, ensuring proper formatting.

However, the formatter doesn't catch everything. Please follow these additional guidelines:

- **Naming Conventions**:
    - Classes, Structs, and Enums: ``PascalCase``
    - Functions and Variables: ``camelCase``
    - Constants: ``ALL_CAPS``
    - Header Files: ``PascalCase.hpp``
    - Source Files: ``snake_case.cpp``
- **Header Includes**: Only include headers that are strictly necessary in a given file. Avoid including general-purpose headers (e.g., ``<iostream>``) in header files unless they are directly needed there. Instead, include them in source files where applicable. This practice reduces unnecessary dependencies and improves compile times.
- **Comments**: Focus comments on the *why* behind your code, not the *what*. Clear and descriptive function and variable names should make the code's intent self-explanatory.

Documentation Guidelines
------------------------

Kraken Engine uses **Sphinx** and **Doxygen** for generating documentation.
Follow these guidelines to maintain consistency and clarity:

Writing Docstrings
~~~~~~~~~~~~~~~~~~

When writing docstrings, adhere to the **Doxygen** format. Here's an example:

.. code-block:: cpp

    /**
     * @brief Adds two numbers.
     * 
     * @param a The left-hand side operand.
     * @param b The right-hand side operand.
     * 
     * @return The sum of a and b.
     */
    int addNums(int a, int b);

For more details on Doxygen formatting, refer to the `official Doxygen documentation <https://www.doxygen.nl/manual/docblocks.html>`_.

Writing Documentation
~~~~~~~~~~~~~~~~~~~~~

Use **reStructuredText (RST)** format for creating and editing documentation files.

- If you add a new class, function, or namespace to the codebase, create a corresponding ``.rst`` file in the appropriate directory under ``docs/``.
- Include the following details in the ``.rst`` file:
    - A clear description of the class, function, or namespace.
    - Example usage code (if applicable).
    - Doxygen's generated documentation.

For guidance on RST syntax, check the `official Sphinx documentation <https://www.sphinx-doc.org/en/master/usage/restructuredtext/index.html>`_.  
You can also review existing ``.rst`` files in the repository as examples.
