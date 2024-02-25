//
// Created by Kaden on 22/02/2024.
//

#include "header/Grid.h"
#include "header/Vector.h"
#include "header/Ship.h"
#include <iostream>


bool *getShipsPointer();

//return grid point grid[0]
char* Grid::getGridPointer()
{
    return this->gridptr;
}

//prints out grid
void Grid::displayGrid()
{
    //column
    std::cout << "   0  1  2  3  4  5  6  7  8  9" << std::endl;
    for(int j = 0; j < 10; j++)
    {
        //row
        std::cout <<  j;

        for(int i = 0; i < 10; i++)
        {
            std::cout << "  " << *(getGridPointer() + i + 10*j);
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

bool Grid::validateShipSize(int size)
{
    Ship s;

    if(size < 0 && size > 5)
    {
        return  false;
    };

    for(int i = 0; i < 5; i++)
    {
        s = *(getShipsPointer() + i);
        if( s.getSize() == size)
        {
            return false;
        }
    }

    return true;
}

bool Grid::validateShipPos(Vector pos, int size, char dir)
{
    //horizontal
    if(dir == 'h')
    {
        if(pos.x + size > 9 || size < 1 || size > 5)
        {
            return false;
        }

        for(int i = 0; i < size; i++)
        {
            if( *(getGridPointer()+ (pos.x+i) + (pos.y*10)) != ' ')
            {
                return false;
            }
        }

        return true;
    }

    //Vertical
    if(dir == 'v')
    {
        if(pos.y + size > 9 || size < 1 || size > 5)
        {
            return false;
        }

        for(int j = 0; j < size; j++)
        {
            if( *(getGridPointer()+ (pos.x) + (pos.y*10 + j*10)) != ' ')
            {
                return false;
            }
        }

        return true;
    }
    return false;
}

void Grid::placeShip(Vector pos, int size, char dir)
{

    if(validateShipSize(size) && validateShipPos(pos, size, dir))
    {
        *(getShipsPointer() + getTotalShips()) = Ship(pos, size, dir);

        if(dir == 'h')
        {
            for(int i = 0; i < size; i++)
            {
                *(getGridPointer() + (pos.x + i) + (pos.y*10)) = '*';
            }
        }

        if(dir == 'v')
        {
            for(int j = 0; j < size; j++)
            {
                *(getGridPointer()+ (pos.x) + (pos.y*10 + j*10)) = '*';
            }
        }

    }
}