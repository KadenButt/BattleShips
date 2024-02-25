//
// Created by Kaden on 25/02/2024.
//

#ifndef BATTLESHIPS_SHIP_H
#define BATTLESHIPS_SHIP_H


#include "Vector.h"

class Ship {

private:
    Vector startPosition;
    char direction;
    int size;
    int health;

public:
    Ship();
    Ship(Vector pos, int size, char dir);
    Vector getStartPosition();
    char getDirection();
    int getSize();
    int getHealth();
    void hit();
    bool isSunk();


};


#endif //BATTLESHIPS_SHIP_H
