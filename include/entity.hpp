#pragma once

#include <SFML/Graphics.hpp>

class Entity
{
public: 
    int id;
    Entity();
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f size;
    virtual void Draw(sf::RenderWindow &window) {};
    virtual void Move() {};
    enum CollisionSide { Left, Right, Up, Down };
    Entity* CheckCollision(Entity::CollisionSide &side);
};

extern std::map<int, Entity*> entities;