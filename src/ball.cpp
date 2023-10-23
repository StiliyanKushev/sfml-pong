#include "ball.hpp"
#include <iostream>

Ball::Ball(sf::Vector2f &&p)
{
    position = p;
    size = sf::Vector2f(RADIUS*2, RADIUS*2);
}

void Ball::Draw(sf::RenderWindow &window) 
{
    sf::CircleShape c(RADIUS);
    c.setPosition(position.x, position.y);
    window.draw(c);
}

void Ball::Move() 
{
    int old_x = position.x;
    int old_y = position.y;

    position.x += velocity.x;
    position.y += velocity.y;

    Entity::CollisionSide side;
    auto eCollided = CheckCollision(side);

    if(eCollided != nullptr)
    {
        // revert back to when we didn't collide
        position.x = old_x;
        position.y = old_y;

        if(side == Entity::CollisionSide::Left
        || side == Entity::CollisionSide::Right)
        {
            velocity.x *= -1;
        }

        if(side == Entity::CollisionSide::Up
        || side == Entity::CollisionSide::Down)
        {
            velocity.y *= -1;
        }
    }
}