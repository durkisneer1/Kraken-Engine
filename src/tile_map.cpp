#include <algorithm>

#include "tmxlite/TileLayer.hpp"

#include "ErrorLogger.hpp"
#include "TileMap.hpp"

namespace kn
{

TileMap::TileMap(const std::string& tmxPath)
{
    if (!map.load(tmxPath))
    {
        WARN("Failed to load and parse tile map: " + tmxPath);
        return;
    }

    int mapWidth = map.getTileCount().x;
    const auto& tileSize = map.getTileSize();

    for (const auto& set : map.getTilesets())
    {
        auto tex = cache::load("tileset", set.getImagePath());
        tileSetMap[set.getFirstGID()] = tex; // Binding map texture to its GID key.
        cache::unload("tileset");
    }

    for (const auto& layer : map.getLayers())
    {
        if (layer->getType() == tmx::Layer::Type::Tile)
        {
            const auto& layerTiles = layer->getLayerAs<tmx::TileLayer>().getTiles();

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

                int regionX = (currentGID % (tileSetWidth / (int)tileSize.x)) * (int)tileSize.x;
                int regionY = (currentGID / (tileSetWidth / (int)tileSize.x)) * (int)tileSize.y;

                int xPos = (i % mapWidth) * (int)tileSize.x;
                int yPos = (i / mapWidth) * (int)tileSize.y;

                tileVec.emplace_back(Tile{tile,
                                          {regionX, regionY, (int)tileSize.x, (int)tileSize.y},
                                          {xPos, yPos, (int)tileSize.x, (int)tileSize.y}});
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
