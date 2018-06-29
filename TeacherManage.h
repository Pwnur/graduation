#ifndef TEACHERMANAGE_H
#define TEACHERMANAGE_H

#include <QDialog>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QDebug>
#include <QDebug>
#include <QPalette>
#include <QDateTime>
#include <QTimer>

#include "TAutomation.h"
#include "TElectricalautomation.h"
#include "TInformation.h"
#include "TCommunication.h"
#include "TElectronicTechnology.h"
#include "TeaPassWord.h"

namespace Ui {
class TeacherManage;
}

class TeacherManage : public QDialog
{
    Q_OBJECT

public:
    explicit TeacherManage(QWidget *parent = 0);
    ~TeacherManage();
    void btnsettrue();
    void btnsetfalse();

private slots:
    void comeLoginDialog(QString,QString);
    void settimeline();
    void setbtnEnable();

    void on_autobtn_clicked();

    void on_elecautobtn_clicked();

    void on_inforbtn_clicked();

    void on_combtn_clicked();

    void on_elecbtn_clicked();

    void on_passwordbtn_clicked();

    void on_returnbtn_clicked();

    void on_exitbtn_clicked();

signals:
    void toLoginDialog();
    void toautomation(QString);
    void tocommunication(QString);
    void toelectricalautomation(QString);
    void toelectonictechnology(QString);
    void toinfomation(QString);
    void tostupassword(QString);


private:
    Ui::TeacherManage *ui;
    QString teachername,id;
    QTimer *timelinetimer;
    TeaPassWord *teapassword;
    TAutomation *automation;
    TElectricalAutomation *electricalautomation;
    TInformation *information;
    TCommunication *communication;
    TElectronicTechnology *electronictechnology;
};

#endif // TEACHERMANAGE_H
