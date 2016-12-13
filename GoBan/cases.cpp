#include "cases.h"

Cases::Cases(int _posx, int _posy)
{
    this->contenu = nullptr;
    this->coordx = _posx;
    this->coordy = _posy;
}

void Cases::setPierre(Pierre _contenu)
{
    this->contenu = _contenu;
}
