#include <iostream>
#include "header/Grid.h"
#include "header/Vector.h"
#include "header/Validation.h"


const int TOTALSHIPS = 5;


Grid playerGrid;
Grid enemyGrid;

bool allShipsPlaced = false;
bool validInputs = true;

int placedShips = 0;

int tempX;
int tempY;
int tempSize;

char tempDirection;


int main()
{



    std::cout<<"Player Grid;" << std::endl;

    //player place ships


    while(placedShips < TOTALSHIPS ) {
       std::cout << "Please input the X axis: ";
        std::cin >> tempX;

        std::cout << "Please input the X axis: ";
        std::cin >> tempX;


        std::cout << "Please input the Y axis: ";
        std::cin >> tempY;


        std::cout << "Please input the size: ";
        std::cin >> tempSize;

        std::cout << "Please input the direction: ";
        std::cin >> tempDirection;

        std::cout << std::endl;


        if(playerGrid.placeShip(Vector(tempX, tempY),tempSize, tempDirection))
        {
            placedShips++;
            playerGrid.displayGrid();
        }
        else
        {
            std::cout << "Ship was unable to be placed!" << std::endl;
        }

    }


}
