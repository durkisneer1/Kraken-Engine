#include <iostream>

#include "SDL.h"

#include "../include/RenderWindow.hpp"


namespace kn {

static int scale = 1;
static bool instanceCreated = false;
static std::string title = "Kraken";
static bool fullscreen = false;


RenderWindow& RenderWindow::getInstance()
{
    static RenderWindow __instance;
    instanceCreated = true;

    return __instance;
}

RenderWindow::RenderWindow()
{
    if (SDL_Init(SDL_INIT_VIDEO)) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        exit(3);
    }
    if (!IMG_Init(IMG_INIT_PNG)) {
        std::cerr << "IMG_Init Error: " << IMG_GetError() << std::endl;
        SDL_Quit();
        exit(3);
    }
    if (TTF_Init() < 0) {
        std::cerr << "TTF_Init Error: " << TTF_GetError() << std::endl;
        IMG_Quit();
        SDL_Quit();
        exit(3);
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "Mix_OpenAudio Error: " << Mix_GetError() << std::endl;
        TTF_Quit();
        IMG_Quit();
        SDL_Quit();
    }

    this->m_window = SDL_CreateWindow(
        title.c_str(),
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        (int)SCREEN_SIZE.x * scale, (int)SCREEN_SIZE.y * scale,
        fullscreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN
    );

    if (!m_window) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(3);
    }

    m_renderer = SDL_CreateRenderer(
        m_window, -1, SDL_RENDERER_ACCELERATED
    );
    
    if (!m_renderer) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        exit(3);
    }

    if (scale > 1) {
        SDL_RenderSetLogicalSize(m_renderer, SCREEN_SIZE.x, SCREEN_SIZE.y);
        SDL_RenderSetIntegerScale(m_renderer, SDL_TRUE);
    }
}

RenderWindow::~RenderWindow() {
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    Mix_CloseAudio();
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}

const std::vector<SDL_Event>& RenderWindow::getEvents() {
    m_events.clear();
    while (SDL_PollEvent(&m_event)) {
        m_events.push_back(m_event);
    }
    return m_events;
}

void RenderWindow::cls(SDL_Color color) {
    SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a);
    SDL_RenderClear(m_renderer);
}

void RenderWindow::flip() {
    SDL_RenderPresent(m_renderer);
}

void RenderWindow::blit(const std::shared_ptr<Texture>& texture, Rect crop, Rect rect) {
    if (crop.getSize() == math::Vec2::ZERO()) {
        SDL_RenderCopyF(m_renderer, texture->getSDLTexture(), nullptr, &rect);
        return;
    }
    SDL_Rect src;
    src.x = crop.x;
    src.y = crop.y;
    src.w = crop.w;
    src.h = crop.h;
    SDL_RenderCopyF(m_renderer, texture->getSDLTexture(), &src, &rect);
}

void RenderWindow::blit(const std::shared_ptr<Texture>& texture, const math::Vec2& position) {
    SDL_FRect rect = {
        position.x, position.y,
        texture->getSize().x, texture->getSize().y
    };
    SDL_RenderCopyF(m_renderer, texture->getSDLTexture(), nullptr, &rect);
}

void RenderWindow::blitEx(const std::shared_ptr<Texture>& texture, Rect crop, Rect rect, double angle, bool flipX, bool flipY) {
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    if (flipX) {
        flip = (SDL_RendererFlip)(flip | SDL_FLIP_HORIZONTAL);
    }
    if (flipY) {
        flip = (SDL_RendererFlip)(flip | SDL_FLIP_VERTICAL);
    }
    if (crop.getSize() == math::Vec2::ZERO()) {
        SDL_RenderCopyExF(m_renderer, texture->getSDLTexture(), nullptr, &rect, angle, nullptr, flip);
        return;
    }
    SDL_Rect src;
    src.x = crop.x;
    src.y = crop.y;
    src.w = crop.w;
    src.h = crop.h;
    SDL_RenderCopyExF(m_renderer, texture->getSDLTexture(), &src, &rect, angle, nullptr, flip);
}

void RenderWindow::blitEx(const std::shared_ptr<Texture>& texture, const math::Vec2& position, double angle, bool flipX, bool flipY) {
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    if (flipX) {
        flip = (SDL_RendererFlip)(flip | SDL_FLIP_HORIZONTAL);
    }
    if (flipY) {
        flip = (SDL_RendererFlip)(flip | SDL_FLIP_VERTICAL);
    }
    SDL_FRect rect = {
        position.x, position.y,
        texture->getSize().x, texture->getSize().y
    };
    SDL_RenderCopyExF(m_renderer, texture->getSDLTexture(), nullptr, &rect, angle, nullptr, flip);
}

const std::string RenderWindow::getTitle() const
{
    if (m_window != nullptr)
	{
		return SDL_GetWindowTitle(m_window);
	}
	return title;
}

bool RenderWindow::getFullscreen() const
{
    return (SDL_GetWindowFlags(m_window) & SDL_WINDOW_FULLSCREEN) > 0;
}

int RenderWindow::getScale()
{
    return scale;
}

void RenderWindow::setTitle(const std::string& newTitle)
{
	title = newTitle;

	if (m_window != nullptr)
	{
		SDL_SetWindowTitle(m_window, newTitle.c_str());
	}
}

void RenderWindow::setFullscreen(bool fullscreenValue)
{
	fullscreen = fullscreenValue;

	if (m_window != nullptr)
	{
		SDL_SetWindowFullscreen(m_window, fullscreen);
	}
}

bool RenderWindow::setScale(int newScale)
{
    if (instanceCreated)
    {
        std::cout << "Cannot set scale after creating the window\n";
        return false;
    }

    scale = std::min(std::max(newScale, 1), 32);

	return true;
}
}