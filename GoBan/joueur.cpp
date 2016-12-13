#include "joueur.h"

Joueur::Joueur(std::string _color)
{
    this->color = _color;
    this->status = "En cours de partie...";
    this->pierre = Pierre(_color);
}
