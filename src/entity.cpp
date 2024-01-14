#include "Entity.hpp"

namespace kn
{

Entity::Entity(std::shared_ptr<Texture> texture)
    : crop({0, 0, 0, 0}), rect(texture->getRect()), texture(texture)
{
    crop.w = rect.w;
    crop.h = rect.h;
}

std::shared_ptr<Texture> Entity::getTexture() const { return texture; }

} // namespace kn
