#pragma once

#include <SDL.h>
#include <unordered_map>

// Scancodes
extern bool g_scancodePressed[SDL_NUM_SCANCODES];
extern bool g_scancodeReleased[SDL_NUM_SCANCODES];

// Keycodes
extern std::unordered_map<SDL_Keycode, bool> g_keycodePressed;
extern std::unordered_map<SDL_Keycode, bool> g_keycodeReleased;

constexpr size_t MOUSE_BUTTON_COUNT = 5;
extern bool g_mousePressed[MOUSE_BUTTON_COUNT];
extern bool g_mouseReleased[MOUSE_BUTTON_COUNT];

extern bool g_controllerPressed[SDL_CONTROLLER_BUTTON_MAX];
extern bool g_controllerReleased[SDL_CONTROLLER_BUTTON_MAX];

namespace kn
{
inline SDL_GameController* _controller;
} // namespace kn
