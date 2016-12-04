#ifndef MYMATH_H
#define MYMATH_H
//Непосредственно функции для подсчёта оценок
#include <cmath>
#include <QString>
#include <QDebug>
using std::sqrt;

//quadratic equation -(англ.) квадратные уравнения,класс для их решения
class QuaEqu{
typedef double numb;

public:
    QuaEqu();
    QuaEqu(numb a,numb b,numb c);
    QString getX1();
    QString getX2();
    QString getInfo();
    QString getD();
    QString getSqrtD();
    void resolve(numb a,numb b,numb c);
private:

    void Solve(); //вызывается в конструкторе

    numb _a,_b,_c;
    numb _D,_x1,_x2;
    QString _label_info; //для подписи снизу
    QString _label_sqrt_D;
    QString _label_D;
    QString _label_x1;
    QString _label_x2;
};

//Какая оценка за тест?
//Аргументы: сколько баллов?,из скольки возможных?
//Возвращает точную оценку,!без округления!
double Score_for_Test(double have,double max);
//Сколько баллов необходимо для повышения до оценки score
//have - сколько набрано баллов,max - из скольки
double More_need_Test(double have,double max,int score);
//Сколько пятёрок нужно для повышения оценки за четверть
//summ - сумма ряда чисел,number - количество чисел в ряду,d_s - желаемая оценка
int lifting_middle_score(double summ,int number,int desire_score);
#endif // MYMATH_H
