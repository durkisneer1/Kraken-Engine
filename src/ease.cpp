#include "Ease.hpp"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#ifndef M_PI_2
#define M_PI_2 1.57079632679489661923
#endif

namespace kn::ease
{

double inQuad(const double t) { return t * t; }

double outQuad(const double t) { return -(t * (t - 2)); }

double inOutQuad(const double t)
{
    if (t < 0.5)
        return 2 * t * t;

    return (-2 * t * t) + (4 * t) - 1;
}

double inCubic(const double t) { return t * t * t; }

double outCubic(const double t)
{
    const double f = (t - 1);
    return f * f * f + 1;
}

double inOutCubic(const double t)
{
    if (t < 0.5)
        return 4 * t * t * t;

    const double f = ((2 * t) - 2);
    return 0.5 * f * f * f + 1;
}

double inQuart(const double t) { return t * t * t * t; }

double outQuart(const double t)
{
    const double f = (t - 1);
    return f * f * f * (1 - t) + 1;
}

double inOutQuart(const double t)
{
    if (t < 0.5)
        return 8 * t * t * t * t;

    const double f = (t - 1);
    return -8 * f * f * f * f + 1;
}

double inQuint(const double t) { return t * t * t * t * t; }

double outQuint(const double t)
{
    const double f = (t - 1);
    return f * f * f * f * f + 1;
}

double inOutQuint(const double t)
{
    if (t < 0.5)
        return 16 * t * t * t * t * t;

    const double f = ((2 * t) - 2);
    return 0.5 * f * f * f * f * f + 1;
}

double inSine(const double t) { return sin((t - 1) * M_PI_2) + 1; }

double outSine(const double t) { return sin(t * M_PI_2); }

double inOutSine(const double t) { return 0.5 * (1 - cos(t * M_PI)); }

double inCircular(const double t) { return 1 - sqrt(1 - (t * t)); }

double outCircular(const double t) { return sqrt((2 - t) * t); }

double inOutCircular(const double t)
{
    if (t < 0.5)
        return 0.5 * (1 - sqrt(1 - 4 * (t * t)));

    return 0.5 * (sqrt(-((2 * t) - 3) * ((2 * t) - 1)) + 1);
}

double inExpon(const double t) { return (t == 0.0) ? t : pow(2, 10 * (t - 1)); }

double outExpon(const double t) { return (t == 1.0) ? t : 1 - pow(2, -10 * t); }

double inOutExpon(const double t)
{
    if (t == 0.0 || t == 1.0)
        return t;

    if (t < 0.5)
        return 0.5 * pow(2, (20 * t) - 10);

    return -0.5 * pow(2, (-20 * t) + 10) + 1;
}

double inElastic(const double t) { return sin(13 * M_PI_2 * t) * pow(2, 10 * (t - 1)); }

double outElastic(const double t) { return sin(-13 * M_PI_2 * (t + 1)) * pow(2, -10 * t) + 1; }

double inOutElastic(const double t)
{
    if (t < 0.5)
        return 0.5 * sin(13 * M_PI_2 * (2 * t)) * pow(2, 10 * ((2 * t) - 1));

    return 0.5 * (sin(-13 * M_PI_2 * ((2 * t - 1) + 1)) * pow(2, -10 * (2 * t - 1)) + 2);
}

double inBack(const double t) { return t * t * t - t * sin(t * M_PI); }

double outBack(const double t)
{
    const double f = (1 - t);
    return 1 - (f * f * f - f * sin(f * M_PI));
}

double inOutBack(const double t)
{
    if (t < 0.5)
    {
        const double f = 2 * t;
        return 0.5 * (f * f * f - f * sin(f * M_PI));
    }

    const double f = (1 - (2 * t - 1));
    return 0.5 * (1 - (f * f * f - f * sin(f * M_PI))) + 0.5;
}

double inBounce(const double t) { return 1 - outBounce(1 - t); }

double outBounce(const double t)
{
    if (t < 4 / 11.0)
        return (121 * t * t) / 16.0;
    else if (t < 8 / 11.0)
        return (363 / 40.0 * t * t) - (99 / 10.0 * t) + 17 / 5.0;
    else if (t < 9 / 10.0)
        return (4356 / 361.0 * t * t) - (35442 / 1805.0 * t) + 16061 / 1805.0;

    return (54 / 5.0 * t * t) - (513 / 25.0 * t) + 268 / 25.0;
}

double inOutBounce(const double t)
{
    if (t < 0.5)
        return 0.5 * inBounce(t * 2);

    return 0.5 * outBounce(t * 2 - 1) + 0.5;
}

} // namespace kn::ease