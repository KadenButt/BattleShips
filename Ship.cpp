//
// Created by Kaden on 25/02/2024.
//

#include "header/Ship.h"
#include "header/Vector.h"

Ship::Ship(){}

Ship::Ship(Vector pos, char dir, int size)
{
    this->startPosition = pos;
    this->direction = dir;
    this->size = size;
    this->health = size;
}

Vector Ship::getStartPosition()
{
    return this->startPosition;
}

char Ship::getDirection()
{
    return this->direction;
}

int Ship::getSize()
{
    return this->size;
}

int Ship::getHealth()
{
    return this->health;
}

void Ship::hit()
{
    this->health--;
}

bool Ship::isSunk()
{
    if(this->getHealth() <= 0)
    {
        return true;
    }
    return false;
}
