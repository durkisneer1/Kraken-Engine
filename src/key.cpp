#include "Key.hpp"
#include "Math.hpp"
#include <SDL.h>
#include <algorithm>
#include <unordered_map>

namespace kn::key
{
static std::unordered_map<std::string, std::vector<Scancode>> _keyBindings;
static const uint8_t* _pressed = nullptr;
static const auto _isPressedLambda = [](const Scancode key) { return _pressed[key]; };

const uint8_t* getPressed() { return SDL_GetKeyboardState(nullptr); }

bool isPressed(const std::string& name)
{
    if (name.empty())
        return false;

    if (_keyBindings.find(name) == _keyBindings.end())
        return false;

    _pressed = getPressed();
    return std::any_of(_keyBindings[name].begin(), _keyBindings[name].end(), _isPressedLambda);
}

void bind(const std::string& name, const std::vector<Scancode>& keys)
{
    if (name.empty())
    {
        WARN("Key binding name cannot be empty")
        return;
    }

    _keyBindings[name] = keys;
}

void unbind(const std::string& name) { _keyBindings.erase(name); }

math::Vec2 getDirection(const std::string& left, const std::string& right, const std::string& up,
                        const std::string& down)
{
    _pressed = getPressed();
    static const auto getAxis = [&](const std::string& negativeKey, const std::string& positiveKey)
    {
        float axisValue = 0.0f;
        if (const auto it = _keyBindings.find(negativeKey);
            it != _keyBindings.end() &&
            std::any_of(it->second.begin(), it->second.end(), _isPressedLambda))
            axisValue -= 1.0f;
        if (const auto it = _keyBindings.find(positiveKey);
            it != _keyBindings.end() &&
            std::any_of(it->second.begin(), it->second.end(), _isPressedLambda))
            axisValue += 1.0f;
        return axisValue;
    };

    math::Vec2 direction{getAxis(left, right), getAxis(up, down)};

    if (direction.getLength() > 1)
        direction.normalize();

    return direction;
}

} // namespace kn::key