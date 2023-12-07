#pragma once

#include <KrakenEngine.hpp>
#include <vector>
#include <memory>


class Player : public kn::Sprite {
public:
    Player(kn::RenderWindow& window, std::shared_ptr<kn::Texture> texture);
    ~Player() = default;

    void process(double deltaTime) override;

private:
    std::vector<KN_KEYS> moveLeft = { KNK_a, KNK_left };
    std::vector<KN_KEYS> moveRight = { KNK_d, KNK_right };

    float speed = 450.0f;
};
