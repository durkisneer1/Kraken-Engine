math
====

Description
-----------

This module provides a set of mathematical functions and classes for working with 2D vectors and angles.
In case you're not familiar with the concept of a vector, it's a mathematical object that has both a magnitude and a direction.
You may read more on the subject `here <https://www.mathsisfun.com/algebra/vectors.html>`_.

Members
-------

.. doxygenstruct:: kn::math::PolarCoordinate
    :members:

.. doxygenclass:: kn::math::Vec2
    :members:

Functions
---------

.. doxygenfunction:: kn::math::scaleToLength

.. doxygenfunction:: kn::math::fromPolar

.. doxygenfunction:: kn::math::normalize

.. doxygenfunction:: kn::math::clampVec

.. doxygenfunction:: kn::math::lerpVec

.. doxygenfunction:: kn::math::lerp

.. doxygenfunction:: kn::math::remap

.. doxygenfunction:: kn::math::toDegrees

.. doxygenfunction:: kn::math::toRadians

.. doxygenfunction:: kn::math::dot

.. doxygenfunction:: kn::math::cross

.. doxygenfunction:: kn::math::angleBetween