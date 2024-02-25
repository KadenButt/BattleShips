//
// Created by Kaden on 22/02/2024.
//

#include "header/Grid.h"
#include "header/Vector.h"
#include "header/Ship.h"
#include <iostream>




//return grid point grid[0]
char* Grid::getGridPointer()
{
    return this->gridptr;
}

//prints out grid
void Grid::displayGrid()
{
    //column
    for(int j = 0; j < 10; j++)
    {
        //row
        for(int i = 0; i < 10; i++)
        {
            std::cout << *(getGridPointer() + i + 10*j);
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int Grid::getTotalShips()
{
    return this->totalShips;
}

void Grid::shoot(Vector pos)
{
    if(*(getGridPointer() + pos.x  + 10*pos.y) == ' ')
    {
        *(getGridPointer() + pos.x  + 10*pos.y) = 'O';
    }
}

Ship* Grid::getShipsPointer()
{
    return this->shipsptr;
}