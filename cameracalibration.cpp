#include "cameracalibration.h"
#include "ui_cameracalibration.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonObject>

CameraCalibration::CameraCalibration(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CameraCalibration)
{
    ui->setupUi(this);
    this->setFixedSize(940,840);
    w1 = new First(this);
    w2 = new Second(this);
    QObject::connect(w2,SIGNAL(show_step1()),w1,SLOT(receive_step2()));
    QObject::connect(w1,SIGNAL(show_step2()),w2,SLOT(receive_step1()));
    QObject::connect(w2, SIGNAL(save_alldata()), this, SLOT(save_data()));
    w1->show();
    w2->hide();
}

void CameraCalibration::save_data()
{
    QJsonObject json;
    json.insert("height1", w1->height1);
    json.insert("height2", w1->height2);
    json.insert("label1", w2->label1);
    json.insert("label2", w2->label2);
    json.insert("label3", w2->label3);
    json.insert("label4", w2->label4);

    // 构建 JSON 文档
    QJsonDocument document;
    document.setObject(json);
    QByteArray byteArray = document.toJson(QJsonDocument::Compact);
    QString strJson(byteArray);
    QFile file("data.json");
    file.open(QIODevice::WriteOnly);
    QTextStream out(&file);
    //out.setVersion(QTextStream::Qt_5_6);
    out << strJson;
    qDebug()<<strJson;
}

CameraCalibration::~CameraCalibration()
{
    delete ui;
}
