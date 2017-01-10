#include "mainwindow.h"
#include <QApplication>
#include <thread>
#include <iostream>
#include "gameserver.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    GameServer gs = GameServer();
    gs.lancerPartie();

    return a.exec();
}
