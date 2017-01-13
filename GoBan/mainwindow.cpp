#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"
MainWindow::MainWindow(QWidget *parent,GameServer* GS) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->gserver=GS;

    //stonesFrame = new Frame(this);
    //stonesFrame->setGeometry(10, 10, 80, 30);
    //stonesFrame->setFixedSize(300,400);
    ui->setupUi(this);
    this->ui->gobanFrame->connectToServer(GS);
    //ui->gobanFrame->setAttribute( Qt::WA_TransparentForMouseEvents );
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
    //TODOFUNCTION Barbeau
    //this->gserver->playerPassed();
}


void MainWindow::on_resign_button_clicked()
{

    //TODOFUNCTION Barbeau
    //this->gserver->playerResigned();
    update();
}


void MainWindow::on_play_button_clicked()
{
    //TODOFUNCTION Barbeau
    //this->gserver->newGame();
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
    //qDebug()<<p.rx()<<" "<<p.ry();
    p=clickPosToCases(p);
    if (p.rx()>=0 && p.rx()<19 && p.ry()>=0 && p.ry()<19){// Case where the click position doesn't match with a cross of the Goban
    //TODOFUNCTION Barbeau
    //this->gserver->putStoneRequest(p.rx(),p.ry());
    }
   update();

}


