#ifndef PIERRE_H
#define PIERRE_H

#include <string>

class Pierre
{
private:
    std::string color;
public:
    Pierre(std::string _color);
    Pierre();
    std::string getColor();
    bool isEqual(Pierre);
    bool isNotSet();
};

#endif // PIERRE_H
