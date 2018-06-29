#ifndef STUDENTMANAGE_H
#define STUDENTMANAGE_H

#include <QDialog>
#include <QDebug>
#include <QPalette>
#include <QDateTime>
#include <QTimer>

#include "Automation.h"
#include "ElectricalAutomation.h"
#include "Information.h"
#include "Communication.h"
#include "ElectronicTechnology.h"
#include "StuPassWord.h"

namespace Ui {
class StudentManage;
}

class StudentManage : public QDialog
{
    Q_OBJECT

public:
    explicit StudentManage(QWidget *parent = 0);
    ~StudentManage();
    void btnsettrue();
    void btnsetfalse();

private slots:
    void comeLoginDialog(QString,QString);
    void settimeline();

    void autoSlot();
    void combtnSlot();
    void elecautobtnSlot();
    void elecbtnSlot();
    void inforbtnSlot();

    void passwordbtnSlot();

    void exitbtnSlot();
    void setbtnEnable();
    void returnbtnSlot();

signals:
    void toLoginDialog();
    void toautomation(QString);
    void tocommunication(QString);
    void toelectricalautomation(QString);
    void toelectonictechnology(QString);
    void toinfomation(QString);
    void tostupassword(QString);


private:
    Ui::StudentManage *ui;
    QString studentname,id;
    QTimer *timelinetimer;
    StuPassWord *stupassword;
    Automation *automation;
    ElectricalAutomation *electricalautomation;
    Information *information;
    Communication *communication;
    ElectronicTechnology *electronictechnology;
};

#endif // STUDENTMANAGE_H
