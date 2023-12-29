#include <iostream>
#include <algorithm>

#include "../include/tmxlite/TileLayer.hpp"

#include "../include/TileMap.hpp"


namespace kn {

TileMap::TileMap(RenderWindow& window, TextureCache& textureCache, const std::string &tmxPath)
: window(window) {
    if (!m_map.load(tmxPath)) {
        std::cerr << "Failed to load and parse tile map: " << tmxPath << std::endl;
        return;
    }

    int mapWidth = m_map.getTileCount().x;
    int mapHeight = m_map.getTileCount().y;
    int tileWidth = m_map.getTileSize().x;
    int tileHeight = m_map.getTileSize().y;

    auto& tileSets = m_map.getTilesets();
    for (const auto& set : tileSets) {
        auto tex = textureCache.load("tileset", set.getImagePath());
        tileSetMap[set.getFirstGID()] = tex;  // Binding map texture to its GID key.
        textureCache.unload("tileset");
    }

    auto& layers = m_map.getLayers();
    for (const auto& layer : layers) {
        if (layer->getType() == tmx::Layer::Type::Object) {
            const auto& objectLayer = layer->getLayerAs<tmx::ObjectGroup>();
            const auto& layerObjects = objectLayer.getObjects();

            for (const auto& obj : layerObjects) {
                int currentGID = obj.getTileID();

                int tileSetGID = -1;
                for (const auto& tileSet : tileSetMap)
                    if (currentGID >= tileSet.first) {
                        tileSetGID = tileSet.first;
                        break;
                    }
                if (tileSetGID == -1) continue;

                currentGID -= tileSetGID;
                int tileSetWidth = tileSetMap[tileSetGID]->getSize().x;
                
                int regionX = (currentGID % (tileSetWidth / tileWidth)) * tileWidth;
                int regionY = (currentGID / (tileSetWidth / tileWidth)) * tileHeight;

                objectVec.emplace_back(
                    Object {
                        tileSetMap[tileSetGID],
                        { regionX, regionY, tileWidth, tileHeight },
                        { obj.getPosition().x, obj.getPosition().y - obj.getAABB().height, (float)tileWidth, (float)tileHeight },
                        obj.getName(),
                        obj.getType()
                    }
                );
            }
        }

        if (layer->getType() == tmx::Layer::Type::Tile) {
            const auto& tileLayer = layer->getLayerAs<tmx::TileLayer>();
            const auto& layerTiles = tileLayer.getTiles();

            for (int y = 0; y < mapHeight; ++y) {
                for (int x = 0; x < mapWidth; ++x) {
                    int currentGID = layerTiles[y * mapWidth + x].ID;
                    if (currentGID == 0) continue;

                    int tileSetGID = -1;
                    for (const auto& tileSet : tileSetMap)
                        if (currentGID >= tileSet.first) {
                            tileSetGID = tileSet.first;
                            break;
                        }
                    if (tileSetGID == -1) continue;

                    currentGID -= tileSetGID;
                    int tileSetWidth = tileSetMap[tileSetGID]->getSize().x;

                    int regionX = (currentGID % (tileSetWidth / tileWidth)) * tileWidth;
                    int regionY = (currentGID / (tileSetWidth / tileWidth)) * tileHeight;

                    int xPos = (x * tileWidth);
                    int yPos = (y * tileHeight);

                    tileVec.emplace_back(
                        Tile {
                            tileSetMap[tileSetGID],
                            { regionX, regionY, tileWidth, tileHeight },
                            { xPos, yPos, tileWidth, tileHeight }
                        }
                    );
                }
            }
        }
    }
}

void TileMap::drawTiles() {
    for (const auto& tile : tileVec) {
        window.blit(tile.texture, tile.crop, tile.rect);
    }
}

void TileMap::drawObjects() {
    for (const auto& object : objectVec) {
        window.blit(object.texture, object.crop, object.rect);
    }
}

void TileMap::drawAll() {
    drawTiles();
    drawObjects();
}

const std::vector<Object>& TileMap::getObjects() const {
    return objectVec;
}

}
