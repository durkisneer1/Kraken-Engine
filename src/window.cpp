#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include "ErrorLogger.hpp"
#include "Math.hpp"
#include "Music.hpp"
#include "Texture.hpp"
#include "Window.hpp"
#include "_globals.hpp"

namespace kn::window
{
static SDL_Renderer* _renderer;
static SDL_Window* _window;
static bool _isOpen;

bool init(const math::Vec2& resolution, const std::string& title, const int scale)
{
    if (_renderer)
    {
        WARN("Cannot initialize renderer more than once")
        return false;
    }

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER) < 0)
    {
        FATAL("SDL_Init Error: " + std::string(SDL_GetError()))
        return false;
    }

    if (!IMG_Init(IMG_INIT_PNG))
    {
        FATAL("IMG_Init Error: " + std::string(IMG_GetError()))
        SDL_Quit();
        return false;
    }

    if (TTF_Init())
    {
        FATAL("TTF_Init Error: " + std::string(TTF_GetError()))
        IMG_Quit();
        SDL_Quit();
        return false;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048))
    {
        FATAL("Mix_OpenAudio Error: " + std::string(Mix_GetError()))
        TTF_Quit();
        IMG_Quit();
        SDL_Quit();
        return false;
    }

    const int resolutionWidth = static_cast<int>(resolution.x);
    const int resolutionHeight = static_cast<int>(resolution.y);
    _window = SDL_CreateWindow("Kraken Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                               resolutionWidth * scale, resolutionHeight * scale, SDL_WINDOW_SHOWN);
    if (!_window)
    {
        FATAL("SDL_CreateWindow Error: " + std::string(SDL_GetError()))
        return false;
    }

    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    if (!_renderer)
    {
        FATAL("SDL_CreateRenderer Error: " + std::string(SDL_GetError()))
        return false;
    }

    if (scale > 1)
        SDL_RenderSetLogicalSize(_renderer, resolutionWidth, resolutionHeight);

    setTitle(title);
    // setIcon("../example/assets/kraken_engine_window_icon.png");
    SDL_SetRenderDrawBlendMode(_renderer, SDL_BLENDMODE_BLEND);

    _isOpen = true;

    return true;
}

bool isOpen() { return _isOpen; }

void close() { _isOpen = false; }

void quit()
{
    music::unload();

    if (_renderer)
        SDL_DestroyRenderer(_renderer);
    if (_window)
        SDL_DestroyWindow(_window);
    if (_controller)
        SDL_GameControllerClose(_controller);

    Mix_CloseAudio();
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}

int pollEvent(Event& event)
{
    if (!_window)
        WARN("Cannot get events before creating the window")

    const int pending = SDL_PollEvent(&event);

    if (pending)
    {
        switch (event.type)
        {
        case QUIT:
            close();
            break;
        case CONTROLLERDEVICEADDED:
        {
            if (!_controller)
                _controller = SDL_GameControllerOpen(event.cdevice.which);
            break;
        }
        case CONTROLLERDEVICEREMOVED:
            if (_controller &&
                event.cdevice.which ==
                    SDL_JoystickInstanceID(SDL_GameControllerGetJoystick(_controller)))
            {
                SDL_GameControllerClose(_controller);
                _controller = nullptr;
            }
            break;
        case KEYDOWN:
            if (event.key.keysym.sym == SDLK_F11)
                setFullscreen(!getFullscreen());
            break;
        default:
            break;
        }
    }

    return pending;
}

void clear(const Color color)
{
    if (!_renderer)
        WARN("Cannot clear screen before creating the window")

    SDL_SetRenderDrawColor(_renderer, color.r, color.g, color.b, color.a);
    SDL_RenderClear(_renderer);
}

void flip()
{
    if (!_renderer)
        WARN("Cannot flip screen before creating the window")

    SDL_RenderPresent(_renderer);
}

void blit(const Texture& texture, const Rect& dstRect, const Rect& srcRect)
{
    if (!_renderer)
    {
        WARN("Cannot blit before creating the window")
        return;
    }

    if (dstRect.bottomRight() < camera || dstRect.topLeft() > getSize() + camera)
        return;

    SDL_RendererFlip flipAxis = SDL_FLIP_NONE;
    if (texture.flip.x)
        flipAxis = static_cast<SDL_RendererFlip>(flipAxis | SDL_FLIP_HORIZONTAL);
    if (texture.flip.y)
        flipAxis = static_cast<SDL_RendererFlip>(flipAxis | SDL_FLIP_VERTICAL);

    Rect offsetRect = dstRect;
    offsetRect.topLeft(offsetRect.topLeft() - camera);

    if (srcRect.size() == math::Vec2())
    {
        SDL_RenderCopyExF(_renderer, texture.getSDLTexture(), nullptr, &offsetRect, texture.angle,
                          nullptr, flipAxis);
        return;
    }

    SDL_Rect src;
    SDL_Rect* pSrc = nullptr;
    if (srcRect.size() != math::Vec2())
    {
        src = srcRect;
        pSrc = &src;
    }

    SDL_RenderCopyExF(_renderer, texture.getSDLTexture(), pSrc, &offsetRect, texture.angle, nullptr,
                      flipAxis);
}

void blit(const Texture& texture, const math::Vec2& position, const Anchor anchor)
{
    if (!_renderer)
    {
        WARN("Cannot blit before creating the window");
        return;
    }

    if (texture.getSize() + position < camera || position > getSize() + camera)
        return;

    SDL_RendererFlip flipAxis = SDL_FLIP_NONE;
    if (texture.flip.x)
        flipAxis = static_cast<SDL_RendererFlip>(flipAxis | SDL_FLIP_HORIZONTAL);
    if (texture.flip.y)
        flipAxis = static_cast<SDL_RendererFlip>(flipAxis | SDL_FLIP_VERTICAL);

    const math::Vec2 screenPos = position - camera;
    Rect rect = texture.getRect();
    switch (anchor)
    {
    case TOP_LEFT:
        rect.topLeft(screenPos);
        break;
    case TOP_MID:
        rect.topMid(screenPos);
        break;
    case TOP_RIGHT:
        rect.topRight(screenPos);
        break;
    case LEFT_MID:
        rect.leftMid(screenPos);
        break;
    case CENTER:
        rect.center(screenPos);
        break;
    case RIGHT_MID:
        rect.rightMid(screenPos);
        break;
    case BOTTOM_LEFT:
        rect.bottomLeft(screenPos);
        break;
    case BOTTOM_MID:
        rect.bottomMid(screenPos);
        break;
    case BOTTOM_RIGHT:
        rect.bottomRight(screenPos);
        break;
    }

    SDL_RenderCopyExF(_renderer, texture.getSDLTexture(), nullptr, &rect, texture.angle, nullptr,
                      flipAxis);
}

SDL_Renderer* getRenderer()
{
    if (!_renderer)
        WARN("Cannot get renderer before creating the window")

    return _renderer;
}

int getScale()
{
    if (!_window)
        WARN("Cannot get scale before creating the window");

    float scale;
    SDL_RenderGetScale(_renderer, &scale, nullptr);

    return static_cast<int>(scale);
}

void setTitle(const std::string& newTitle)
{
    if (!_window)
        WARN("Cannot set title before creating the window")

    if (newTitle.empty())
    {
        WARN("Cannot set title to empty string")
        return;
    }

    if (newTitle.size() > 255)
    {
        WARN("Cannot set title to string longer than 255 characters")
        return;
    }

    SDL_SetWindowTitle(_window, newTitle.c_str());
}

std::string getTitle()
{
    if (!_window)
        WARN("Cannot get title before creating the window")

    return {SDL_GetWindowTitle(_window)};
}

void setFullscreen(const bool fullscreen)
{
    if (!_window)
    {
        WARN("Cannot set fullscreen before creating the window")
        return;
    }

    SDL_SetWindowFullscreen(_window, fullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);
}

bool getFullscreen()
{
    if (!_window)
    {
        WARN("Cannot get fullscreen before creating the window")
        return false;
    }

    return SDL_GetWindowFlags(_window) & SDL_WINDOW_FULLSCREEN_DESKTOP;
}

math::Vec2 getSize()
{
    if (!_window)
        WARN("Cannot get size before creating the window")

    int w, h;
    SDL_RenderGetLogicalSize(_renderer, &w, &h);
    if (!w || !h)
        SDL_GetWindowSize(_window, &w, &h);

    return {w, h};
}

void setIcon(const std::string& path)
{
    if (!_window)
        WARN("Cannot set icon before creating the window")

    SDL_Surface* icon = IMG_Load(path.c_str());
    if (!icon)
    {
        WARN("IMG_Load Error: " + std::string(IMG_GetError()))
        return;
    }

    SDL_SetWindowIcon(_window, icon);
    SDL_FreeSurface(icon);
}

} // namespace kn::window
