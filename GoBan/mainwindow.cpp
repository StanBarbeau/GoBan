#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stdio.h"
#include "QString"
#include "QPoint"
#include "qdebug.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init(){

    /*
    QWidget * wdg = new QWidget(this);
    QPushButton *play_button = new QPushButton(wdg);
    play_button->setText(tr("Jouer"));
    play_button->resize(500,100);
    play_button->move(200,100);
    connect(play_button, SIGNAL (released()), this, SLOT (test()));
    setCentralWidget(wdg);
    */

}

void MainWindow::test(){
}


void MainWindow::on_quit_button_clicked()
{
    QCoreApplication::quit();
}

void MainWindow::on_size_box_currentIndexChanged(const QString &arg1)
{

}

void MainWindow::on_pass_button_clicked()
{

}

void MainWindow::on_resign_button_clicked()
{

}

void MainWindow::on_play_button_clicked()
{

}

void MainWindow::on_radioButton_toggled(bool checked)
{

}

void MainWindow::on_goban_linkActivated(const QString &link)
{

}

void MainWindow::on_goban_Button_clicked()
{
    QPoint p = this->mapFromGlobal(QCursor::pos());
    qDebug()<<p.rx()<<" "<<p.ry();

}
