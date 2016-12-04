#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ocenka.h"
#include "startwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	// выделяем память под решалку уравнений
    equation = new QuaEqu();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_action_mid_triggered()
{
	//Средняя оценка
	static Ocenka ocWindow;
    ocWindow.show();
}

void MainWindow::on_action_toHome_triggered()
{
    MainWindow::close();
}

void MainWindow::on_Edit_C_editingFinished()
{
	Solve();
}

void MainWindow::on_Edit_A_editingFinished()
{
	Solve();
}

void MainWindow::on_Edit_B_editingFinished()
{
    Solve();
}

void MainWindow::Solve()
{
    double a = ui->Edit_A->text().toDouble();
    double b = ui->Edit_B->text().toDouble();
    double c = ui->Edit_C->text().toDouble();
    equation->resolve(a,b,c);
    ui->Disk->setText(equation->getD());
    ui->Disk_kor->setText(equation->getSqrtD());
    ui->Answer1->setText(equation->getX1());
    ui->Answer2->setText(equation->getX2());
    ui->isKomplexLabel->setText(equation->getInfo());
}
