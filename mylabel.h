#ifndef MYLABEL_H
#define MYLABEL_H

#include <QWidget>
#include <QPaintEvent>
#include <QLabel>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    MyLabel(QWidget *parent=0);
    ~MyLabel();
    virtual void paintEvent(QPaintEvent *) override;

signals:

public slots:
    void drawNewLine(int);
    void update_d_line(QString);
private:
    int current_y;
    int d;
};

#endif // MYLABEL_H
