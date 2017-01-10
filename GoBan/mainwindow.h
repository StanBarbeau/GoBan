
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "gameserver.h"
#include <QMainWindow>
#include "QPushButton"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void init();
    void test();
    ~MainWindow();





private slots:
    void on_quit_button_clicked();

    void on_size_box_currentIndexChanged(const QString &arg1);

    void on_pass_button_clicked();

    void on_resign_button_clicked();

    void on_play_button_clicked();



    void on_radioButton_toggled(bool checked);

    void on_goban_linkActivated(const QString &link);

    void on_goban_Button_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
