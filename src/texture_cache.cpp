#include <iostream>

#include "ErrorLogger.hpp"
#include "TextureCache.hpp"
#include "RenderWindow.hpp"

namespace kn
{

std::shared_ptr<Texture> TextureCache::load(const std::string &name, const std::string &path)
{
    SDL_Texture *texture = IMG_LoadTexture(RenderWindow::getInstance().getRenderer(), path.c_str());
    if (!texture)
    {
        WARN("Failed to create texture from: " + path);
        return nullptr;
    }
    else
    {
        textures[name] = std::make_shared<Texture>(texture);
    }

    return textures[name];
}

std::shared_ptr<Texture> TextureCache::create(const std::string &name, const math::Vec2 &size, SDL_Color color)
{
    SDL_Surface *surface = SDL_CreateRGBSurface(0, size.x, size.y, 32, 0, 0, 0, 0);
    if (!surface)
    {
        WARN("Failed to create surface: " + name);
        return nullptr;
    }

    SDL_FillRect(surface, nullptr, SDL_MapRGB(surface->format, color.r, color.g, color.b));

    SDL_Texture *texture = SDL_CreateTextureFromSurface(RenderWindow::getInstance().getRenderer(), surface);
    if (!texture)
    {
        WARN("Failed to create texture from surface: " + name);
        return nullptr;
    }

    textures[name] = std::make_shared<Texture>(texture);
    SDL_FreeSurface(surface);

    return textures[name];
}

std::shared_ptr<Texture> TextureCache::move(const std::string &name, std::shared_ptr<Texture> texture)
{
    textures[name] = texture;

    return textures[name];
}

void TextureCache::unload(const std::string &name)
{
    textures.erase(name);
}

void TextureCache::unloadAll()
{
    textures.clear();
}

std::shared_ptr<Texture> TextureCache::getTexture(const std::string &name) const
{
    auto it = textures.find(name);
    if (it != textures.end())
    {
        return it->second;
    }
    
    return nullptr;
}

const std::map<std::string, std::shared_ptr<Texture>> &TextureCache::getCache() const
{
    return textures;
}

}