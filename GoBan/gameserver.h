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

    bool testKo(int x, int y);

public:
    GameServer();
    bool newGame();
    void setDimension(int dim);
    int putStoneRequest(int x, int y);
    void playerPassed();
    void playerResigned();
    Plateau getPlateau();
};

#endif // GAMESERVER_H
