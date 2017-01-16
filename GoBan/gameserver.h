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
    int tour;
    bool last_passed;
    Plateau previous_board;

    bool etat;
    Plateau board;

    bool testKo(int x, int y);
    bool isSuicide(int,int);

public:
    GameServer();
    bool newGame();
    void setDimension(int dim);
    int putStoneRequest(int x, int y);
    Joueur playerPassed();
    Joueur playerResigned();
    Plateau getPlateau();
    bool getState();
};

#endif // GAMESERVER_H
