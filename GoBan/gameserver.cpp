#include "gameserver.h"
#include <iostream>
#include <QDebug>


GameServer::GameServer()
{
    this->board = Plateau(this->dimension);
    this->dimension=19;
    this->etat = false;
    this->player1 = Joueur("black");
    this->player2 = Joueur("white");
    this->activplayer = this->player1;
}

bool GameServer::getState(){
    return this->etat;
}

bool GameServer::newGame()
// return true si la partie est lancée, false sinon.
{
    if (this->dimension)
    {
        this->board = Plateau(this->dimension);
        this->etat = true;
        this->player1.enPartie();
        this->player2.enPartie();
        this->tour=1;
        this->last_passed=false;
        this->previous_board=Plateau(this->dimension);

    }
    else
    {
        qDebug() << "Veuillez tout d'abord régler la taille du plateau.";
    }

    return this->etat;
}

void GameServer::setDimension(int dim)
{
    if (etat == false)
    {
        this->dimension = dim;
    }
}

bool GameServer::testKo(int x, int y)
{
    //return false si règle du Ko non respectée, true sinon.
    bool res = true;

    return res;
}

int GameServer::putStoneRequest(int x, int y)
{

    Plateau current= Plateau(this->board.getDimension());
    current.copy(this->board);
    int res = 0;
    if(!this->etat){
        qDebug()<< "game not initialized, please press the play button";
        return 3;
    }else if(this->isSuicide(x,y)){
        return 3;

    }else if(this->board.isFree(x,y)){
        this->last_passed=false;
        this->board.setCases(x,y,this->activplayer.getPierre());
        this->board.mkPrisoners(x,y);

        qDebug()<< "previous";
        this->previous_board.print();
        qDebug()<< "current";
        current.print();
        qDebug()<< "normal";
        this->board.print();


        if(this->previous_board.isEqual(this->board)&& this->tour>1){// Ko scenario
            qDebug()<<"banana";
            this->board.copy(current); // The turn is not accepted, we go back to the previous situation
            return 3;
        }

        this->previous_board.copy(current);
        this->tour+=1;

        if (this->activplayer.isEqual(this->player1))
        {
            this->activplayer = this->player2;
            return 1;
        }
        else
        {
            this->activplayer = this->player1;
            return 2;
        }

    }
    //std::string col=this->board.getCases(x,y).getContenu().getColor();
    //qDebug()<<col.c_str()<< "end";
    return res;
}

bool GameServer::isSuicide(int x,int y){
    Plateau current= Plateau(this->board.getDimension());
    current.copy(this->board);
    if(this->etat && current.isFree(x,y)){
        current.setCases(x,y,this->activplayer.getPierre());
        current.mkPrisoners(x,y);
    }
    int res= current.nbrliberte(x,y);
    //qDebug()<<res;
    return res==0;

}

Joueur GameServer::playerPassed()
{
    if(this->last_passed==true){
        this->etat=false;
        qDebug()<<"The game is over, count your territory and prisoners!";
    }
    last_passed=true;
    Joueur passing = Joueur(this->activplayer);

    if (this->activplayer.isEqual(this->player1))
    {
        this->activplayer = this->player2;
    }
    else
    {
        this->activplayer = this->player1;
    }

    return passing;
}

Joueur GameServer::playerResigned()
{
    this->etat = false;
    Joueur winner;

    if ((this->activplayer).isEqual(this->player1))
    {
        this->player1.defaite();
        this->player2.victoire();
        qDebug() << player2.getPierre().getColor().c_str() << "has won";
        winner = Joueur(this->player2);
    }
    else
    {
        this->player1.victoire();
        this->player2.defaite();
        qDebug() << player1.getPierre().getColor().c_str() << "has won";

        winner = Joueur(this->player1);
    }

    return winner;
}

Plateau GameServer::getPlateau()
{
    return this->board;
}
