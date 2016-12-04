#ifndef OCENKA_H
#define OCENKA_H
//Оценка за тест
#include <QWidget>
#include "myMath.h"

namespace Ui {
class Ocenka;
}

class Ocenka : public QWidget
{
    Q_OBJECT

public:
    explicit Ocenka(QWidget *parent = 0);
    ~Ocenka();

private slots:
    void on_Edit_max_editingFinished();
    void on_Edit_have_editingFinished();
    void on_Edit_have_textChanged(const QString &arg1);
    void on_Edit_max_textChanged(const QString &arg1);

private:
    Ui::Ocenka *ui;
};

#endif // OCENKA_H
