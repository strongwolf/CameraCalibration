#include "mylabel.h"
#include <QPainter>
#include <QPen>
#include <QDebug>

MyLabel::MyLabel(QWidget *parent):QLabel(parent)
{
    current_y = this->height()/2;
    d = 5;
}

MyLabel::~MyLabel()
{

}

void MyLabel::drawNewLine(int value)
{
    current_y = this->height()-value;
    update();
}

void MyLabel::update_d_line(QString s)
{
    d = s.toInt();
    update();
}

void MyLabel::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event);
    QPainter painter(this);
    QPen pen;
    pen.setWidth(2);
    pen.setColor(Qt::red);
    pen.setStyle(Qt::SolidLine);
    painter.setPen(pen);
    painter.drawLine(0,current_y,this->width(),current_y);
    pen.setStyle(Qt::DashDotLine);
    painter.setPen(pen);
    painter.drawLine(0,current_y-d,this->width(),current_y-d);
    painter.drawLine(0,current_y+d,this->width(),current_y+d);
}
