#include "plateau.h"
#include <algorithm>
#include "qDebug"
#include "iostream"

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

int Plateau::getDimension(){
    return this->dimensionreal;
}

bool Plateau::isEqual(Plateau p){
    bool result=true;
    for (int i=0; i<this->sizex;i++){
        for (int j=0 ; j<this->sizey;j++){

            bool ijbool=(this->getCases(i,j).getContenu().isEqual(p.getCases(i,j).getContenu()));
            if(ijbool==false){
               // qDebug()<<ijbool;
            }
            if(i==0 && j==0){
                //qDebug()<<getCases(i,j).getContenu().getColor();
                //qDebug()<<getCases()
            }
            result=result&&ijbool;

        }
    }
    return result;
}

void Plateau::print(){
    for (int i=0; i<this->sizex;i++){
        for (int j=0 ; j<this->sizey;j++){
            Cases caseij=this->cases[i+this->sizex*j];
            if (!caseij.isFree()){
                qDebug()<< i<<j<< caseij.getContenu().getColor().c_str();
            }
        }
    }

}

void Plateau::copy(Plateau p){
    for (int i=0; i<this->sizex;i++){
        for (int j=0 ; j<this->sizey;j++){
            this->cases[i+this->sizex*j]=p.getCases(i,j);
        }
    }
}

int Plateau::mkPrisoners(int x,int y){
    int res=0;
    int coords[8]={x+1,y,x-1,y,x,y+1,x,y-1};

    for (int k = 0 ; k<4 ; k++){
            int i=coords[2*k];
            int j=coords[2*k+1];
            if(0<=i && i<19 && 0<=j && j<19){
                if (!this->isFree(i,j)){
                    if(this->nbrliberte(i,j)==0){
                        res+=mkPrisonersAux(i,j,this->getCases(i,j).getContenu());
                    }
                }
            }
    }
    return res;
}

int Plateau::mkPrisonersAux(int x,int y,Pierre p){
    if(0<=x && x<19 && 0<=y && y<19){
        if(this->getCases(x,y).getContenu().isEqual(p)){
        this->setCases(x,y,Pierre());
        return 1+
            mkPrisonersAux(x+1,y,p)+
            mkPrisonersAux(x-1,y,p)+
            mkPrisonersAux(x,y+1,p)+
            mkPrisonersAux(x,y-1,p);
        }
    }else {
        return 0;
    }

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
    Plateau board= Plateau(this->dimensionreal);
    if (this->isFree(x, y))
    {
        res = -1;
    }
    else
    {
        res = this->nbrliberte(x,y,this->getCases(x,y).getContenu(),&board);
    }
    //qDebug()<<"libertés :" << res;
    // retourne -1 si la case est vide, calcule les libertés sinon.
    return res;
}

int Plateau::nbrliberte(int x, int y, const Pierre &pierre,Plateau* board)
{

    if(x<0 || x>=19 || y<0 || y>=19 ){
        return 0;
    }else {
        if(!board->isFree(x,y)){// Check if the current position has already been tested for liberty
            return 0;
        } else{
            board->setCases(x,y,pierre);
        }
    }

    if( this->isFree(x,y)){
        return 1;
    } else if(!this->getCases(x,y).getContenu().isEqual(pierre)){
        return 0;
    }else{
        return   nbrliberte(x+1,y,pierre,board)
                +nbrliberte(x-1,y,pierre,board)
                +nbrliberte(x,y+1,pierre,board)
                +nbrliberte(x,y-1,pierre,board);
    }


}
