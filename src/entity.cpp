#include <iostream>

#include "Entity.hpp"

namespace kn
{

Entity::Entity(std::shared_ptr<Texture> texture)
    : rect(texture->getRect()), texture(texture)
{
    crop.w = rect.w;
    crop.h = rect.h;
}

std::shared_ptr<Texture> Entity::getTexture() const
{
    return texture;
}

}
