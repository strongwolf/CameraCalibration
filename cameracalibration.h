#ifndef CAMERACALIBRATION_H
#define CAMERACALIBRATION_H

#include <QMainWindow>
#include "first.h"
#include "second.h"

namespace Ui {
class CameraCalibration;
}

class CameraCalibration : public QMainWindow
{
    Q_OBJECT

public:
    explicit CameraCalibration(QWidget *parent = 0);
    ~CameraCalibration();

public slots:
    void save_data();

private:
    Ui::CameraCalibration *ui;
    First *w1;
    Second *w2;
};

#endif // CAMERACALIBRATION_H
