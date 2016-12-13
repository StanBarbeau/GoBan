#ifndef PLATEAU_H
#define PLATEAU_H

#include "cases.h"
#include "pierre.h"
#include <string>

class Plateau
{
    int sizex;
    int sizey;
    Cases cases[];
public:
    Plateau(int _sizex, int _sizey);

    void setCases(int posx, int posy, Pierre& pierre);
    Cases getCases(int posx, int posy);
    bool isFree(Cases _case);
    bool isFree(int posx, int posy);
};

#endif // PLATEAU_H
