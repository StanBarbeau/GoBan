#include "button.h"

Button::Button(QWidget* parent)
    :QPushButton(parent)
    , m_radius(0)
{

}

void Button::setCircleRadius(int radius)
{
    m_radius=radius;
}
void Button::paintEvent(QPaintEvent *pe)
{
    QPushButton::paintEvent(pe);
    if(m_radius>0)
    {
        //QPainter p(this);
        //p.drawEllips(rect().center(),m_radius,m_radius);
    }
}
