#include <SFML/Graphics.hpp>
#include "platform.hpp"

Platform::Platform(sf::Vector2f &&p)
{
    position = p;
    size = sf::Vector2f(WIDTH, HEIGHT);
}

void Platform::Move() 
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

        // if two platforms touch then stop them
        velocity.x = 0;
        velocity.y = 0;
    }
}

void Platform::Draw(sf::RenderWindow &window) 
{
    sf::RectangleShape r(size);
    r.setPosition(position.x, position.y);
    window.draw(r);
}