#pragma once

#include <SDL.h>

namespace kn
{
typedef SDL_Scancode Scancode;
typedef SDL_Keycode Keycode;
typedef SDL_GameControllerButton ControllerButton;
typedef SDL_GameControllerAxis ControllerAxis;
typedef SDL_Event Event;
typedef SDL_Color Color;

// Predefined colors
namespace color
{
constexpr Color BLACK = {0, 0, 0, 255};
constexpr Color WHITE = {255, 255, 255, 255};
constexpr Color RED = {255, 0, 0, 255};
constexpr Color GREEN = {0, 255, 0, 255};
constexpr Color BLUE = {0, 0, 255, 255};
constexpr Color YELLOW = {255, 255, 0, 255};
constexpr Color MAGENTA = {255, 0, 255, 255};
constexpr Color CYAN = {0, 255, 255, 255};
constexpr Color GRAY = {128, 128, 128, 255};
constexpr Color DARK_GRAY = {64, 64, 64, 255};
constexpr Color LIGHT_GRAY = {192, 192, 192, 255};
constexpr Color ORANGE = {255, 165, 0, 255};
constexpr Color BROWN = {139, 69, 19, 255};
constexpr Color PINK = {255, 192, 203, 255};
constexpr Color PURPLE = {128, 0, 128, 255};
constexpr Color NAVY = {0, 0, 128, 255};
constexpr Color TEAL = {0, 128, 128, 255};
constexpr Color OLIVE = {128, 128, 0, 255};
} // namespace color

// Scancodes
constexpr Scancode S_0 = SDL_SCANCODE_0;
constexpr Scancode S_1 = SDL_SCANCODE_1;
constexpr Scancode S_2 = SDL_SCANCODE_2;
constexpr Scancode S_3 = SDL_SCANCODE_3;
constexpr Scancode S_4 = SDL_SCANCODE_4;
constexpr Scancode S_5 = SDL_SCANCODE_5;
constexpr Scancode S_6 = SDL_SCANCODE_6;
constexpr Scancode S_7 = SDL_SCANCODE_7;
constexpr Scancode S_8 = SDL_SCANCODE_8;
constexpr Scancode S_9 = SDL_SCANCODE_9;
constexpr Scancode S_a = SDL_SCANCODE_A;
constexpr Scancode S_b = SDL_SCANCODE_B;
constexpr Scancode S_c = SDL_SCANCODE_C;
constexpr Scancode S_d = SDL_SCANCODE_D;
constexpr Scancode S_e = SDL_SCANCODE_E;
constexpr Scancode S_f = SDL_SCANCODE_F;
constexpr Scancode S_g = SDL_SCANCODE_G;
constexpr Scancode S_h = SDL_SCANCODE_H;
constexpr Scancode S_i = SDL_SCANCODE_I;
constexpr Scancode S_j = SDL_SCANCODE_J;
constexpr Scancode S_k = SDL_SCANCODE_K;
constexpr Scancode S_l = SDL_SCANCODE_L;
constexpr Scancode S_m = SDL_SCANCODE_M;
constexpr Scancode S_n = SDL_SCANCODE_N;
constexpr Scancode S_o = SDL_SCANCODE_O;
constexpr Scancode S_p = SDL_SCANCODE_P;
constexpr Scancode S_q = SDL_SCANCODE_Q;
constexpr Scancode S_r = SDL_SCANCODE_R;
constexpr Scancode S_s = SDL_SCANCODE_S;
constexpr Scancode S_t = SDL_SCANCODE_T;
constexpr Scancode S_u = SDL_SCANCODE_U;
constexpr Scancode S_v = SDL_SCANCODE_V;
constexpr Scancode S_w = SDL_SCANCODE_W;
constexpr Scancode S_x = SDL_SCANCODE_X;
constexpr Scancode S_y = SDL_SCANCODE_Y;
constexpr Scancode S_z = SDL_SCANCODE_Z;
constexpr Scancode S_DOWN = SDL_SCANCODE_DOWN;
constexpr Scancode S_LEFT = SDL_SCANCODE_LEFT;
constexpr Scancode S_RIGHT = SDL_SCANCODE_RIGHT;
constexpr Scancode S_UP = SDL_SCANCODE_UP;
constexpr Scancode S_LALT = SDL_SCANCODE_LALT;
constexpr Scancode S_LCTRL = SDL_SCANCODE_LCTRL;
constexpr Scancode S_LSHIFT = SDL_SCANCODE_LSHIFT;
constexpr Scancode S_RALT = SDL_SCANCODE_RALT;
constexpr Scancode S_RCTRL = SDL_SCANCODE_RCTRL;
constexpr Scancode S_RETURN = SDL_SCANCODE_RETURN;
constexpr Scancode S_RSHIFT = SDL_SCANCODE_RSHIFT;
constexpr Scancode S_SPACE = SDL_SCANCODE_SPACE;
constexpr Scancode S_TAB = SDL_SCANCODE_TAB;

// Event types
constexpr SDL_EventType QUIT = SDL_QUIT;
constexpr SDL_EventType DISPLAYEVENT = SDL_DISPLAYEVENT;
constexpr SDL_EventType WINDOWEVENT = SDL_WINDOWEVENT;
constexpr SDL_EventType SYSWMEVENT = SDL_SYSWMEVENT;
constexpr SDL_EventType KEYDOWN = SDL_KEYDOWN;
constexpr SDL_EventType KEYUP = SDL_KEYUP;
constexpr SDL_EventType TEXTEDITING = SDL_TEXTEDITING;
constexpr SDL_EventType TEXTINPUT = SDL_TEXTINPUT;
constexpr SDL_EventType KEYMAPCHANGED = SDL_KEYMAPCHANGED;
constexpr SDL_EventType MOUSEMOTION = SDL_MOUSEMOTION;
constexpr SDL_EventType MOUSEBUTTONDOWN = SDL_MOUSEBUTTONDOWN;
constexpr SDL_EventType MOUSEBUTTONUP = SDL_MOUSEBUTTONUP;
constexpr SDL_EventType MOUSEWHEEL = SDL_MOUSEWHEEL;
constexpr SDL_EventType JOYAXISMOTION = SDL_JOYAXISMOTION;
constexpr SDL_EventType JOYBALLMOTION = SDL_JOYBALLMOTION;
constexpr SDL_EventType JOYHATMOTION = SDL_JOYHATMOTION;
constexpr SDL_EventType JOYBUTTONDOWN = SDL_JOYBUTTONDOWN;
constexpr SDL_EventType JOYBUTTONUP = SDL_JOYBUTTONUP;
constexpr SDL_EventType JOYDEVICEADDED = SDL_JOYDEVICEADDED;
constexpr SDL_EventType JOYDEVICEREMOVED = SDL_JOYDEVICEREMOVED;
constexpr SDL_EventType CONTROLLERAXISMOTION = SDL_CONTROLLERAXISMOTION;
constexpr SDL_EventType CONTROLLERBUTTONDOWN = SDL_CONTROLLERBUTTONDOWN;
constexpr SDL_EventType CONTROLLERBUTTONUP = SDL_CONTROLLERBUTTONUP;
constexpr SDL_EventType CONTROLLERDEVICEADDED = SDL_CONTROLLERDEVICEADDED;
constexpr SDL_EventType CONTROLLERDEVICEREMOVED = SDL_CONTROLLERDEVICEREMOVED;
constexpr SDL_EventType CONTROLLERDEVICEREMAPPED = SDL_CONTROLLERDEVICEREMAPPED;
constexpr SDL_EventType CLIPBOARDUPDATE = SDL_CLIPBOARDUPDATE;
constexpr SDL_EventType DROPFILE = SDL_DROPFILE;
constexpr SDL_EventType DROPTEXT = SDL_DROPTEXT;
constexpr SDL_EventType DROPBEGIN = SDL_DROPBEGIN;
constexpr SDL_EventType DROPCOMPLETE = SDL_DROPCOMPLETE;
constexpr SDL_EventType AUDIODEVICEADDED = SDL_AUDIODEVICEADDED;
constexpr SDL_EventType AUDIODEVICEREMOVED = SDL_AUDIODEVICEREMOVED;
constexpr SDL_EventType USEREVENT = SDL_USEREVENT;

// Keycodes
constexpr SDL_KeyCode K_0 = SDLK_0;
constexpr SDL_KeyCode K_1 = SDLK_1;
constexpr SDL_KeyCode K_2 = SDLK_2;
constexpr SDL_KeyCode K_3 = SDLK_3;
constexpr SDL_KeyCode K_4 = SDLK_4;
constexpr SDL_KeyCode K_5 = SDLK_5;
constexpr SDL_KeyCode K_6 = SDLK_6;
constexpr SDL_KeyCode K_7 = SDLK_7;
constexpr SDL_KeyCode K_8 = SDLK_8;
constexpr SDL_KeyCode K_9 = SDLK_9;
constexpr SDL_KeyCode K_a = SDLK_a;
constexpr SDL_KeyCode K_b = SDLK_b;
constexpr SDL_KeyCode K_c = SDLK_c;
constexpr SDL_KeyCode K_d = SDLK_d;
constexpr SDL_KeyCode K_e = SDLK_e;
constexpr SDL_KeyCode K_f = SDLK_f;
constexpr SDL_KeyCode K_g = SDLK_g;
constexpr SDL_KeyCode K_h = SDLK_h;
constexpr SDL_KeyCode K_i = SDLK_i;
constexpr SDL_KeyCode K_j = SDLK_j;
constexpr SDL_KeyCode K_k = SDLK_k;
constexpr SDL_KeyCode K_l = SDLK_l;
constexpr SDL_KeyCode K_m = SDLK_m;
constexpr SDL_KeyCode K_n = SDLK_n;
constexpr SDL_KeyCode K_o = SDLK_o;
constexpr SDL_KeyCode K_p = SDLK_p;
constexpr SDL_KeyCode K_q = SDLK_q;
constexpr SDL_KeyCode K_r = SDLK_r;
constexpr SDL_KeyCode K_s = SDLK_s;
constexpr SDL_KeyCode K_t = SDLK_t;
constexpr SDL_KeyCode K_u = SDLK_u;
constexpr SDL_KeyCode K_v = SDLK_v;
constexpr SDL_KeyCode K_w = SDLK_w;
constexpr SDL_KeyCode K_x = SDLK_x;
constexpr SDL_KeyCode K_y = SDLK_y;
constexpr SDL_KeyCode K_z = SDLK_z;
constexpr SDL_KeyCode K_DOWN = SDLK_DOWN;
constexpr SDL_KeyCode K_LEFT = SDLK_LEFT;
constexpr SDL_KeyCode K_RIGHT = SDLK_RIGHT;
constexpr SDL_KeyCode K_UP = SDLK_UP;
constexpr SDL_KeyCode K_APPLICATION = SDLK_APPLICATION;
constexpr SDL_KeyCode K_AUDIOMUTE = SDLK_AUDIOMUTE;
constexpr SDL_KeyCode K_AUDIONEXT = SDLK_AUDIONEXT;
constexpr SDL_KeyCode K_AUDIOPLAY = SDLK_AUDIOPLAY;
constexpr SDL_KeyCode K_AUDIOPREV = SDLK_AUDIOPREV;
constexpr SDL_KeyCode K_AUDIOSTOP = SDLK_AUDIOSTOP;
constexpr SDL_KeyCode K_BACKSLASH = SDLK_BACKSLASH;
constexpr SDL_KeyCode K_BACKSPACE = SDLK_BACKSPACE;
constexpr SDL_KeyCode K_CAPSLOCK = SDLK_CAPSLOCK;
constexpr SDL_KeyCode K_COMMA = SDLK_COMMA;
constexpr SDL_KeyCode K_DELETE = SDLK_DELETE;
constexpr SDL_KeyCode K_DISPLAYSWITCH = SDLK_DISPLAYSWITCH;
constexpr SDL_KeyCode K_END = SDLK_END;
constexpr SDL_KeyCode K_EQUALS = SDLK_EQUALS;
constexpr SDL_KeyCode K_ESCAPE = SDLK_ESCAPE;
constexpr SDL_KeyCode K_F1 = SDLK_F1;
constexpr SDL_KeyCode K_F2 = SDLK_F2;
constexpr SDL_KeyCode K_F3 = SDLK_F3;
constexpr SDL_KeyCode K_F4 = SDLK_F4;
constexpr SDL_KeyCode K_F5 = SDLK_F5;
constexpr SDL_KeyCode K_F6 = SDLK_F6;
constexpr SDL_KeyCode K_F7 = SDLK_F7;
constexpr SDL_KeyCode K_F8 = SDLK_F8;
constexpr SDL_KeyCode K_F9 = SDLK_F9;
constexpr SDL_KeyCode K_F10 = SDLK_F10;
constexpr SDL_KeyCode K_F11 = SDLK_F11;
constexpr SDL_KeyCode K_F12 = SDLK_F12;
constexpr SDL_KeyCode K_BACKQUOTE = SDLK_BACKQUOTE;
constexpr SDL_KeyCode K_HOME = SDLK_HOME;
constexpr SDL_KeyCode K_INSERT = SDLK_INSERT;
constexpr SDL_KeyCode K_KP_0 = SDLK_KP_0;
constexpr SDL_KeyCode K_KP_1 = SDLK_KP_1;
constexpr SDL_KeyCode K_KP_2 = SDLK_KP_2;
constexpr SDL_KeyCode K_KP_3 = SDLK_KP_3;
constexpr SDL_KeyCode K_KP_4 = SDLK_KP_4;
constexpr SDL_KeyCode K_KP_5 = SDLK_KP_5;
constexpr SDL_KeyCode K_KP_6 = SDLK_KP_6;
constexpr SDL_KeyCode K_KP_7 = SDLK_KP_7;
constexpr SDL_KeyCode K_KP_8 = SDLK_KP_8;
constexpr SDL_KeyCode K_KP_9 = SDLK_KP_9;
constexpr SDL_KeyCode K_KP_DIVIDE = SDLK_KP_DIVIDE;
constexpr SDL_KeyCode K_KP_ENTER = SDLK_KP_ENTER;
constexpr SDL_KeyCode K_KP_MINUS = SDLK_KP_MINUS;
constexpr SDL_KeyCode K_KP_MULTIPLY = SDLK_KP_MULTIPLY;
constexpr SDL_KeyCode K_KP_PERIOD = SDLK_KP_PERIOD;
constexpr SDL_KeyCode K_KP_PLUS = SDLK_KP_PLUS;
constexpr SDL_KeyCode K_LALT = SDLK_LALT;
constexpr SDL_KeyCode K_LCTRL = SDLK_LCTRL;
constexpr SDL_KeyCode K_LEFTBRACKET = SDLK_LEFTBRACKET;
constexpr SDL_KeyCode K_LSHIFT = SDLK_LSHIFT;
constexpr SDL_KeyCode K_MINUS = SDLK_MINUS;
constexpr SDL_KeyCode K_NUMLOCKCLEAR = SDLK_NUMLOCKCLEAR;
constexpr SDL_KeyCode K_PAGEDOWN = SDLK_PAGEDOWN;
constexpr SDL_KeyCode K_PAGEUP = SDLK_PAGEUP;
constexpr SDL_KeyCode K_PERIOD = SDLK_PERIOD;
constexpr SDL_KeyCode K_PRINTSCREEN = SDLK_PRINTSCREEN;
constexpr SDL_KeyCode K_RALT = SDLK_RALT;
constexpr SDL_KeyCode K_RCTRL = SDLK_RCTRL;
constexpr SDL_KeyCode K_RETURN = SDLK_RETURN;
constexpr SDL_KeyCode K_RIGHTBRACKET = SDLK_RIGHTBRACKET;
constexpr SDL_KeyCode K_RSHIFT = SDLK_RSHIFT;
constexpr SDL_KeyCode K_SEMICOLON = SDLK_SEMICOLON;
constexpr SDL_KeyCode K_SLASH = SDLK_SLASH;
constexpr SDL_KeyCode K_SPACE = SDLK_SPACE;
constexpr SDL_KeyCode K_TAB = SDLK_TAB;
constexpr SDL_KeyCode K_AMPERSAND = SDLK_AMPERSAND;
constexpr SDL_KeyCode K_ASTERISK = SDLK_ASTERISK;
constexpr SDL_KeyCode K_AT = SDLK_AT;
constexpr SDL_KeyCode K_CARET = SDLK_CARET;
constexpr SDL_KeyCode K_COLON = SDLK_COLON;
constexpr SDL_KeyCode K_DOLLAR = SDLK_DOLLAR;
constexpr SDL_KeyCode K_EXCLAIM = SDLK_EXCLAIM;
constexpr SDL_KeyCode K_GREATER = SDLK_GREATER;
constexpr SDL_KeyCode K_HASH = SDLK_HASH;
constexpr SDL_KeyCode K_LEFTPAREN = SDLK_LEFTPAREN;
constexpr SDL_KeyCode K_LESS = SDLK_LESS;
constexpr SDL_KeyCode K_PERCENT = SDLK_PERCENT;
constexpr SDL_KeyCode K_PLUS = SDLK_PLUS;
constexpr SDL_KeyCode K_QUESTION = SDLK_QUESTION;
constexpr SDL_KeyCode K_QUOTEDBL = SDLK_QUOTEDBL;
constexpr SDL_KeyCode K_RIGHTPAREN = SDLK_RIGHTPAREN;
constexpr SDL_KeyCode K_UNDERSCORE = SDLK_UNDERSCORE;

// Mouse buttons
constexpr int M_LEFT = SDL_BUTTON_LEFT;
constexpr int M_MIDDLE = SDL_BUTTON_MIDDLE;
constexpr int M_RIGHT = SDL_BUTTON_RIGHT;
constexpr int M_SIDE1 = SDL_BUTTON_X1;
constexpr int M_SIDE2 = SDL_BUTTON_X2;

// Controller buttonsW
constexpr ControllerButton C_A = SDL_CONTROLLER_BUTTON_A;
constexpr ControllerButton C_B = SDL_CONTROLLER_BUTTON_B;
constexpr ControllerButton C_X = SDL_CONTROLLER_BUTTON_X;
constexpr ControllerButton C_Y = SDL_CONTROLLER_BUTTON_Y;
constexpr ControllerButton C_BACK = SDL_CONTROLLER_BUTTON_BACK;
constexpr ControllerButton C_GUIDE = SDL_CONTROLLER_BUTTON_GUIDE;
constexpr ControllerButton C_START = SDL_CONTROLLER_BUTTON_START;
constexpr ControllerButton C_LEFTSTICK = SDL_CONTROLLER_BUTTON_LEFTSTICK;
constexpr ControllerButton C_RIGHTSTICK = SDL_CONTROLLER_BUTTON_RIGHTSTICK;
constexpr ControllerButton C_LEFTSHOULDER = SDL_CONTROLLER_BUTTON_LEFTSHOULDER;
constexpr ControllerButton C_RIGHTSHOULDER = SDL_CONTROLLER_BUTTON_RIGHTSHOULDER;
constexpr ControllerButton C_DPAD_UP = SDL_CONTROLLER_BUTTON_DPAD_UP;
constexpr ControllerButton C_DPAD_DOWN = SDL_CONTROLLER_BUTTON_DPAD_DOWN;
constexpr ControllerButton C_DPAD_LEFT = SDL_CONTROLLER_BUTTON_DPAD_LEFT;
constexpr ControllerButton C_DPAD_RIGHT = SDL_CONTROLLER_BUTTON_DPAD_RIGHT;

constexpr ControllerAxis C_AXIS_LEFTX = SDL_CONTROLLER_AXIS_LEFTX;
constexpr ControllerAxis C_AXIS_LEFTY = SDL_CONTROLLER_AXIS_LEFTY;
constexpr ControllerAxis C_AXIS_RIGHTX = SDL_CONTROLLER_AXIS_RIGHTX;
constexpr ControllerAxis C_AXIS_RIGHTY = SDL_CONTROLLER_AXIS_RIGHTY;
constexpr ControllerAxis C_TRIGGERLEFT = SDL_CONTROLLER_AXIS_TRIGGERLEFT;
constexpr ControllerAxis C_TRIGGERRIGHT = SDL_CONTROLLER_AXIS_TRIGGERRIGHT;

constexpr unsigned int MILLISECONDS_PER_SECOND = 1000U;

} // namespace kn
