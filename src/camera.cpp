#include "Camera.hpp"
#include "Math.hpp"
#include "Window.hpp"

#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

namespace kn::camera
{
static math::Vec2 m_pos;
static float m_rot = 0.0f;

void pos(math::Vec2 pos) { m_pos = pos; }

math::Vec2 pos() { return m_pos; }

void rot(float rot) { m_rot = rot; }

float rot() { return m_rot; }

math::Vec2 worldToScreen(const math::Vec2& worldPos)
{
    const auto localPos = worldPos - m_pos;

    const float angleRad = m_rot * M_PI / 180.0f;
    const float sinA = std::sin(angleRad);
    const float cosA = std::cos(angleRad);

    math::Vec2 rotatedPos = {localPos.x * cosA - localPos.y * sinA,
                             localPos.x * sinA + localPos.y * cosA};

    rotatedPos += kn::window::getSize() / 2;

    return rotatedPos;
}
} // namespace kn::camera
