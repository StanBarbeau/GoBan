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

    bool isNotSet();
};

#endif // PIERRE_H
