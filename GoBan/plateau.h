#ifndef PLATEAU_H
#define PLATEAU_H

#include "cases.h"
#include "pierre.h"
#include <string>
#include <vector>

class Plateau
{
    int sizex;
    int sizey;
    Cases cases[];

public:
    Plateau(int _sizex, int _sizey);
    void setCases(int posx, int posy, const Pierre &pierre);
    Cases getCases(int posx, int posy);
    bool isFree(int posx, int posy);
};

#endif // PLATEAU_H
