#include "plateau.h"
#include <algorithm>
#include "qDebug"

Plateau::Plateau()
{

}

Plateau::Plateau(int dimension)
{

    this->sizex = this->dimensionmax;
    this->sizey = this->dimensionmax;
    this->dimensionreal = std::max(0, std::min(this->dimensionmax, dimension));
    this->casesvides = this->dimensionreal * this->dimensionreal;
    this->marge = (this->dimensionmax - this->dimensionreal) / 2;

    for (int j = 0; j < this->sizey; j++)
    {
        for(int i = 0; i < this->sizex; i++)
        {
            this->cases[ i + j * this->sizex] = Cases(i,j);
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

int Plateau::nbrliberte(int x, int y)
{
    int res;

    if (this->isFree(x, y))
    {
        res = 5;
    }
    else
    {
        res = this->nbrliberte(x,y,this->getCases(x,y).getContenu());
    }

    // retourne 5 si la case est vide, calcule les libertés sinon.
    return res;
}

int Plateau::nbrliberte(int x, int y, const Pierre &pierre)
{
    int res = 4;

    //if ()

    return res;
}
