//
// Created by Kaden on 22/02/2024.
//

#ifndef BATTLESHIPS_GRID_H
#define BATTLESHIPS_GRID_H

#include "Vector.h"
#include "Ship.h"



class Grid {



private:

    int totalShips = 5;
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
    bool validateShipSize();
    void shipSunk();
    Ship* getShipsPointer();




};


#endif //BATTLESHIPS_GRID_H
