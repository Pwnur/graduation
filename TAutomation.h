#ifndef TAUTOMATION_H
#define TAUTOMATION_H

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
class TAutomation;
}

class TAutomation : public QDialog
{
    Q_OBJECT

public:
    explicit TAutomation(QWidget *parent = 0);
    ~TAutomation();
    QString id;
    bool judgeEmpty();

private slots:
    void on_searchbtn_clicked();

    void on_addbtn_clicked();

    void on_changebtn_clicked();

    void on_deletebtn_clicked();

    void on_returnbtn_clicked();

    void comeTeacherManage(QString);

    void ShowSupplyclick();
private:
    Ui::TAutomation *ui;
    QSqlTableModel *model;
    QSqlTableModel *_model;
    QButtonGroup *buttongroup;


signals:
    void EmitToTeaManage();
};

#endif // TAUTOMATION_H
