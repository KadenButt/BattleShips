//
// Created by Kaden on 22/02/2024.
//

#ifndef BATTLESHIPS_GRID_H
#define BATTLESHIPS_GRID_H

#include "Vector.h"
#include "Ship.h"



class Grid {



private:

    int totalShips = 0;
    Ship ships[5];
    char grid[100] =
            {
                    'f',' ',' ',' ',' ',' ',' ',' ',' ',' ',
                    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
                    ' ','d',' ',' ',' ',' ',' ',' ',' ',' ',
                    ' ',' ','s',' ',' ',' ',' ',' ',' ',' ',
                    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
                    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
                    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
                    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
                    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
                    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' '
            };
    char* gridptr = &grid[0];
    Ship* shipsptr = &ships[0];

public:

    char* getGridPointer();
    void displayGrid();
    int getTotalShips();
    void shoot(Vector pos);
    void shipSunk();
    Ship* getShipsPointer();
    bool validateShipSize(int size);
    bool validateShipPos(Vector pos, int size, char dir);
    void placeShip(Vector pos, int size, char dir);




};


#endif //BATTLESHIPS_GRID_H
