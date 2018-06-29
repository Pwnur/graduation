#ifndef AUTOMATION_H
#define AUTOMATION_H

#include <QDialog>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QStringList>
#include <QDebug>
#include <QTableView>
#include <QButtonGroup>
namespace Ui {
class Automation;
}

class Automation : public QDialog
{
    Q_OBJECT

public:
    explicit Automation(QWidget *parent = 0);
    ~Automation();
    QString id;
private slots:
    void on_returnbtn_clicked();
    void comeStudentManage(QString);
    void on_searchbtn_clicked();

private:
    Ui::Automation *ui;
    QSqlTableModel *model;
    QSqlTableModel *_model;
    QButtonGroup *buttongroup;


signals:
    void EmitToStuManage();
};

#endif // AUTOMATION_H
