#ifndef TCOMMUNICATION_H
#define TCOMMUNICATION_H

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
class TCommunication;
}

class TCommunication : public QDialog
{
    Q_OBJECT

public:
    explicit TCommunication(QWidget *parent = 0);
    ~TCommunication();

    QString id;
    bool judgeEmpty();

private slots:
    void comeTeacherManage(QString);

    void ShowSupplyclick();
    void on_searchbtn_clicked();

    void on_addbtn_clicked();

    void on_changebtn_clicked();

    void on_deletebtn_clicked();

    void on_returnbtn_clicked();

private:
    Ui::TCommunication *ui;
    QSqlTableModel *model;
    QSqlTableModel *_model;
    QButtonGroup *buttongroup;


signals:
    void EmitToTeaManage();
};

#endif // TCOMMUNICATION_H
