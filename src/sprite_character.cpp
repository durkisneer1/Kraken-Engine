#include "../include/SpriteCharacter.hpp"
#include <memory>


namespace dk {
	CharacterSprite::CharacterSprite(dk::RenderWindow& window, dk::Texture& texture)
	: SpriteNode(window, texture) {}
}
