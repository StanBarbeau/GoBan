#ifndef JOUEUR_H
#define JOUEUR_H

#include "string"
#include "pierre.h"

class Joueur
{
    std::string color;
    Pierre pierre;
    std::string status;
public:
    bool isEqual(Joueur other);
    Joueur();
    Joueur(std::string _color);
    void setColor(std::string newcolor);
    void abandon();
    void defaite();
    void victoire();
    void enPartie();
    Pierre getPierre();
};

#endif // JOUEUR_H
