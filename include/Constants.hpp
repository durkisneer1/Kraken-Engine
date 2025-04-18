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
typedef SDL_EventType EventType;

// Mouse buttons
enum class MouseButton : uint8_t
{
    Left = SDL_BUTTON_LEFT,
    Middle = SDL_BUTTON_MIDDLE,
    Right = SDL_BUTTON_RIGHT,
    Side1 = SDL_BUTTON_X1,
    Side2 = SDL_BUTTON_X2,
};
constexpr MouseButton M_LEFT = MouseButton::Left;
constexpr MouseButton M_MIDDLE = MouseButton::Middle;
constexpr MouseButton M_RIGHT = MouseButton::Right;
constexpr MouseButton M_SIDE1 = MouseButton::Side1;
constexpr MouseButton M_SIDE2 = MouseButton::Side2;

// Anchor points for rendering
enum class Anchor
{
    TopLeft,
    TopMid,
    TopRight,
    LeftMid,
    Center,
    RightMid,
    BottomLeft,
    BottomMid,
    BottomRight
};
constexpr Anchor TOP_LEFT = Anchor::TopLeft;
constexpr Anchor TOP_MID = Anchor::TopMid;
constexpr Anchor TOP_RIGHT = Anchor::TopRight;
constexpr Anchor LEFT_MID = Anchor::LeftMid;
constexpr Anchor CENTER = Anchor::Center;
constexpr Anchor RIGHT_MID = Anchor::RightMid;
constexpr Anchor BOTTOM_LEFT = Anchor::BottomLeft;
constexpr Anchor BOTTOM_MID = Anchor::BottomMid;
constexpr Anchor BOTTOM_RIGHT = Anchor::BottomRight;

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
constexpr Color GREY = GRAY;
constexpr Color DARK_GRAY = {64, 64, 64, 255};
constexpr Color DARK_GREY = DARK_GRAY;
constexpr Color LIGHT_GRAY = {192, 192, 192, 255};
constexpr Color LIGHT_GREY = LIGHT_GRAY;
constexpr Color ORANGE = {255, 165, 0, 255};
constexpr Color BROWN = {139, 69, 19, 255};
constexpr Color PINK = {255, 192, 203, 255};
constexpr Color PURPLE = {128, 0, 128, 255};
constexpr Color NAVY = {0, 0, 128, 255};
constexpr Color TEAL = {0, 128, 128, 255};
constexpr Color OLIVE = {128, 128, 0, 255};
} // namespace color

// Scancodes
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

constexpr Scancode S_1 = SDL_SCANCODE_1;
constexpr Scancode S_2 = SDL_SCANCODE_2;
constexpr Scancode S_3 = SDL_SCANCODE_3;
constexpr Scancode S_4 = SDL_SCANCODE_4;
constexpr Scancode S_5 = SDL_SCANCODE_5;
constexpr Scancode S_6 = SDL_SCANCODE_6;
constexpr Scancode S_7 = SDL_SCANCODE_7;
constexpr Scancode S_8 = SDL_SCANCODE_8;
constexpr Scancode S_9 = SDL_SCANCODE_9;
constexpr Scancode S_0 = SDL_SCANCODE_0;

constexpr Scancode S_RETURN = SDL_SCANCODE_RETURN;
constexpr Scancode S_ESC = SDL_SCANCODE_ESCAPE;
constexpr Scancode S_BACKSPACE = SDL_SCANCODE_BACKSPACE;
constexpr Scancode S_TAB = SDL_SCANCODE_TAB;
constexpr Scancode S_SPACE = SDL_SCANCODE_SPACE;

constexpr Scancode S_MINUS = SDL_SCANCODE_MINUS;
constexpr Scancode S_EQ = SDL_SCANCODE_EQUALS;
constexpr Scancode S_LBRACKET = SDL_SCANCODE_LEFTBRACKET;
constexpr Scancode S_RBRACKET = SDL_SCANCODE_RIGHTBRACKET;
constexpr Scancode S_BACKSLASH = SDL_SCANCODE_BACKSLASH;
constexpr Scancode S_SEMICOLON = SDL_SCANCODE_SEMICOLON;
constexpr Scancode S_APOSTROPHE = SDL_SCANCODE_APOSTROPHE;
constexpr Scancode S_GRAVE = SDL_SCANCODE_GRAVE;
constexpr Scancode S_COMMA = SDL_SCANCODE_COMMA;
constexpr Scancode S_PERIOD = SDL_SCANCODE_PERIOD;
constexpr Scancode S_SLASH = SDL_SCANCODE_SLASH;
constexpr Scancode S_CAPS = SDL_SCANCODE_CAPSLOCK;

constexpr Scancode S_F1 = SDL_SCANCODE_F1;
constexpr Scancode S_F2 = SDL_SCANCODE_F2;
constexpr Scancode S_F3 = SDL_SCANCODE_F3;
constexpr Scancode S_F4 = SDL_SCANCODE_F4;
constexpr Scancode S_F5 = SDL_SCANCODE_F5;
constexpr Scancode S_F6 = SDL_SCANCODE_F6;
constexpr Scancode S_F7 = SDL_SCANCODE_F7;
constexpr Scancode S_F8 = SDL_SCANCODE_F8;
constexpr Scancode S_F9 = SDL_SCANCODE_F9;
constexpr Scancode S_F10 = SDL_SCANCODE_F10;
constexpr Scancode S_F11 = SDL_SCANCODE_F11;
constexpr Scancode S_F12 = SDL_SCANCODE_F12;

constexpr Scancode S_PRTSCR = SDL_SCANCODE_PRINTSCREEN;
constexpr Scancode S_SCRLK = SDL_SCANCODE_SCROLLLOCK;
constexpr Scancode S_PAUSE = SDL_SCANCODE_PAUSE;
constexpr Scancode S_INS = SDL_SCANCODE_INSERT;

constexpr Scancode S_HOME = SDL_SCANCODE_HOME;
constexpr Scancode S_PGUP = SDL_SCANCODE_PAGEUP;
constexpr Scancode S_DEL = SDL_SCANCODE_DELETE;
constexpr Scancode S_END = SDL_SCANCODE_END;
constexpr Scancode S_PGDN = SDL_SCANCODE_PAGEDOWN;
constexpr Scancode S_RIGHT = SDL_SCANCODE_RIGHT;
constexpr Scancode S_LEFT = SDL_SCANCODE_LEFT;
constexpr Scancode S_DOWN = SDL_SCANCODE_DOWN;
constexpr Scancode S_UP = SDL_SCANCODE_UP;
constexpr Scancode S_NUMLOCK = SDL_SCANCODE_NUMLOCKCLEAR;

constexpr Scancode S_KP_DIV = SDL_SCANCODE_KP_DIVIDE;
constexpr Scancode S_KP_MULT = SDL_SCANCODE_KP_MULTIPLY;
constexpr Scancode S_KP_MINUS = SDL_SCANCODE_KP_MINUS;
constexpr Scancode S_KP_PLUS = SDL_SCANCODE_KP_PLUS;
constexpr Scancode S_KP_ENTER = SDL_SCANCODE_KP_ENTER;
constexpr Scancode S_KP_1 = SDL_SCANCODE_KP_1;
constexpr Scancode S_KP_2 = SDL_SCANCODE_KP_2;
constexpr Scancode S_KP_3 = SDL_SCANCODE_KP_3;
constexpr Scancode S_KP_4 = SDL_SCANCODE_KP_4;
constexpr Scancode S_KP_5 = SDL_SCANCODE_KP_5;
constexpr Scancode S_KP_6 = SDL_SCANCODE_KP_6;
constexpr Scancode S_KP_7 = SDL_SCANCODE_KP_7;
constexpr Scancode S_KP_8 = SDL_SCANCODE_KP_8;
constexpr Scancode S_KP_9 = SDL_SCANCODE_KP_9;
constexpr Scancode S_KP_0 = SDL_SCANCODE_KP_0;
constexpr Scancode S_KP_PERIOD = SDL_SCANCODE_KP_PERIOD;

constexpr Scancode S_APP = SDL_SCANCODE_APPLICATION;
constexpr Scancode S_KP_EQ = SDL_SCANCODE_KP_EQUALS;
constexpr Scancode S_EXE = SDL_SCANCODE_EXECUTE;
constexpr Scancode S_HELP = SDL_SCANCODE_HELP;
constexpr Scancode S_MENU = SDL_SCANCODE_MENU;
constexpr Scancode S_SELECT = SDL_SCANCODE_SELECT;
constexpr Scancode S_STOP = SDL_SCANCODE_STOP;
constexpr Scancode S_AGAIN = SDL_SCANCODE_AGAIN;
constexpr Scancode S_UNDO = SDL_SCANCODE_UNDO;
constexpr Scancode S_CUT = SDL_SCANCODE_CUT;
constexpr Scancode S_COPY = SDL_SCANCODE_COPY;
constexpr Scancode S_PASTE = SDL_SCANCODE_PASTE;
constexpr Scancode S_FIND = SDL_SCANCODE_FIND;
constexpr Scancode S_MUTE = SDL_SCANCODE_MUTE;
constexpr Scancode S_VOLUP = SDL_SCANCODE_VOLUMEUP;
constexpr Scancode S_VOLDN = SDL_SCANCODE_VOLUMEDOWN;

constexpr Scancode S_LCTRL = SDL_SCANCODE_LCTRL;
constexpr Scancode S_LSHIFT = SDL_SCANCODE_LSHIFT;
constexpr Scancode S_LALT = SDL_SCANCODE_LALT;
constexpr Scancode S_LGUI = SDL_SCANCODE_LGUI;
constexpr Scancode S_RCTRL = SDL_SCANCODE_RCTRL;
constexpr Scancode S_RSHIFT = SDL_SCANCODE_RSHIFT;
constexpr Scancode S_RALT = SDL_SCANCODE_RALT;
constexpr Scancode S_RGUI = SDL_SCANCODE_RGUI;

constexpr Scancode S_AUDIONEXT = SDL_SCANCODE_AUDIONEXT;
constexpr Scancode S_AUDIOPREV = SDL_SCANCODE_AUDIOPREV;
constexpr Scancode S_AUDIOSTOP = SDL_SCANCODE_AUDIOSTOP;
constexpr Scancode S_AUDIOPLAY = SDL_SCANCODE_AUDIOPLAY;
constexpr Scancode S_AUDIOMUTE = SDL_SCANCODE_AUDIOMUTE;
constexpr Scancode S_MEDIASELECT = SDL_SCANCODE_MEDIASELECT;

constexpr Scancode S_BRIGHTNESSDOWN = SDL_SCANCODE_BRIGHTNESSDOWN;
constexpr Scancode S_BRIGHTNESSUP = SDL_SCANCODE_BRIGHTNESSUP;
constexpr Scancode S_DISPLAYSWITCH = SDL_SCANCODE_DISPLAYSWITCH;

constexpr Scancode S_EJECT = SDL_SCANCODE_EJECT;
constexpr Scancode S_SLEEP = SDL_SCANCODE_SLEEP;

// Event types
constexpr EventType QUIT = SDL_QUIT;
constexpr EventType DISPLAYEVENT = SDL_DISPLAYEVENT;
constexpr EventType WINDOWEVENT = SDL_WINDOWEVENT;
constexpr EventType SYSWMEVENT = SDL_SYSWMEVENT;
constexpr EventType KEYDOWN = SDL_KEYDOWN;
constexpr EventType KEYUP = SDL_KEYUP;
constexpr EventType TEXTEDITING = SDL_TEXTEDITING;
constexpr EventType TEXTINPUT = SDL_TEXTINPUT;
constexpr EventType KEYMAPCHANGED = SDL_KEYMAPCHANGED;
constexpr EventType MOUSEMOTION = SDL_MOUSEMOTION;
constexpr EventType MOUSEBUTTONDOWN = SDL_MOUSEBUTTONDOWN;
constexpr EventType MOUSEBUTTONUP = SDL_MOUSEBUTTONUP;
constexpr EventType MOUSEWHEEL = SDL_MOUSEWHEEL;
constexpr EventType JOYAXISMOTION = SDL_JOYAXISMOTION;
constexpr EventType JOYBALLMOTION = SDL_JOYBALLMOTION;
constexpr EventType JOYHATMOTION = SDL_JOYHATMOTION;
constexpr EventType JOYBUTTONDOWN = SDL_JOYBUTTONDOWN;
constexpr EventType JOYBUTTONUP = SDL_JOYBUTTONUP;
constexpr EventType JOYDEVICEADDED = SDL_JOYDEVICEADDED;
constexpr EventType JOYDEVICEREMOVED = SDL_JOYDEVICEREMOVED;
constexpr EventType CONTROLLERAXISMOTION = SDL_CONTROLLERAXISMOTION;
constexpr EventType CONTROLLERBUTTONDOWN = SDL_CONTROLLERBUTTONDOWN;
constexpr EventType CONTROLLERBUTTONUP = SDL_CONTROLLERBUTTONUP;
constexpr EventType CONTROLLERDEVICEADDED = SDL_CONTROLLERDEVICEADDED;
constexpr EventType CONTROLLERDEVICEREMOVED = SDL_CONTROLLERDEVICEREMOVED;
constexpr EventType CONTROLLERDEVICEREMAPPED = SDL_CONTROLLERDEVICEREMAPPED;
constexpr EventType CLIPBOARDUPDATE = SDL_CLIPBOARDUPDATE;
constexpr EventType DROPFILE = SDL_DROPFILE;
constexpr EventType DROPTEXT = SDL_DROPTEXT;
constexpr EventType DROPBEGIN = SDL_DROPBEGIN;
constexpr EventType DROPCOMPLETE = SDL_DROPCOMPLETE;
constexpr EventType AUDIODEVICEADDED = SDL_AUDIODEVICEADDED;
constexpr EventType AUDIODEVICEREMOVED = SDL_AUDIODEVICEREMOVED;
constexpr EventType USEREVENT = SDL_USEREVENT;

// Keycodes
constexpr Keycode K_BACKSPACE = SDLK_BACKSPACE;
constexpr Keycode K_TAB = SDLK_TAB;
constexpr Keycode K_RETURN = SDLK_RETURN;
constexpr Keycode K_ESC = SDLK_ESCAPE;
constexpr Keycode K_SPACE = SDLK_SPACE;
constexpr Keycode K_EXCLAIM = SDLK_EXCLAIM;
constexpr Keycode K_QUOTEDBL = SDLK_QUOTEDBL;
constexpr Keycode K_HASH = SDLK_HASH;
constexpr Keycode K_DOLLAR = SDLK_DOLLAR;
constexpr Keycode K_PERCENT = SDLK_PERCENT;
constexpr Keycode K_AMPERSAND = SDLK_AMPERSAND;
constexpr Keycode K_QUOTE = SDLK_QUOTE;
constexpr Keycode K_LPAREN = SDLK_LEFTPAREN;
constexpr Keycode K_RPAREN = SDLK_RIGHTPAREN;
constexpr Keycode K_ASTERISK = SDLK_ASTERISK;
constexpr Keycode K_PLUS = SDLK_PLUS;
constexpr Keycode K_COMMA = SDLK_COMMA;
constexpr Keycode K_MINUS = SDLK_MINUS;
constexpr Keycode K_PERIOD = SDLK_PERIOD;
constexpr Keycode K_SLASH = SDLK_SLASH;

constexpr Keycode K_0 = SDLK_0;
constexpr Keycode K_1 = SDLK_1;
constexpr Keycode K_2 = SDLK_2;
constexpr Keycode K_3 = SDLK_3;
constexpr Keycode K_4 = SDLK_4;
constexpr Keycode K_5 = SDLK_5;
constexpr Keycode K_6 = SDLK_6;
constexpr Keycode K_7 = SDLK_7;
constexpr Keycode K_8 = SDLK_8;
constexpr Keycode K_9 = SDLK_9;

constexpr Keycode K_COLON = SDLK_COLON;
constexpr Keycode K_SEMICOLON = SDLK_SEMICOLON;
constexpr Keycode K_LT = SDLK_LESS;
constexpr Keycode K_EQ = SDLK_EQUALS;
constexpr Keycode K_GT = SDLK_GREATER;
constexpr Keycode K_QUESTION = SDLK_QUESTION;
constexpr Keycode K_AT = SDLK_AT;
constexpr Keycode K_LBRACKET = SDLK_LEFTBRACKET;
constexpr Keycode K_BACKSLASH = SDLK_BACKSLASH;
constexpr Keycode K_RBRACKET = SDLK_RIGHTBRACKET;
constexpr Keycode K_CARET = SDLK_CARET;
constexpr Keycode K_UNDERSCORE = SDLK_UNDERSCORE;
constexpr Keycode K_BACKQUOTE = SDLK_BACKQUOTE;

constexpr Keycode K_a = SDLK_a;
constexpr Keycode K_b = SDLK_b;
constexpr Keycode K_c = SDLK_c;
constexpr Keycode K_d = SDLK_d;
constexpr Keycode K_e = SDLK_e;
constexpr Keycode K_f = SDLK_f;
constexpr Keycode K_g = SDLK_g;
constexpr Keycode K_h = SDLK_h;
constexpr Keycode K_i = SDLK_i;
constexpr Keycode K_j = SDLK_j;
constexpr Keycode K_k = SDLK_k;
constexpr Keycode K_l = SDLK_l;
constexpr Keycode K_m = SDLK_m;
constexpr Keycode K_n = SDLK_n;
constexpr Keycode K_o = SDLK_o;
constexpr Keycode K_p = SDLK_p;
constexpr Keycode K_q = SDLK_q;
constexpr Keycode K_r = SDLK_r;
constexpr Keycode K_s = SDLK_s;
constexpr Keycode K_t = SDLK_t;
constexpr Keycode K_u = SDLK_u;
constexpr Keycode K_v = SDLK_v;
constexpr Keycode K_w = SDLK_w;
constexpr Keycode K_x = SDLK_x;
constexpr Keycode K_y = SDLK_y;
constexpr Keycode K_z = SDLK_z;

constexpr Keycode K_DEL = SDLK_DELETE;
constexpr Keycode K_CAPS = SDLK_CAPSLOCK;
constexpr Keycode K_F1 = SDLK_F1;
constexpr Keycode K_F2 = SDLK_F2;
constexpr Keycode K_F3 = SDLK_F3;
constexpr Keycode K_F4 = SDLK_F4;
constexpr Keycode K_F5 = SDLK_F5;
constexpr Keycode K_F6 = SDLK_F6;
constexpr Keycode K_F7 = SDLK_F7;
constexpr Keycode K_F8 = SDLK_F8;
constexpr Keycode K_F9 = SDLK_F9;
constexpr Keycode K_F10 = SDLK_F10;
constexpr Keycode K_F11 = SDLK_F11;
constexpr Keycode K_F12 = SDLK_F12;

constexpr Keycode K_PRTSCR = SDLK_PRINTSCREEN;
constexpr Keycode K_SCRLK = SDLK_SCROLLLOCK;
constexpr Keycode K_PAUSE = SDLK_PAUSE;
constexpr Keycode K_INS = SDLK_INSERT;
constexpr Keycode K_HOME = SDLK_HOME;
constexpr Keycode K_PGUP = SDLK_PAGEUP;
constexpr Keycode K_END = SDLK_END;
constexpr Keycode K_PGDN = SDLK_PAGEDOWN;
constexpr Keycode K_RIGHT = SDLK_RIGHT;
constexpr Keycode K_LEFT = SDLK_LEFT;
constexpr Keycode K_DOWN = SDLK_DOWN;
constexpr Keycode K_UP = SDLK_UP;
constexpr Keycode K_NUMLOCK = SDLK_NUMLOCKCLEAR;

constexpr Keycode K_KP_DIV = SDLK_KP_DIVIDE;
constexpr Keycode K_KP_MULT = SDLK_KP_MULTIPLY;
constexpr Keycode K_KP_MINUS = SDLK_KP_MINUS;
constexpr Keycode K_KP_PLUS = SDLK_KP_PLUS;
constexpr Keycode K_KP_ENTER = SDLK_KP_ENTER;
constexpr Keycode K_KP_1 = SDLK_KP_1;
constexpr Keycode K_KP_2 = SDLK_KP_2;
constexpr Keycode K_KP_3 = SDLK_KP_3;
constexpr Keycode K_KP_4 = SDLK_KP_4;
constexpr Keycode K_KP_5 = SDLK_KP_5;
constexpr Keycode K_KP_6 = SDLK_KP_6;
constexpr Keycode K_KP_7 = SDLK_KP_7;
constexpr Keycode K_KP_8 = SDLK_KP_8;
constexpr Keycode K_KP_9 = SDLK_KP_9;
constexpr Keycode K_KP_0 = SDLK_KP_0;
constexpr Keycode K_KP_PERIOD = SDLK_KP_PERIOD;

constexpr Keycode K_APPLICATION = SDLK_APPLICATION;
constexpr Keycode K_KP_EQ = SDLK_KP_EQUALS;
constexpr Keycode K_EXE = SDLK_EXECUTE;
constexpr Keycode K_HELP = SDLK_HELP;
constexpr Keycode K_MENU = SDLK_MENU;
constexpr Keycode K_SELECT = SDLK_SELECT;
constexpr Keycode K_STOP = SDLK_STOP;
constexpr Keycode K_AGAIN = SDLK_AGAIN;
constexpr Keycode K_UNDO = SDLK_UNDO;
constexpr Keycode K_CUT = SDLK_CUT;
constexpr Keycode K_COPY = SDLK_COPY;
constexpr Keycode K_PASTE = SDLK_PASTE;
constexpr Keycode K_FIND = SDLK_FIND;
constexpr Keycode K_MUTE = SDLK_MUTE;
constexpr Keycode K_VOLUP = SDLK_VOLUMEUP;
constexpr Keycode K_VOLDOWN = SDLK_VOLUMEDOWN;
constexpr Keycode K_CANCEL = SDLK_CANCEL;
constexpr Keycode K_CLEAR = SDLK_CLEAR;
constexpr Keycode K_PRIOR = SDLK_PRIOR;
constexpr Keycode K_SEPERATOR = SDLK_SEPARATOR;
constexpr Keycode K_OUT = SDLK_OUT;
constexpr Keycode K_LCTRL = SDLK_LCTRL;
constexpr Keycode K_LSHIFT = SDLK_LSHIFT;
constexpr Keycode K_LALT = SDLK_LALT;
constexpr Keycode K_LGUI = SDLK_LGUI;
constexpr Keycode K_RCTRL = SDLK_RCTRL;
constexpr Keycode K_RSHIFT = SDLK_RSHIFT;
constexpr Keycode K_RALT = SDLK_RALT;
constexpr Keycode K_RGUI = SDLK_RGUI;

constexpr Keycode K_MODE = SDLK_MODE;
constexpr Keycode K_AUDIONEXT = SDLK_AUDIONEXT;
constexpr Keycode K_AUDIOPREV = SDLK_AUDIOPREV;
constexpr Keycode K_AUDIOSTOP = SDLK_AUDIOSTOP;
constexpr Keycode K_AUDIOPLAY = SDLK_AUDIOPLAY;
constexpr Keycode K_AUDIOMUTE = SDLK_AUDIOMUTE;
constexpr Keycode K_MEDIASELECT = SDLK_MEDIASELECT;

constexpr Keycode K_BRIGHTNESSDOWN = SDLK_BRIGHTNESSDOWN;
constexpr Keycode K_BRIGHTNESSUP = SDLK_BRIGHTNESSUP;
constexpr Keycode K_DISPLAYSWITCH = SDLK_DISPLAYSWITCH;
constexpr Keycode K_EJECT = SDLK_EJECT;
constexpr Keycode K_SLEEP = SDLK_SLEEP;

// Controller buttonsW
constexpr ControllerButton C_SOUTH = SDL_CONTROLLER_BUTTON_A;
constexpr ControllerButton C_EAST = SDL_CONTROLLER_BUTTON_B;
constexpr ControllerButton C_WEST = SDL_CONTROLLER_BUTTON_X;
constexpr ControllerButton C_NORTH = SDL_CONTROLLER_BUTTON_Y;
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
