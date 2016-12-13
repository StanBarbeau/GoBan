#include "pierre.h"

Pierre::Pierre(std::string _color)
{
    this->color = _color;
}

Pierre::Pierre()
{
    this->color = "undefined";
}

bool Pierre::isNotSet()
{
    return (this->color == "undefined");
}
