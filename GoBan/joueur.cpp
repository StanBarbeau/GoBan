#include "joueur.h"

Joueur::Joueur(std::string _color)
{
    this->color = _color;
    this->status = "En cours de partie...";
    this->pierre = Pierre(_color);
    this->tour = 0;
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
