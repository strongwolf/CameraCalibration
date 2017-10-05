#ifndef FIRST_H
#define FIRST_H

#include <QWidget>
#include <QMainWindow>
#include <QSlider>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QImage>
#include <QDialog>
#include <QPainter>
#include <QPoint>
#include <QPen>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QtMultimedia/QCamera>
#include <QtMultimedia/QCameraImageCapture>
#include <QCameraViewfinder>
#include "myviewfinder.h"

namespace Ui {
class First;
}

class First : public QWidget
{
    Q_OBJECT

public:
    explicit First(QWidget *parent = 0);
    ~First();

public slots:
    void setLineEditValue(int value);
    void on_nextbutton_clicked();
    void receive_step2();



signals:
    void show_step2();
    void show_step_value(int);

private:
    Ui::First *ui;
    QLineEdit *lineEdit;
    QLabel *d;
    QSlider *slider;
    MyViewFinder *viewfinder;
    QLineEdit *dValue;
    QPushButton *next;
    QCamera *camera;
    QCameraImageCapture *capture;
    //QCameraViewfinder *viewfinder;
    QLabel *title;
    int step;

public:
    int height1;
    int height2;

};

#endif // FIRST_H
