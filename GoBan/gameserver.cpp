#include "gameserver.h"
#include <thread>


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
}

GameServer::GameServer()
{
    this->dimension = 0;
}

void GameServer::lancerPartie()
{
    std::thread jeu (partie, this->dimension);
    jeu.join();
}

void GameServer::setDimension(int dim)
{
    this->dimension = dim;
}
