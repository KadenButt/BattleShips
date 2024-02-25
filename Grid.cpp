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

void Grid::displayGridLine(int line)
{
    //column
    if(line == 0)
    {
        std::cout << "   0  1  2  3  4  5  6  7  8  9" << std::endl;
    }

    std::cout <<  line;

    for(int i = 0; i < 10; i++)
    {
        std::cout << "  " << *(getGridPointer() + i + 10*line);
    }
    std::cout << std::endl;

}

int Grid::getTotalShips()
{
    return this->totalShips;
}

void Grid::incrementTotalShips(int i)
{
    this->totalShips+=i;
}

void Grid::shoot(Vector pos)
{
    //miss shot
    if(*(getGridPointer() + pos.x  + 10*pos.y) == ' ')
    {
        *(getGridPointer() + pos.x  + 10*pos.y) = 'O';
    }
    //hit ship
    else if(*(getGridPointer() + pos.x  + 10*pos.y) == '*')
    {
        for(int i = 0; i < getTotalShips(); i++)
        {
            Ship& s = *(getShipsPointer() + i);
            //check horizontally

            //check both vertically and horzontially for a hit
            if(pos.x >= s.getStartPosition().x && pos.x <= s.getStartPosition().x+s.getSize() && pos.y == s.getStartPosition().y || pos.y >= s.getStartPosition().y && pos.y <= s.getStartPosition().y+s.getSize() && pos.x == s.getStartPosition().x)
            {
                s.hit();
                if(s.isSunk())
                {
                    incrementTotalShips(-1);
                    std::cout<<"Your Ship has been sunk" << std::endl;
                }
                break;



            }

            //checks space vertically

        }

    }


}

Ship* Grid::getShipsPointer()
{
    return this->shipsptr;
}

bool Grid::validateShoot(Vector pos)
{
    if(pos.x < 0 || pos.x >  9 || pos.y < 0 || pos.y > 9)
    {
        return false;
    }

    if( *(getGridPointer() + pos.x  + 10*pos.y) == 'O')
    {
        return false;
    }

    return true;
}

bool Grid::validateShipSize(int size)
{
    Ship s;

    if(size < 0 || size > 5)
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
        incrementTotalShips(1);


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