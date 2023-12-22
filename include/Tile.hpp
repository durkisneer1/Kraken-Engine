#pragma once

#include <memory>

#include "Rect.hpp"


namespace kn {
    struct Tile {
        std::string name;
        Rect rect;
    };
}
