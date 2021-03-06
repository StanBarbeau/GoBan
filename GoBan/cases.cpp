#include "cases.h"



Cases::Cases(){}

Cases::Cases(int _posx, int _posy)
{
    this->contenu = Pierre();
    this->coordx = _posx;
    this->coordy = _posy;
}

void Cases::setContenu(Pierre const& _contenu)
{
    this->contenu = _contenu;
}

bool Cases::isFree()
{
    return this->contenu.isNotSet();
}

Pierre Cases::getContenu()
{
    return this->contenu;
}
