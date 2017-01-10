#include "plateau.h"


Plateau::Plateau(int _sizex, int _sizey)
{
    this->sizex = _sizex;
    this->sizey = _sizey;
    this->cases = {};

    for (int j = 0; j < _sizey; j++)
    {
        for(int i = 0; i < _sizex; i++)
        {
            this->cases[ i + j * _sizex ] = Cases(i,j);
        }
    }
}

void Plateau::setCases(int posx, int posy, Pierre const& pierre)
{
    this->cases[this->sizex * posy + posx].setContenu(pierre);
}

bool Plateau::isFree(int posx, int posy)
{
    return this->getCases(posx, posy).isFree();
}

Cases Plateau::getCases(int posx, int posy)
{
    return this->cases[this->sizex * posy + posx];
}
