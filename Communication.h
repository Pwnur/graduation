#ifndef COMMUNICATION_H
#define COMMUNICATION_H

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
class Communication;
}

class Communication : public QDialog
{
    Q_OBJECT

public:
    explicit Communication(QWidget *parent = 0);
    ~Communication();
    QString id;

private slots:
    void on_returnbtn_clicked();
    void comeStudentManage(QString);

    void on_searchbtn_clicked();

private:
    Ui::Communication *ui;
    QSqlTableModel *model;
    QSqlTableModel *_model;
    QButtonGroup *buttongroup;


signals:
    void EmitToStuManage();
};

#endif // COMMUNICATION_H
