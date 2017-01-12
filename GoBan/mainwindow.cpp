#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //stonesFrame = new Frame(this);
    //stonesFrame->setGeometry(10, 10, 80, 30);
    //stonesFrame->setFixedSize(300,400);
    ui->setupUi(this);
    //ui->gobanFrame->setAttribute( Qt::WA_TransparentForMouseEvents );
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

void MainWindow::paintEvent(QPaintEvent* event){
    QMainWindow::paintEvent(event);

    /*
    QPainter painter(this->stonesFrame);
    painter.drawEllipse(QPoint(100,100),100,100);
    painter.drawEllipse(QPoint(0,0),50,50);
    painter.drawEllipse(QPoint(0,0),500,500);*/
    //update();
}
    //foreach (Circle c, circleList) { // understand foreach requirements
    //    painter.drawEllipse(c.origin(), c.radius(), c.radius());
    //}
    /*QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    //helper->paint(&painter, event, elapsed);
    painter.drawEllipse(QPointF(100,100), 100, 100);
    painter.end();*/
/*void MainWindow::drawCircle(QPoint origin, int radius) {
    addCircle(origin, radius);
    update(); // update the UI
}

void MainWindow::addCircle(QPoint origin, int radius) {
    circleList.add(new Circle(origin,radius));
}
*/
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
    //update();
    /*QPaintEvent* event= new QPaintEvent();
    this->paintEvent(event);
    //painter.begin(this);
    painter.setBrush(Qt::black);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.drawEllipse(QPointF(100,100), 100, 100);
    painter.end();
    */
    //this->drawCircle(QPoint(100,100),80);

}

void MainWindow::on_radioButton_toggled(bool checked)
{

}


void MainWindow::on_goban_Button_clicked()
{
    QPoint p = this->mapFromGlobal(QCursor::pos());
    qDebug()<<p.rx()<<" "<<p.ry();
   this->ui->gobanFrame->setCircleRadius( 15 );
   this->ui->gobanFrame->update();

}

