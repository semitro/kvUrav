#ifndef MIDRATING_H
#define MIDRATING_H
//Оценка за четверть
#include <QMainWindow>
#include "myMath.h"
namespace Ui {
class MidRating;
}

class MidRating : public QMainWindow
{
    Q_OBJECT

public:
    explicit MidRating(QWidget *parent = 0);
    ~MidRating();

private slots:
    void on_Edit_input_editingFinished();
    void on_action_triggered();
    void on_Edit_input_textChanged(const QString &arg1);

private:
    Ui::MidRating *ui;
};

#endif // MIDRATING_H
