#pragma once

#include <SFML/Graphics.hpp>
#include "entity.hpp"

class Platform : public Entity
{
public:
    Platform(sf::Vector2f &&p);
    void Draw(sf::RenderWindow &window) override;
    void Move() override;
    static constexpr int WIDTH = 20;
    static constexpr int HEIGHT = 150;
    static constexpr int SPEED = 5;
};