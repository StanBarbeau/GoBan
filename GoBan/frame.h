#pragma once

#include <QFrame>

class Frame : public QFrame
{
Q_OBJECT

public:
    Frame( QWidget* );

    void setCircleRadius( int );

protected:
    void paintEvent( QPaintEvent* );

private:
    int m_radius;
};
