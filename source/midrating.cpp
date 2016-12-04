#include "midrating.h"
#include "ui_midrating.h"
//Оценка за четверть


MidRating::MidRating(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MidRating)
{
    ui->setupUi(this);
}

MidRating::~MidRating()
{
    delete ui;
}

void MidRating::on_Edit_input_editingFinished()
{
	ui->label_answer->clear();
	ui->label_for_5->clear();
	ui->label_for_4->clear();
	ui->label_for_3->clear();
	//Количество оценок
	int number = ui->Edit_input->text().length();
	if(number<=0)
		return;
	//Сумма чисел среднего арифметического
	long summ(0);
	//Суммируем числа
	for(int i(0);i<number;i++)
		summ += ui->Edit_input->text()[i].toLatin1()-48;
	//Высчитываем оценку
	//Точную
	double final_score_accurate = summ/(double)number;
	//Итоговую
	int final_score = final_score_accurate + 0.5;




	if(final_score<5)
	{
		ui->label_for_5->setNum(lifting_middle_score(summ,number,5));
		ui->label_for_5->setText("До оценки '5' не хватает пятёрок: " + ui->label_for_5->text());
		if(final_score < 4)
		{
			ui->label_for_4->setNum(lifting_middle_score(summ,number,4));
			ui->label_for_4->setText("До оценки '4' не хватает пятёрок: " + ui->label_for_4->text());
			if(final_score < 3)
			{
				ui->label_for_3->setNum(lifting_middle_score(summ,number,3));
				ui->label_for_3->setText("До оценки '3' не хватает пятёрок: " + ui->label_for_3->text());
			}

		}
	}

	ui->label_answer->setNum(final_score);
	ui->label_answer->setText("Выходит "+ui->label_answer->text());
	ui->label_accurate_score->setNum(final_score_accurate);
	ui->label_accurate_score->setText("≈" +ui->label_accurate_score->text());
}

void MidRating::on_action_triggered()
{
    //MidRating::close();
}

void MidRating::on_Edit_input_textChanged(const QString &arg1)
{
    if(ui->Edit_input->text().length()>0)
		MidRating::on_Edit_input_editingFinished();
}
