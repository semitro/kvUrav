#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//Квадратные уравнения
#include <QMainWindow>
#include <cmath>
#include <string>
#include <sstream>
#include "myMath.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

	void on_action_mid_triggered();
    void on_action_toHome_triggered();
    void on_Edit_C_editingFinished();
    void on_Edit_A_editingFinished();
    void on_Edit_B_editingFinished();

private:
	Ui::MainWindow *ui;
    QuaEqu *equation;
    void Solve();
};

#endif // MAINWINDOW_H
