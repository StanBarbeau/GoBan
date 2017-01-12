#include <QPainter>

#include "frame.h"

Frame::Frame( QWidget* parent )
    : QFrame( parent )
    , m_radius( 0 )
{
    setFrameStyle( QFrame::Box );
    this->setAttribute( Qt::WA_TransparentForMouseEvents );
}

void Frame::setCircleRadius( int radius )
{
    m_radius = radius;
}

void Frame::paintEvent( QPaintEvent* pe )
{
    QFrame::paintEvent( pe );

    if ( m_radius > 0 )
    {
        QPainter p( this );
        p.drawEllipse( rect().center(), m_radius, m_radius );
    }
}
