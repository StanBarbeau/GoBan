#include <QPainter>

#include "frame.h"

Frame::Frame( QWidget* parent )
    : QFrame( parent )
    , m_radius( 15 )
{
    setFrameStyle( QFrame::Box );
    this->setAttribute( Qt::WA_TransparentForMouseEvents );
}

void Frame::connectToServer(GameServer* g){
    this->gserver=g;
}

void Frame::setCircleRadius( int radius )
{

    m_radius = radius;
}

void Frame::paintEvent( QPaintEvent* pe )
{
    QFrame::paintEvent( pe );
    if(gserver!=0)
    if ( m_radius > 0 )
    {
        QPainter p( this );
        p.drawEllipse( rect().center(), m_radius, m_radius );
    }
}
