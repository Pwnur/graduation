#ifndef STUPASSWORD_H
#define STUPASSWORD_H

#include <QDialog>
#include <QTime>
#include <QDebug>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QMessageBox>
#include <QStringList>
#include <QDebug>
#include <QTableView>

namespace Ui {
class StuPassWord;
}

class StuPassWord : public QDialog
{
    Q_OBJECT

public:
    explicit StuPassWord(QWidget *parent = 0);
    ~StuPassWord();
    void setyanzheng();
    bool judgeEmpty();
    void clearAll();

private:
    Ui::StuPassWord *ui;
    int yanzheng;
    QString id;
    QSqlTableModel *model;

private slots:
    void comeStudentManage(QString);

    void confirmbtnSlot();
    void canclebtnSlot();

signals:
    void EmitToStuManage();
};

#endif // STUPASSWORD_H
