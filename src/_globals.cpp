#include "_globals.hpp"

bool g_scancodePressed[SDL_NUM_SCANCODES] = {};
bool g_scancodeReleased[SDL_NUM_SCANCODES] = {};

std::unordered_map<SDL_Keycode, bool> g_keycodePressed;
std::unordered_map<SDL_Keycode, bool> g_keycodeReleased;

bool g_mousePressed[MOUSE_BUTTON_COUNT] = {};
bool g_mouseReleased[MOUSE_BUTTON_COUNT] = {};

bool g_controllerPressed[SDL_CONTROLLER_BUTTON_MAX] = {};
bool g_controllerReleased[SDL_CONTROLLER_BUTTON_MAX] = {};
