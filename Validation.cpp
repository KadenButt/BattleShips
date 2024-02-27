#include "header/Validation.h"

bool isValidInput()
{
    if(!std::cin.good())
    {
        //clear string
        std::cin.clear();
        //how many character to ignore, and what character to ignore
        std::cin.ignore(INT_MAX, '\n');
        return false;
    }
    return true;
}

bool isChar(char i)
{
    return typeid(i) == typeid(char);
}

bool isInt(char i)
{
    return typeid(i) == typeid(int);
}

bool isVector(Vector i)
{
    return typeid(i) == typeid(Vector) && isInt(i.x) && isInt(i.y);
}