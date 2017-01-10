#ifndef GAMESERVER_H
#define GAMESERVER_H

#include "plateau.h"
#include "joueur.h"

class GameServer
{
    int dimension;
public:
    GameServer();
    void lancerPartie();
    void setDimension(int dim);
};

#endif // GAMESERVER_H
