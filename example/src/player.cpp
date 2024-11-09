#include "include/Player.hpp"
#include "Constants.hpp"
#include "Draw.hpp"
#include "Rect.hpp"
#include "Texture.hpp"

#define AxisX 0
#define AxisY 1

Player::Player(const kn::Layer* collisionLayer)
    : animController(5), rect(48, 120, 13, 16), collisionLayer(collisionLayer)
{

    animController.addAnim("../example/assets/player_idle.png", "idle", 13, 16);
    animController.addAnim("../example/assets/player_walk.png", "walk", 13, 16);
    animController.setAnim("idle");
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
    if (dirVec.x != 0.0)
    {
        animController.setAnim("walk");
        if (dirVec.x > 0.0)
            facingRight = true;
        else if (dirVec.x < 0.0)
            facingRight = false;
    }
    else
        animController.setAnim("idle");

    velocity.x = dirVec.x * moveSpeed;

    rect.x += static_cast<float>(velocity.x * dt);
    handleCollision(AxisX);
    rect.y += static_cast<float>(velocity.y * dt);
    handleCollision(AxisY);

    if (facingRight)
    {
        kn::window::blit(animController.getAnimSpritesheet(), rect, animController.update(dt));
    }
    else
        kn::window::blitEx(animController.getAnimSpritesheet(), rect, animController.update(dt), 0,
                           true);
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
