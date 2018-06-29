#include "Logindialog.h"
#include <QApplication>
#include <QIcon>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //设置app的图标
    a.setWindowIcon(QIcon("school.ico"));
    //连接mysql数据库
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPort(3306);
    db.setPassword("123456");
    db.setDatabaseName("school");
    if(db.open())
    {
    LoginDialog w;
    w.show();
    return a.exec();
    }
    else
    {
        QMessageBox::information(NULL,"提示","系统载入数据库失败，无法运行",QMessageBox::Yes);
    }
    return 0;
}
