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
    static const int dimensionmax = 19;
    int dimensionreal;
    int casesvides;
    int marge;
    Cases cases[];

public:
    Plateau();
    Plateau(int dimension);
    void setCases(int posx, int posy, const Pierre &pierre);
    Cases getCases(int posx, int posy);
    bool isFree(int posx, int posy);
    int nbrliberte(int x, int y);
    int nbrliberte(int x, int y, Pierre const& pierre);
};

#endif // PLATEAU_H
