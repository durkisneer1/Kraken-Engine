#include <iostream>

#include "../include/Entity.hpp"

namespace kn
{

Entity::Entity(std::shared_ptr<Texture> texture)
    : texture(texture), rect(texture->getRect())
{
    crop.w = rect.w;
    crop.h = rect.h;
}

std::shared_ptr<Texture> Entity::getTexture() const
{
    return texture;
}

}
