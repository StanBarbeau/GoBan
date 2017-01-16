#ifndef PLATEAU_H
#define PLATEAU_H

#include "cases.h"
#include "pierre.h"
#include <string>
#include <vector>

class Plateau
{
private :
    int sizex;
    int sizey;
    static const int dimensionmax = 19;
    int casesvides;
    int marge;
    Cases cases[19*19];
    int dimensionreal;
    int nbrliberte(int x, int y, Pierre const& pierre,Plateau* p);
    int mkPrisonersAux(int,int,Pierre);

public:
    void print();
    int mkPrisoners(int,int);
    int getDimension();
    bool isEqual(Plateau);
    Plateau();
    Plateau(int dimension);
    void setCases(int posx, int posy, const Pierre &pierre);
    Cases getCases(int posx, int posy);
    bool isFree(int posx, int posy);
    int nbrliberte(int x, int y);
    void copy(Plateau);
};

#endif // PLATEAU_H
