#include "startwindow.h"
#include "ui_startwindow.h"
#include "ocenka.h"
#include "mainwindow.h"
#include "midrating.h"
StartWindow::StartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);
    setAnimated(true);

 }
StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::on_pushButton_clicked()
{
    static MainWindow w;
    w.show();
}

void StartWindow::on_Button_krest_clicked()
{
    static MainWindow w;
    w.show();
}



void StartWindow::on_action_urav_triggered()
{
    StartWindow::on_Button_krest_clicked();
}

void StartWindow::on_Button_test_clicked()
{
    static Ocenka w;
    w.show();
}

void StartWindow::on_action_test_triggered()
{
    StartWindow::on_Button_test_clicked();
}

void StartWindow::on_Button_mid_clicked()
{
    static MidRating w;
    w.show();
}

void StartWindow::on_action_mid_rating_triggered()
{
    StartWindow::on_Button_mid_clicked();
}
