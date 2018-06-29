#ifndef ELECTRONICTECHNOLOGY_H
#define ELECTRONICTECHNOLOGY_H

#include <QDialog>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QDebug>
#include <QStringList>
#include <QDebug>
#include <QTableView>
#include <QButtonGroup>
namespace Ui {
class ElectronicTechnology;
}

class ElectronicTechnology : public QDialog
{
    Q_OBJECT

public:
    explicit ElectronicTechnology(QWidget *parent = 0);
    ~ElectronicTechnology();
    QString id;

private slots:
    void on_returnbtn_clicked();
    void comeStudentManage(QString);

    void on_searchbtn_clicked();

private:
    Ui::ElectronicTechnology *ui;
    QSqlTableModel *model;
    QSqlTableModel *_model;
    QButtonGroup *buttongroup;

signals:
    void EmitToStuManage();
};

#endif // ELECTRONICTECHNOLOGY_H
