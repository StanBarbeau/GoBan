#ifndef CASES_H
#define CASES_H

#include "pierre.h"
#include <string>

class Cases
{
    Pierre contenu;
    int coordx;
    int coordy;
public:
    Cases(int coordx, int coordy);
    Cases();
    void setContenu(const Pierre &_contenu);
    bool isFree();
};

#endif // CASES_H
