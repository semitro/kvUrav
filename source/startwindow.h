#ifndef STARTWINDOW_H
#define STARTWINDOW_H
//Окно запуска приложения
#include <QMainWindow>

namespace Ui {
class StartWindow;
}

class StartWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = 0);
    ~StartWindow();

private slots:
    void on_pushButton_clicked();
    void on_Button_krest_clicked();
    void on_action_urav_triggered();
    void on_Button_test_clicked();
    void on_action_test_triggered();
    void on_Button_mid_clicked();
    void on_action_mid_rating_triggered();

private:
    Ui::StartWindow *ui;
};

#endif // STARTWINDOW_H
