#include "joueur.h"


Joueur::Joueur()
{
    this->status = "En cours d'initialisation...";
}

bool Joueur::isEqual(Joueur other){
    return this->color==other.color ;
}

Joueur::Joueur(std::string _color)
{
    this->color = _color;
    this->pierre = Pierre(_color);
}

void Joueur::setColor(std::string newcolor)
{
    this->color = newcolor;
    this->pierre = Pierre(newcolor);
}

void Joueur::enPartie()
{
    this->status = "En cours de partie...";
}

void Joueur::abandon()
{
    this->status = "Abandon.";
}

void Joueur::victoire()
{
    this->status = "Victoire.";
}

void Joueur::defaite()
{
    this->status = "Défaite.";
}

Pierre Joueur::getPierre()
{
    return this->pierre;
}
