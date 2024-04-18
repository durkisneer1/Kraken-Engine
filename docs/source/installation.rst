============
Installation
============

Kraken Engine as of now is only compatible with Windows platforms.

.. note::
    Kraken Engine is still in development and is not ready for production use.
    This means that there aren't any pre-built binaries for Kraken Engine yet, so you have to build it yourself.

Before starting, ensure you have `Visual Studio 2022 <https://visualstudio.microsoft.com/downloads/>`_ and the complete SDL2 framework installed.

1. Clone the Kraken Engine `repository <https://github.com/durkisneer1/Kraken-Engine>`_.
2. Open the solution - you may have to edit the project properties to point to the correct SDL2 include and lib directories.
3. Build the solution as either a release or debug type.

You will find the .lib file in the ``x64/Release`` or ``x64/Debug`` directory.

.. note::
	If you have any issues building the solution, please open an issue.
