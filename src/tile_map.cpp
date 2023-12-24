#include "../include/TileMap.hpp"

#include <iostream>

#include "tmxlite/Map.hpp"


namespace kn {

TileMap::TileMap(RenderWindow& window, TextureCache& textureCache, const std::string &tmxPath)
: window(window) {
    if (!m_map.load(tmxPath)) {
        std::cerr << "Failed to load and parse tile map: " << tmxPath << std::endl;
        return;
    }

    tmx::Tileset tileSet = m_map.getTilesets()[0];
    mapTexture = textureCache.load("tileset", tileSet.getImagePath());
    textureCache.unload("tileset");
}

}
