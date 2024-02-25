//
// Created by Kaden on 22/02/2024.
//

#include "header/Grid.h"
#include <iostream>

char* Grid::getGridPointer()
{
    return this->gridptr;
}



void Grid::displayGrid()
{
    for(int j = 0; j < 10; j++)
    {
        for(int i = 0; i < 100; i++)
        {
            std::cout << *(getGridPointer() + i + 10*j);
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
