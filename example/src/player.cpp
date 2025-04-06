#include "Player.hpp"

#define AxisX 0
#define AxisY 1

Player::Player(const kn::TileMap& tileMap)
    : rect(48, 120, 13, 16), collisionLayer(tileMap.getLayer("Wall"))
{
    animController.loadSpriteSheet("idle", "../example/assets/player_idle.png", {13, 16}, 5);
    animController.loadSpriteSheet("walk", "../example/assets/player_walk.png", {13, 16}, 5);

    interactables = kn::TileMap::getTileCollection({
        tileMap.getLayer("Mirror"),
        tileMap.getLayer("Bed"),
        tileMap.getLayer("Desk"),
    });
}

void Player::update(const double dt)
{
    if (onGround)
    {
        if (kn::input::isPressed("jump"))
        {
            velocity.y = -200;
            onGround = false;
        }
    }
    else
        velocity.y += 980.7 * dt;

    const double xDir = kn::input::getDirection("left", "right").x;
    if (xDir != 0.0)
    {
        animController.setAnim("walk");

        if (xDir > 0.0)
            facingRight = true;
        else if (xDir < 0.0)
            facingRight = false;
    }
    else
        animController.setAnim("idle");

    velocity.x = xDir * moveSpeed;

    rect.x += static_cast<float>(velocity.x * dt);
    handleCollision(AxisX);
    rect.y += static_cast<float>(velocity.y * dt);
    handleCollision(AxisY);

    for (const auto& tile : interactables)
        if (rect.collideRect(tile.collider))
            kn::draw::rect(tile.rect, kn::color::YELLOW, 1);

    const kn::Frame* frame = animController.nextFrame(dt);

    frame->tex->flip.x = !facingRight;
    kn::window::blit(*frame->tex, rect, frame->rect);
}

void Player::handleCollision(const int axis)
{
    for (const auto& tile : collisionLayer->tiles)
        if (rect.collideRect(tile.rect))
        {
            if (axis == AxisX)
            {
                if (velocity.x > 0.0)
                    rect.right(tile.rect.left());
                else if (velocity.x < 0.0)
                    rect.left(tile.rect.right());
            }
            else if (axis == AxisY)
            {
                if (velocity.y > 0.0)
                {
                    rect.bottom(tile.rect.top());
                    onGround = true;
                }
                else if (velocity.y < 0.0)
                    rect.top(tile.rect.bottom());
                velocity.y = 0.0;
            }
            break;
        }
}
