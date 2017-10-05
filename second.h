#ifndef SECOND_H
#define SECOND_H

#include <QWidget>

namespace Ui {
class Second;
}

class Second : public QWidget
{
    Q_OBJECT

public:
    explicit Second(QWidget *parent = 0);
    ~Second();

public slots:
    void on_lastbutton_clicked();
    void receive_step1();
    void save_part2_data();
    void on_nextbutton_clicked();

signals:
    void show_step1();
    void save_alldata();


public:
    Ui::Second *ui;

public:
    QString label1, label2, label3, label4;
};

#endif // SECOND_H
