#include "../include/TextureCache.hpp"
#include <iostream>


namespace dk {
    void TextureCache::load(const char* name, const char* path) {
        SDL_Texture* texture = IMG_LoadTexture(window.getRenderer(), path);
        if (!texture) {
            std::cout << "Failed to create texture from: " << path << std::endl;
            return;
        } else {
            textures[name] = std::make_shared<dk::Texture>(texture);
        }
    }

    void TextureCache::create(const char* name, dk::math::Vector2 size, SDL_Color color) {
        SDL_Surface* surface = SDL_CreateRGBSurface(0, size.x, size.y, 32, 0, 0, 0, 0);
        if (!surface) {
            std::cout << "Failed to create surface: " << name << std::endl;
            return;
        }

        SDL_FillRect(surface, nullptr, SDL_MapRGB(surface->format, color.r, color.g, color.b));

        SDL_Texture* texture = SDL_CreateTextureFromSurface(window.getRenderer(), surface);
        if (!texture) {
            std::cout << "Failed to create texture from surface: " << name << std::endl;
            return;
        }

        textures[name] = std::make_shared<dk::Texture>(texture);
        SDL_FreeSurface(surface);
    }

    void TextureCache::move(const char* name, const dk::Texture& texture) {
        textures[name] = std::make_shared<dk::Texture>(std::move(texture));
    }

    void TextureCache::unload(const char* name) {
        SDL_DestroyTexture(textures[name]->getSDLTexture());
        textures.erase(name);
    }

    void TextureCache::unloadAll() {
        for (auto& texture : textures) {
            SDL_DestroyTexture(texture.second->getSDLTexture());
        }
        textures.clear();
    }

    std::shared_ptr<dk::Texture> TextureCache::get(const char* name) {
        return textures[name];
    }
}