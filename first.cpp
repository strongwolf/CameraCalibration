#include "first.h"
#include "ui_first.h"

First::First(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::First)
{
    ui->setupUi(this);
    ui->setupUi(this);
    this->resize(940,800);
    slider = new QSlider(Qt::Vertical,this);
    lineEdit = new QLineEdit(this);
    title = new QLabel(this);
    d = new QLabel(this);
    dValue = new QLineEdit(this);
    next = new QPushButton(this);
    camera = new QCamera(this);
    capture = new QCameraImageCapture(camera);
    viewfinder = new MyViewFinder(this);
    camera->setCaptureMode(QCamera::CaptureStillImage);
    camera->setViewfinder(viewfinder);
    camera->start();
    step = 1;

    title->setText(tr("镜头近似水平确定"));
    title->setGeometry(400, 140, 200, 30);
    viewfinder->setGeometry(200, 200, 600,300);
    slider->setGeometry(850, 200, 30,viewfinder->size().height());
    slider->setMinimum(0);
    slider->setMaximum(viewfinder->size().height());
    slider->setValue(slider->size().height()/2);
    lineEdit->setGeometry(250, 550, 80, 50);
    lineEdit->setAlignment(Qt::AlignCenter);
    lineEdit->setText(tr("150"));
    d->setText(tr("d值"));
    d->setGeometry(400, 510, 40, 40);
    dValue->setText(tr("5"));
    dValue->setAlignment(Qt::AlignCenter);
    dValue->setGeometry(400, 550, 80, 50);
    next->setGeometry(550, 550, 80, 50);
    next->setText(tr("下一步"));


    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(setLineEditValue(int)));
    connect(slider, SIGNAL(valueChanged(int)), viewfinder, SLOT(drawNewLine(int)));
    connect(dValue, SIGNAL(textChanged(QString)), viewfinder, SLOT(update_d_line(QString)));
    connect(next, SIGNAL(clicked(bool)), this, SLOT(on_nextbutton_clicked()));
    connect(this, SIGNAL(show_step_value(int)), viewfinder, SLOT(accept_step_value(int)));

    slider->hide();
    lineEdit->hide();

}

void First::setLineEditValue(int value)
{
  int pos = slider->value();
  QString str = QString("%1").arg(pos);
  lineEdit->setText(str);
}

void First::on_nextbutton_clicked()
{
    step = step + 1;
    if (step > 3)
    {
        height2 = slider->value();
        this->hide();
        emit show_step2();
    }
    else if (step == 2)
    {
        title->setText(tr("水平线确定"));
        slider->show();
        lineEdit->show();
        emit show_step_value(step);
    }
    else
    {
        height1 = slider->value();
        title->setText(tr("盲区停止线确定"));
        slider->show();
        lineEdit->show();
        emit show_step_value(step);
    }
}

void First::receive_step2()
{
    this->show();
}


First::~First()
{
    delete ui;
}
