#include "myviewfinder.h"

MyViewFinder::MyViewFinder(QWidget *parent):QCameraViewfinder(parent)
{
    current_y = 150;
    d = 5;
    part1_step = 1;
}

MyViewFinder::~MyViewFinder()
{

}

void MyViewFinder::drawNewLine(int value)
{
    current_y = this->height()-value;
    update();
}

void MyViewFinder::update_d_line(QString s)
{
    d = s.toInt();
    update();
}

void MyViewFinder::accept_step_value(int value)
{
    part1_step = value;
    update();
}

void MyViewFinder::paintEvent(QPaintEvent *event)
{
    QCameraViewfinder::paintEvent(event);
    QPainter painter(this);
    QPen pen;
    pen.setWidth(2);
    pen.setColor(Qt::red);
    pen.setStyle(Qt::SolidLine);
    painter.setPen(pen);
    painter.drawLine(0,current_y,this->width(),current_y);
    if (part1_step == 1)
    {
      pen.setStyle(Qt::DashDotLine);
      painter.setPen(pen);
      painter.drawLine(0,current_y-d,this->width(),current_y-d);
      painter.drawLine(0,current_y+d,this->width(),current_y+d);
    }
}
