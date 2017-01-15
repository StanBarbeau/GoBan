#include <QPainter>
#include "QDebug"
#include "frame.h"
#include "iostream"
#include "string"

Frame::Frame( QWidget* parent )
    : QFrame( parent )
    , stone_radius( 10 )
{
    setFrameStyle( QFrame::Box );
    this->setAttribute( Qt::WA_TransparentForMouseEvents );
}

void Frame::connectToServer(GameServer* g){
    this->gserver=g;
    this->init_done=true;
}

void Frame::setCircleRadius( int radius )
{

    stone_radius = radius;
}

void Frame::paintEvent( QPaintEvent* pe )
{
    QFrame::paintEvent( pe );
    if(this->init_done && stone_radius > 0 )
    {
        if(this->gserver->getState())
        {
            Plateau board=this->gserver->getPlateau();
            QPainter p( this );
            for(int i=0;i<19;i++)
            {
                for (int j=0 ; j<19 ; j++)
                {
                    Cases caseij=board.getCases(i,j);
                    if(!caseij.isFree())
                    {
                        if(caseij.getContenu().getColor()=="white"){
                            p.setBrush(QBrush(Qt::white));
                        } else {
                            p.setBrush(QBrush(Qt::black));
                        }
                        p.drawEllipse(QPoint(15+22.8*i,15+22.8*j), stone_radius, stone_radius );
                    }
                }
            }
        }
    }
}
