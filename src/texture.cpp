#include <iostream>

#include "../include/Texture.hpp"

namespace kn
{

Texture::Texture(SDL_Texture *texture)
	: texture(texture)
{
	query();
}

void Texture::query()
{
	int w, h;
	SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);
	this->rect = {0, 0, w, h};
}

math::Vec2 Texture::getSize() const
{
	return {rect.w, rect.h};
}

Rect Texture::getRect() const
{
	return rect;
}

SDL_Texture *Texture::getSDLTexture() const
{
	return texture;
}

void Texture::setSize(const math::Vec2 &size)
{
	rect.w = size.x;
	rect.h = size.y;
}

void Texture::scaleBy(float factor)
{
	rect.w = rect.w * factor;
	rect.h = rect.h * factor;
}

void Texture::fitWidth(float width)
{
	float scale = width / rect.w;
	rect.w = width;
	rect.h = rect.h * scale;
}

void Texture::fitHeight(float height)
{
	float scale = height / rect.h;
	rect.w = rect.w * scale;
	rect.h = height;
}

}
