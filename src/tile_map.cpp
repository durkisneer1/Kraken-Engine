#include "../include/TileMap.hpp"

#include <iostream>


namespace kn {
    TileMap::TileMap(RenderWindow& window, TextureCache& textureCache, const std::string &tmxPath)
    : window(window), textureCache(textureCache) {
        if (!map.load(tmxPath)) {
            std::cerr << "Failed to load and parse tile map: " << tmxPath << std::endl;
            return;
        }

        tmx::Tileset tileset = map.getTilesets()[0];
        textureCache.load("tileset", tileset.getImagePath());

        for (const auto& tile : tileset.getTiles()) {
            std::cout << tile.ID << " " << tile.imagePosition.x << " " << tile.imagePosition.y << std::endl;
        }
    }
}
