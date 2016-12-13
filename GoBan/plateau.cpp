#include "plateau.h"

Plateau::Plateau(int _sizex, int _sizey)
{
    this->sizex = _sizex;
    this->sizey = _sizey;
    this->cases = new Cases[_sizex * _sizey];

}

void Plateau::setCase(int posx, int posy, Pierre pierre)
{
    this->cases[this->_sizex * posy + posx].setContenu(pierre);
}
