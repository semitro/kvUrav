#include "ocenka.h"
#include "ui_ocenka.h"



Ocenka::Ocenka(QWidget *parent) :
   QWidget(parent),
    ui(new Ui::Ocenka)
{
    ui->setupUi(this);
}

Ocenka::~Ocenka()
{
    delete ui;
}

void Ocenka::on_Edit_max_editingFinished()
{
	ui->label_helper->clear();
	if(ui->Edit_have->text().length()<=0
	|| ui->Edit_max->text().length()<=0)
		return;

	//Сколько баллов?
	double have = ui->Edit_have->text().toDouble();
	//Из скольки?
	double max = ui->Edit_max->text().toDouble();
	double Accurat_Score(0); //Оценка без округления
							//посчитаем через 5 строк
	int final_score(0); //Окончательная оценка,с округлением
	if(max <= 0)
	{
		ui->label_answer->setText("Некорректные данные!");
		return;
	}
	else
	{
		//Молодцы кони,подсчитали!
		Accurat_Score = Score_for_Test(have,max);
		final_score = int(Accurat_Score +0.5);//Округляем
		ui->label_answer->setNum(final_score);
		ui->label_answer->setText("Оценка: "+ui->label_answer->text());
		//Оценка без округления
		ui->label_accurate_score->setNum(double(Accurat_Score));
		//ui->label_accurate_score->setText();
	}
	//Если оценка хуже пятёрки
	if(final_score<5)
	{
		//Думаем,сколько баллов надо набрать ещё
		ui->label_helper->setNum(More_need_Test(have,max,final_score+1));
		ui->label_helper->setText("Для повышения оценки ещё нужно\n   " + ui->label_helper->text() +"  баллов");

	}
}
void Ocenka::on_Edit_have_editingFinished()
{
	Ocenka::on_Edit_max_editingFinished();
}
void Ocenka::on_Edit_have_textChanged(const QString &arg1)
{
	Ocenka::on_Edit_max_editingFinished();
}
void Ocenka::on_Edit_max_textChanged(const QString &arg1)
{
	Ocenka::on_Edit_max_editingFinished();
}
