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

            for (uint64_t i = 0; i < layerTiles.size(); ++i)
            {
                int currentGID = layerTiles[i].ID;
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
                auto tile = tileSetMap[tileSetGID];
                int tileSetWidth = tile->getSize().x;

                int regionX = (currentGID % (tileSetWidth / tileWidth)) * tileWidth;
                int regionY = (currentGID / (tileSetWidth / tileWidth)) * tileHeight;

                int xPos = (i % mapWidth) * tileWidth;
                int yPos = (i / mapWidth) * tileHeight;

                tileVec.emplace_back(Tile{tile,
                                          {regionX, regionY, tileWidth, tileHeight},
                                          {xPos, yPos, tileWidth, tileHeight}});
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
