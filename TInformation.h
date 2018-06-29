#ifndef TINFORMATION_H
#define TINFORMATION_H

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
class TInformation;
}

class TInformation : public QDialog
{
    Q_OBJECT

public:
    explicit TInformation(QWidget *parent = 0);
    ~TInformation();

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
    Ui::TInformation *ui;
    QSqlTableModel *model;
    QSqlTableModel *_model;
    QButtonGroup *buttongroup;


signals:
    void EmitToTeaManage();
};

#endif // TINFORMATION_H
