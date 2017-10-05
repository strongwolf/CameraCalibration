#ifndef MYVIEWFINDER_H
#define MYVIEWFINDER_H

#include <QWidget>
#include <QEvent>
#include <QCameraViewfinder>
#include <QLabel>
#include <QPen>
#include <QPainter>

class MyViewFinder : public QCameraViewfinder
{
     Q_OBJECT
public:
    MyViewFinder(QWidget *parent=0);
    ~MyViewFinder();
    void paintEvent(QPaintEvent *);

signals:

public slots:
    void drawNewLine(int);
    void update_d_line(QString);
    void accept_step_value(int);

private:
    int current_y;
    int d;
    int part1_step;
};

#endif // MYVIEWFINDER_H
