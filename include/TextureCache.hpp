#pragma once

#include <map>
#include <memory>

#include "RenderWindow.hpp"
#include "Texture.hpp"
#include "Math.hpp"


namespace kn {
    /// @brief A class to cache textures.
    /// @note This class is a mandatory singleton.
    class TextureCache final {
    public:
        /// @brief Instantiate the texture cache.
        /// @param window The renderer context.
        explicit TextureCache(RenderWindow& window) : window(window) {}

        /// @brief Unload the texture cache.
        ~TextureCache() { unloadAll(); };

        /// @brief Load a texture file.
        /// @param name The name of the texture.
        /// @param path The path to the texture file.
        /// @return The texture pointer.
        [[maybe_unused]]
        std::shared_ptr<Texture> load(const std::string &name, const std::string &path);

        /// @brief Create a solid texture.
        /// @param name The name of the texture.
        /// @param size The size of the texture.
        /// @param color The color of the texture.
        /// @return The texture pointer.
        [[maybe_unused]]
        std::shared_ptr<Texture> create(const std::string &name, math::Vec2 size, SDL_Color color);

        /// @brief Move an existing texture.
        /// @param name The name of the texture.
        /// @param texture The texture to move.
        /// @note This function is recommended for loading fonts.
        /// @return The texture pointer.
        [[maybe_unused]]
        std::shared_ptr<Texture> move(const std::string &name, std::shared_ptr<Texture> texture);

        /// @brief Get the const reference to the texture cache.
        /// @return The texture cache.
        const std::map<std::string, std::shared_ptr<Texture>>& getCache() const;

        /// @brief Unload a texture from cache.
        /// @param name The name of the texture.
        void unload(const std::string &name);

        /// @brief Unload all textures from cache.
        void unloadAll();

        /// @brief Get a texture pointer from cache.
        /// @param name The name of the texture.
        /// @return The texture pointer.
        std::shared_ptr<Texture> getTexture(const std::string &name) const;

    private:
        RenderWindow& window;
        std::map<std::string, std::shared_ptr<Texture>> textures;
    };
}
