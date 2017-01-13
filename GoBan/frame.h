#pragma once

#include <QFrame>
#include "gameserver.h"
class Frame : public QFrame
{
Q_OBJECT

public:
    Frame( QWidget* );
    GameServer* gserver=0;

    void connectToServer(GameServer* g);
    void setCircleRadius( int );

protected:
    void paintEvent( QPaintEvent* );

private:
    int m_radius;
};
