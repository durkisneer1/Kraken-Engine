#pragma once

#include <memory>

#include "Rect.hpp"


namespace kn {
    struct Tile {
        std::string name;
        kn::Rect rect;
    };
}
