#ifndef ELECTRICALAUTOMATION_H
#define ELECTRICALAUTOMATION_H

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
class ElectricalAutomation;
}

class ElectricalAutomation : public QDialog
{
    Q_OBJECT

public:
    explicit ElectricalAutomation(QWidget *parent = 0);
    ~ElectricalAutomation();
    QString id;

private slots:
    void on_returnbtn_clicked();
    void comeStudentManage(QString);

    void on_searchbtn_clicked();

private:
    Ui::ElectricalAutomation *ui;
    QSqlTableModel *model;
    QSqlTableModel *_model;
    QButtonGroup *buttongroup;

signals:
    void EmitToStuManage();
};

#endif // ELECTRICALAUTOMATION_H
