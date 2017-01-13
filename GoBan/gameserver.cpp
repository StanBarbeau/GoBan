#include "gameserver.h"
#include <iostream>


GameServer::GameServer()
{
    this->dimension=19;
    this->etat = false;
    this->player1 = Joueur("Blanc");
    this->player2 = Joueur("Noir");
    this->activplayer = this->player1;
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
    }
    else
    {
        std::cout << "Veuillez tout d'abord régler la taille du plateau.";
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
    int res = 0;
/*
    if (this->etat)
    {
        res = 3;
    }
    else if (this->board.isFree(x, y))
    {
        if (this->testKo(x,y))
        {
            this->getPlateau().setCases(x,y,this->activplayer.getPierre());
            res += (100*x + y);

            if (this->activplayer == this->player1)
            {
                res += 10000;
            }
            else
            {
                res += 20000;
            }

        }
    }*/

    // Cette fonction renvoie un entier de l'ordre de 10,000 qui respecte la forme suivante:
    // res = 0 déjà une pierre en place, ou règle de ko.
    // res = 1 xx yy on place une pierre pour le joueur blanc en xx yy
    // res = 2 xx yy on place une pierre pour le joueur noir en xx yy
    // res = 3 la partie n joue pas.
    return res;
}

Joueur GameServer::playerPassed()
{
    Joueur passing = Joueur(this->activplayer);

    /*if (this->activplayer == this->player1)
    {
        this->activplayer = this->player2;
    }
    else
    {
        this->activplayer = this->player1;
    }*/

    return passing;
}

Joueur GameServer::playerResigned()
{
    this->etat = false;
    Joueur winner;

    /*if (this->activplayer == this->player1)
    {
        this->player1.defaite();
        this->player2.victoire();

        winner = Joueur(this->player2);
    }
    else
    {
        this->player1.victoire();
        this->player2.defaite();

        winner = Joueur(this->player1);
    }*/

    return winner;
}

Plateau GameServer::getPlateau()
{
    return this->board;
}
