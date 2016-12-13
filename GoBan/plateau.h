#ifndef PLATEAU_H
#define PLATEAU_H


class Plateau
{
    int sizex;
    int sizey;
    Cases cases[];
public:
    Plateau();

    void setCase(int posx, int posy, Pierre pierre);
};

#endif // PLATEAU_H
