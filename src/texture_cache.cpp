#include "../include/TextureCache.hpp"
#include <iostream>


namespace kn {
    void TextureCache::load(const std::string &name, const std::string &path) {
        SDL_Texture* texture = IMG_LoadTexture(window.getRenderer(), path.c_str());
        if (!texture) {
            std::cerr << "Failed to create texture from: " << path << std::endl;
            return;
        } else {
            textures[name] = std::make_shared<kn::Texture>(texture);
        }
    }

    void TextureCache::create(const std::string &name, kn::math::Vector2 size, SDL_Color color) {
        SDL_Surface* surface = SDL_CreateRGBSurface(0, size.x, size.y, 32, 0, 0, 0, 0);
        if (!surface) {
            std::cerr << "Failed to create surface: " << name << std::endl;
            return;
        }

        SDL_FillRect(surface, nullptr, SDL_MapRGB(surface->format, color.r, color.g, color.b));

        SDL_Texture* texture = SDL_CreateTextureFromSurface(window.getRenderer(), surface);
        if (!texture) {
            std::cerr << "Failed to create texture from surface: " << name << std::endl;
            return;
        }

        textures[name] = std::make_shared<kn::Texture>(texture);
        SDL_FreeSurface(surface);
    }

    void TextureCache::move(const std::string &name, const kn::Texture& texture) {
        textures[name] = std::make_shared<kn::Texture>(std::move(texture));
    }

    void TextureCache::unload(const std::string &name) {
        textures.erase(name);
    }

    void TextureCache::unloadAll() {
        textures.clear();
    }

    std::shared_ptr<kn::Texture> TextureCache::getTexture(const std::string &name) {
        return textures[name];
    }
}