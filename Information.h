#ifndef INFORMATION_H
#define INFORMATION_H

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
class Information;
}

class Information : public QDialog
{
    Q_OBJECT

public:
    explicit Information(QWidget *parent = 0);
    ~Information();
    QString id;

private slots:
    void on_returnbtn_clicked();
    void comeStudentManage(QString);

    void on_searchbtn_clicked();

private:
    Ui::Information *ui;
    QSqlTableModel *model;
    QSqlTableModel *_model;
    QButtonGroup *buttongroup;

signals:
    void EmitToStuManage();
};

#endif // INFORMATION_H
