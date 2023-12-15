#include "../include/TileMap.hpp"

#include <iostream>
#include <fstream>


namespace kn {
    TileMap::TileMap(const std::string &filePath, kn::math::Vector2 tileSize) {
        this->tileSize = tileSize;

        std::ifstream file(filePath);
        if (!file.is_open()) {
            std::cerr << "Failed to open file: " << filePath << std::endl;
            return;
        }
        file.close();
    }
}
