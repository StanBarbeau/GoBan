#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"
MainWindow::MainWindow(QWidget *parent,GameServer* GS) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->gserver=GS;

    ui->setupUi(this);
    this->ui->gobanFrame->connectToServer(GS);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_quit_button_clicked()
{
    QCoreApplication::quit();
}


void MainWindow::on_size_box_currentIndexChanged(const QString &arg1)
{
    //GIVEN UP FOR NOW
    //this->gserver->plateau->setDimension(arg1.toStdString());

    update();
}


void MainWindow::on_pass_button_clicked()
{
    this->gserver->playerPassed();
    update();
}


void MainWindow::on_resign_button_clicked()
{

    this->gserver->playerResigned();
    update();
}


void MainWindow::on_play_button_clicked()
{
    this->gserver->newGame();
}

void MainWindow::on_radioButton_toggled(bool checked)
{
    //GIVEN UP FOR NOW :  No IA implemented yet
}


QPoint MainWindow::clickPosToCases(QPoint p){

    int offsetx=round( (float (p.rx()-54))/22.8);
    int offsety=round( (float (p.ry()-106))/22.8);
    //qDebug()<<p.rx()<<p.ry()<<offsetx<<offsety;
    return QPoint(offsetx,offsety);
}
void MainWindow::on_goban_Button_clicked()
{
    QPoint p = this->mapFromGlobal(QCursor::pos());
    p=clickPosToCases(p);
    if (p.rx()>=0 && p.rx()<19 && p.ry()>=0 && p.ry()<19){// Case where the click position matches with the size of the goban
       this->gserver->putStoneRequest(p.rx(),p.ry());
    }
   update();

}


