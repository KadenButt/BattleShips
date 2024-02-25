//
// Created by Kaden on 22/02/2024.
//

#ifndef BATTLESHIPS_GRID_H
#define BATTLESHIPS_GRID_H



class Grid {



private:
    int totalShips = 5;
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

public:
    char* getGridPointer();
    void displayGrid();
    int getTotalShips();

    void shipSunk();




};


#endif //BATTLESHIPS_GRID_H
