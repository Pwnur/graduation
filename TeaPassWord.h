#ifndef TEAPASSWORD_H
#define TEAPASSWORD_H

#include <QDialog>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QStringList>
#include <QDebug>
#include <QTableView>
#include <QButtonGroup>
#include <QSqlDatabase>
#include <QtSql>


namespace Ui {
class TeaPassWord;
}

class TeaPassWord : public QDialog
{
    Q_OBJECT

public:
    explicit TeaPassWord(QWidget *parent = 0);
    ~TeaPassWord();
    void setyanzheng();
    bool judgeEmpty();
    void clearAll();

private slots:
    void on_confirmbtn_clicked();

    void on_canclebtn_clicked();

    void comeStudentManage(QString);

private:
    Ui::TeaPassWord *ui;
    int yanzheng;
    QString id;
    QSqlTableModel *model;

signals:
    void EmitToStuManage();
};

#endif // TEAPASSWORD_H
