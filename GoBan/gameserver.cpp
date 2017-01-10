#include "gameserver.h"


void partie(int dimension)
{
    Joueur Player1 = Joueur("Blanc");
    Joueur Player2 = Joueur("Noir");
    Plateau board = Plateau(dimension, dimension);
    bool etat = true;

    while(etat)
    {
        etat = false;
    }

    Player1.~Joueur();
    Player2.~Joueur();
    board.~Plateau();
}

GameServer::GameServer()
{

}

GameServer::lancerPartie()
{

}
