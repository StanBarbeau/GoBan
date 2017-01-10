#ifndef JOUEUR_H
#define JOUEUR_H

#include "string"
#include "pierre.h"

class Joueur
{
    std::string color;
    Pierre pierre;
    std::string status;
    int tour;
public:
    Joueur(std::string _color);
    void abandon();
    void defaite();
    void victoire();
};

#endif // JOUEUR_H
