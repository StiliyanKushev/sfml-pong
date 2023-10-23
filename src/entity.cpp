#include <iostream>
#include "entity.hpp"

std::map<int, Entity*> entities;
static int entityIncrementalId = 0;

Entity::Entity() 
{
    id = entityIncrementalId++;
    entities.insert_or_assign(id, this);
}

Entity* Entity::CheckCollision(Entity::CollisionSide &side)
{
    for(auto &[_id, ent] : entities) 
    {
        // don't collide with yourself
        if(_id == id)
            continue;

        bool collisionDetected = 
            position.x < ent->position.x + ent->size.x &&
            position.x + size.x > ent->position.x &&
            position.y < ent->position.y + ent->size.y &&
            position.y + size.y > ent->position.y;

        if(!collisionDetected)
            continue;

        // Checking collision on the left side
        if(position.x + size.x > ent->position.x 
        && position.x < ent->position.x)
        {
            side = Entity::CollisionSide::Left;
            return ent;
        }

        // Checking collision on the right side
        if(position.x < ent->position.x + ent->size.x 
        && position.x + size.x > ent->position.x + ent->size.x)
        {
            side = Entity::CollisionSide::Right;
            return ent;
        }

        // Checking collision on the top side
        if(position.y + size.y > ent->position.y 
        && position.y < ent->position.y)
        {
            side = Entity::CollisionSide::Up;
            return ent;
        }

        // Checking collision on the bottom side
        if(position.y < ent->position.y + ent->size.y 
        && position.y + size.y > ent->position.y + ent->size.y)
        {
            side = Entity::CollisionSide::Down;
            return ent;
        }
    }

    // we didn't collide with anything
    return nullptr;
}