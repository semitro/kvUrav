#include "myMath.h"
//BeginQuaEqu
QuaEqu::QuaEqu():
  _a(1),_b(1),_c(1),_x1(0),_x2(0),
  _label_info(),_label_D(),_label_sqrt_D(){

    }
QuaEqu::QuaEqu(numb a, numb b, numb c):
 _a(a),_b(b),_c(c),_x1(0),_x2(0),
 _label_info(),_label_D(),_label_sqrt_D()
{
    _D = b*b-4*a*c;
    _label_D.setNum( double(_D) );
    _label_D = "D: " + _label_D;
    Solve();
}
void QuaEqu::Solve(){
    if(_a == 0 && _b == 0){ //с такими значениями уравнение не имеет особого смысла
        _label_info = "Введите корректные коэффициенты!";
        _label_x1 = _label_x2 = '-';
        return;

    }

    if(_a == 0){
        _label_info = "a = 0, частный случай";
        _x1 = (-_c)/_b;
        _label_x1 = QString().setNum( double(_x1) );
        _label_x1 = "x: " + _label_x1;
        _label_x2.clear();
    }
    else
        if(_D >= 0)
        {
            //Простое вычисление через дискриминант
            _label_info.clear();
            _x1 = ( sqrt(_D) - _b )/ (2*_a);
            _x2 = ( -sqrt(_D) - _b )/ (2*_a);
            _label_sqrt_D.setNum( double(sqrt(_D)) );
            _label_sqrt_D = "√D: " + _label_sqrt_D;
            _label_x1.setNum( double(_x1) );
            _label_x2.setNum( double(_x2) );
            _label_x1 = "x1: " + _label_x1;
            _label_x2 = "x2: " + _label_x2;
        }
    else
        if(_D < 0)
        {

            _label_info = "*D<0, корни мнимые";
            _label_sqrt_D.setNum( double(sqrt(-_D)) );
            double x_first,x_last;  //симулируем комплексное число
            x_first = -_b/(2*_a);
            x_last = sqrt(-_D)/(2*_a);
            _label_x1 = "x1: " + QString().setNum(x_first) + " + i*" + QString().setNum(x_last);
            _label_x2 = "x2: " + QString().setNum(x_first) + " - i*" + QString().setNum(x_last);
            _label_sqrt_D = "√D: i*"+ _label_sqrt_D;

    }
}
void QuaEqu::resolve(numb a, numb b, numb c){
    *this = QuaEqu(a,b,c);
    Solve();
}
QString QuaEqu::getD(){return _label_D;}
QString QuaEqu::getInfo(){return _label_info;}
QString QuaEqu::getSqrtD(){return _label_sqrt_D;}
QString QuaEqu::getX1(){return _label_x1;}
QString QuaEqu::getX2(){return _label_x2;}
//EndQuaEqu
//Оценка за тест
double Score_for_Test(double have, double max)
{
	return (have*5)/max;
}
//Повышение баллов за тест
double More_need_Test(double have, double max, int score=5)
{
	//Фича,считающая,сколько баллов нужно для поднятия оценки
    //have до оценки rating с максимально возможным баллом max
	if(max <= 0 || have <= 0)
        return 0;

    //Работает только для к-ва вопросов <= 2048
    //Алгоритм не эффективен для больших чисел
    //Однако для малых величин таки покатит
    for(double i(0.5);i<2048;i +=0.5)
        if( (int)((( ( (have+i)*5 ) /max )+0.5))
                                == score)
            return i;
	return 0;
}
//Повышение оценки за четверть
int lifting_middle_score(double summ,int number,int desire_score=5)
{
						//double,потому что будем делить
    //Сколько пятёрок нужно
   //Для повышения оценки за четверть
    int count = number;
    //Пока выходим меньше желаемой оценки
    while(summ/double(count) < desire_score-0.5)
    {
	   //Предполагаем, что у нас ещё одна пятёрка
	   summ+=5;
	   //Запоминаем длину нового ряда
	   count++;
    }
    //Возвращаем длину нового ряда - длина старого ряда
  return count-number;
  //Молодцы,кони,отлично!
}
