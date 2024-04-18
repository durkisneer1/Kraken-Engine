#include "Cache.hpp"
#include "ErrorLogger.hpp"
#include "Math.hpp"
#include "Window.hpp"

namespace kn
{
namespace cache
{
static std::map<std::string, std::shared_ptr<Texture>> textures;

std::shared_ptr<Texture> load(const std::string& name, const std::string& path)
{
    SDL_Texture* texture = IMG_LoadTexture(window::getRenderer(), path.c_str());
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

std::shared_ptr<Texture> create(const std::string& name, const math::Vec2& size, Color color)
{
    SDL_Surface* surface = SDL_CreateRGBSurface(0, (int)size.x, (int)size.y, 32, 0, 0, 0, 0);
    if (!surface)
    {
        WARN("Failed to create surface: " + name);
        return nullptr;
    }

    SDL_FillRect(surface, nullptr, SDL_MapRGB(surface->format, color.r, color.g, color.b));

    SDL_Texture* texture = SDL_CreateTextureFromSurface(window::getRenderer(), surface);
    if (!texture)
    {
        WARN("Failed to create texture from surface: " + name);
        return nullptr;
    }

    textures[name] = std::make_shared<Texture>(texture);
    SDL_FreeSurface(surface);

    return textures[name];
}

std::shared_ptr<Texture> move(const std::string& name, std::shared_ptr<Texture> texture)
{
    textures[name] = texture;

    return textures[name];
}

void unload(const std::string& name) { textures.erase(name); }

void unloadAll() { textures.clear(); }

std::shared_ptr<Texture> getTexture(const std::string& name)
{
    auto it = textures.find(name);
    if (it != textures.end())
        return it->second;

    return nullptr;
}

const std::map<std::string, std::shared_ptr<Texture>>& getCache() { return textures; }
} // namespace cache
} // namespace kn
