#include "include/Player.hpp"

#define AxisX 0
#define AxisY 1

Player::Player(const kn::Layer* collisionLayer)
    : texture(), rect(),
      collisionLayer(collisionLayer)
{
    if (!texture.loadFromFile("../example/assets/player.png"))
    {
        ERROR("Failed to load texture from file ../example/assets/player.png")
    }
    rect = texture.getRect();
    rect.setTopLeft({48, 120});
}

void Player::update(const double dt)
{
    const Uint8* keys = kn::input::getKeysPressed();
    if (onGround)
    {
        if (keys[kn::S_SPACE])
        {
            velocity.y = -200;
            onGround = false;
        }
    }
    else
        velocity.y += 980.0 * dt;

    const auto dirVec = kn::input::getVector({kn::S_a}, {kn::S_d});
    velocity.x = dirVec.x * moveSpeed;

    rect.x += static_cast<float>(velocity.x * dt);
    handleCollision(AxisX);
    rect.y += static_cast<float>(velocity.y * dt);
    handleCollision(AxisY);

    kn::window::blit(texture, rect);
}

void Player::handleCollision(const int axis)
{
    for (const auto& tile : collisionLayer->tiles)
        if (rect.collideRect(tile.rect))
        {
            if (axis == AxisX)
            {
                if (velocity.x > 0.0)
                    rect.setRight(tile.rect.getLeft());
                else if (velocity.x < 0.0)
                    rect.setLeft(tile.rect.getRight());
            }
            else if (axis == AxisY)
            {
                if (velocity.y > 0.0)
                {
                    rect.setBottom(tile.rect.getTop());
                    onGround = true;
                }
                else if (velocity.y < 0.0)
                    rect.setTop(tile.rect.getBottom());
                velocity.y = 0.0;
            }
            break;
        }
}
