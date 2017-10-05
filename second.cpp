#include "second.h"
#include "ui_second.h"

Second::Second(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Second)
{
    ui->setupUi(this);
    this->resize(1450,800);
    connect(ui->last, SIGNAL(clicked(bool)), this, SLOT(on_lastbutton_clicked()));
    connect(ui->confirm, SIGNAL(clicked(bool)), this, SLOT(save_part2_data()));
    connect(ui->next, SIGNAL(clicked(bool)), this, SLOT(on_nextbutton_clicked()));
}


void Second::on_lastbutton_clicked()
{
    this->hide();
    emit show_step1();
}

void Second::receive_step1()
{
    this->show();
}


void Second::save_part2_data()
{
    label1 = ui->lineEdit->text();
    label2 = ui->lineEdit_2->text();
    label3 = ui->lineEdit_3->text();
    label4 = ui->lineEdit_4->text();
}

void Second::on_nextbutton_clicked()
{
    emit save_alldata();
}

Second::~Second()
{
    delete ui;
}
