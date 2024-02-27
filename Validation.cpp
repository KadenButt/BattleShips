#include "header/Validation.h"



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