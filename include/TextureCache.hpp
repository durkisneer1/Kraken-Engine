#pragma once

#include <map>
#include <memory>
#include "RenderWindow.hpp"
#include "Texture.hpp"
#include "Math.hpp"


namespace kn {
    class TextureCache {
    public:
        TextureCache(kn::RenderWindow& window) : window(window) {}
        ~TextureCache() { unloadAll();};

        void load(const char* name, const char* path);
        void create(const char* name, kn::math::Vector2 size, SDL_Color color);
        void move(const char* name, const kn::Texture& texture);
        void unload(const char* name);
        void unloadAll();

        std::shared_ptr<kn::Texture> get(const char* name);

    private:
        kn::RenderWindow& window;
        std::map<const char*, std::shared_ptr<kn::Texture>> textures;
    };
}