#include <algorithm>

#include "tmxlite/TileLayer.hpp"

#include "ErrorLogger.hpp"
#include "TileMap.hpp"

namespace kn
{

TileMap::TileMap(TextureCache& textureCache, const std::string& tmxPath)
{
    if (!map.load(tmxPath))
    {
        WARN("Failed to load and parse tile map: " + tmxPath);
        return;
    }

    int mapWidth = map.getTileCount().x;
    int mapHeight = map.getTileCount().y;
    int tileWidth = map.getTileSize().x;
    int tileHeight = map.getTileSize().y;

    const auto& tileSets = map.getTilesets();
    for (const auto& set : tileSets)
    {
        auto tex = textureCache.load("tileset", set.getImagePath());
        tileSetMap[set.getFirstGID()] = tex; // Binding map texture to its GID key.
        textureCache.unload("tileset");
    }

    const auto& layers = map.getLayers();
    for (const auto& layer : layers)
    {
        if (layer->getType() == tmx::Layer::Type::Tile)
        {
            const auto& tileLayer = layer->getLayerAs<tmx::TileLayer>();
            const auto& layerTiles = tileLayer.getTiles();

            for (int y = 0; y < mapHeight; ++y)
            {
                for (int x = 0; x < mapWidth; ++x)
                {
                    int currentGID = layerTiles[y * mapWidth + x].ID;
                    if (currentGID == 0)
                        continue;

                    int tileSetGID = -1;
                    auto it = std::find_if(tileSetMap.rbegin(), tileSetMap.rend(),
                                           [currentGID](const auto& tileSet)
                                           { return currentGID >= tileSet.first; });
                    if (it != tileSetMap.rend())
                        tileSetGID = it->first;
                    if (tileSetGID == -1)
                        continue;

                    currentGID -= tileSetGID;
                    int tileSetWidth = tileSetMap[tileSetGID]->getSize().x;

                    int regionX = (currentGID % (tileSetWidth / tileWidth)) * tileWidth;
                    int regionY = (currentGID / (tileSetWidth / tileWidth)) * tileHeight;

                    int xPos = (x * tileWidth);
                    int yPos = (y * tileHeight);

                    tileVec.emplace_back(Tile{tileSetMap[tileSetGID],
                                              {regionX, regionY, tileWidth, tileHeight},
                                              {xPos, yPos, tileWidth, tileHeight}});
                }
            }
        }
    }
}

void TileMap::draw()
{
    for (const auto& tile : tileVec)
        window.blit(tile.texture, tile.crop, tile.rect);
}

} // namespace kn
