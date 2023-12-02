#pragma once

#include <map>
#include <memory>
#include "RenderWindow.hpp"
#include "Texture.hpp"
#include "Math.hpp"


namespace dk {
    class TextureCache {
    public:
        TextureCache(dk::RenderWindow& window) : window(window) {}
        ~TextureCache() { unloadAll();};

        void load(const char* name, const char* path);
        void create(const char* name, dk::math::Vector2 size, SDL_Color color);
        void move(const char* name, const dk::Texture& texture);
        void unload(const char* name);
        void unloadAll();

        std::shared_ptr<dk::Texture> get(const char* name);

    private:
        dk::RenderWindow& window;
        std::map<const char*, std::shared_ptr<dk::Texture>> textures;
    };
}