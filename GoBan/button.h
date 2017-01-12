#ifndef BUTTON_H
#define BUTTON_H
#include "QPushButton"

class Button: public QPushButton
{
Q_OBJECT
public:
    Button(QWidget*);
    void setCircleRadius(int);

protected:
    void paintEvent(QPaintEvent*);
private :
    int m_radius;
};

#endif // BUTTON_H
