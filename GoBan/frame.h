#pragma once

#include <QFrame>
#include "gameserver.h"
#include "cases.h"

class Frame : public QFrame
{
Q_OBJECT

public:
    Frame( QWidget* );
    GameServer* gserver=0;
    bool init_done=false;
    void connectToServer(GameServer* g);
    void setCircleRadius( int );

protected:
    void paintEvent( QPaintEvent* );

private:
    int stone_radius;
};
