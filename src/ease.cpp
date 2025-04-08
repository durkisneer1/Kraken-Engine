#include "Ease.hpp"

namespace kn::ease
{

double inQuad(const double t) { return t * t; }

double outQuad(const double t) { return -(t * (t - 2)); }

double inOutQuad(const double t)
{
    if (t < 0.5)
        return 2 * t * t;
    else
        return (-2 * t * t) + (4 * t) - 1;
}

double inBounce(const double t) { return 1 - outBounce(1 - t); }

double outBounce(const double t)
{
    if (t < 4 / 11.0)
    {
        return (121 * t * t) / 16.0;
    }
    else if (t < 8 / 11.0)
    {
        return (363 / 40.0 * t * t) - (99 / 10.0 * t) + 17 / 5.0;
    }
    else if (t < 9 / 10.0)
    {
        return (4356 / 361.0 * t * t) - (35442 / 1805.0 * t) + 16061 / 1805.0;
    }
    else
    {
        return (54 / 5.0 * t * t) - (513 / 25.0 * t) + 268 / 25.0;
    }
}

double inOutBounce(const double t)
{
    if (t < 0.5)
    {
        return 0.5 * inBounce(t * 2);
    }
    else
    {
        return 0.5 * outBounce(t * 2 - 1) + 0.5;
    }
}

} // namespace kn::ease