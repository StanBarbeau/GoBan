#ifndef GAMESERVER_H
#define GAMESERVER_H

#include "plateau.h"
#include "joueur.h"

class GameServer
{
    int dimension;
    Joueur player1;
    Joueur player2;
    Joueur activplayer;

    bool etat;
    Plateau board;

public:
    GameServer();
    void lancerPartie();
    void setDimension(int dim);
    int jouercoup(int x, int y);
};

#endif // GAMESERVER_H
