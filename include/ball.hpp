#pragma once

#include <SFML/Graphics.hpp>
#include "entity.hpp"

class Ball : public Entity
{
public:
    Ball(sf::Vector2f &&p);
    void Draw(sf::RenderWindow &window) override;
    void Move() override;
    static constexpr int RADIUS = 15;
    static constexpr int SPEED_X = 3;
};