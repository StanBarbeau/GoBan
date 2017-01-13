#include "mainwindow.h"
#include <QApplication>
#include <thread>
#include <iostream>
#include "gameserver.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameServer *gs =new GameServer();
    MainWindow w(0,gs);
    w.show();


    return a.exec();
}
