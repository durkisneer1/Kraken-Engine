#pragma once

#include <KrakenEngine.hpp>
#include <vector>
#include <memory>


class Player : public kn::sprite::Sprite {
public:
    Player(kn::RenderWindow& window, std::shared_ptr<kn::Texture> texture);
    ~Player() = default;

    template <typename T>
    void update(double deltaTime, const kn::sprite::Group<T>& group);

private:
    std::vector<KN_KEYS> moveLeft = { KNK_a, KNK_left };
    std::vector<KN_KEYS> moveRight = { KNK_d, KNK_right };

    float speed = 110.0f;
};
