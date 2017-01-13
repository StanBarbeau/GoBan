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

void GameServer::lancerPartie()
{
    if (this->dimension)
    {
        this->board = Plateau(this->dimension, this->dimension);
        this->etat = true;
    }
    else
    {
        std::cout << "Veuillez tout d'abord régler la taille du plateau.";
    }
}

void GameServer::setDimension(int dim)
{
    this->dimension = dim;
}

int GameServer::jouercoup(int x, int y)
{
    int res = 0;

    if (this->etat)
    {
        res = 3;
    }
    else if (this->board.isFree(x, y))
    {

    }

    // Cette fonction renvoie un entier de l'ordre de 10,000 qui respecte la forme suivante:
    // res = 0 déjà une pierre en place, ou règle de ko.
    // res = 1 xx yy on place une pierre pour le joueur blanc en xx yy
    // res = 2 xx yy on place une pierre pour le joueur noir en xx yy
    // res = 3 la partie n joue pas.
    return res;
}
