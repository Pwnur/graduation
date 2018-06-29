#include "StudentManage.h"
#include "ui_StudentManage.h"

StudentManage::StudentManage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentManage)
{
    ui->setupUi(this);

    //设置学生成绩管理界面背景
    QPalette p;
    p.setBrush(QPalette::Background,QBrush(QPixmap(":/loginbk1.jpg").scaled(this->size())));
    this->setPalette(p);

    //设置学生成绩管理界面为固定大小
    this->setMaximumSize(822,583);
    this->setMinimumSize(822,583);

    //设置学生界面的标题
    this->setWindowTitle("学生界面");


    //设置工具栏名称
    ui->studenttool->setItemText(0,"教学资料");
    ui->studenttool->setItemText(1,"个人中心");

    QDateTime time=QDateTime::currentDateTime();
    QString str=time.toString("yyyy-MM-dd hh:mm:ss ddd");
    ui->timeline->setText(str);
    //设置定时器
    timelinetimer=new QTimer(this);
    timelinetimer->setInterval(100);
    timelinetimer->start();
    connect(timelinetimer,SIGNAL(timeout()),this,SLOT(settimeline()));

    //教学资料查询
    //创建自动化窗口
    automation = new Automation;
//    ui->studentstack->addWidget(automation);
    automation->hide();
    connect(this,SIGNAL(toautomation(QString)),automation,SLOT(comeStudentManage(QString)));
    connect(ui->autobtn,SIGNAL(clicked()),this,SLOT(autoSlot()));
    //创建通信窗口
    communication = new Communication;
//    ui->studentstack->addWidget(communication);
    communication->hide();
    connect(this,SIGNAL(tocommunication(QString)),communication,SLOT(comeStudentManage(QString)));
    connect(ui->combtn,SIGNAL(clicked()),this,SLOT(combtnSlot()));
    //创建电气工程及其自动化窗口
    electricalautomation = new ElectricalAutomation;
//    ui->studentstack->addWidget(electricalautomation);
    electricalautomation->hide();
    connect(this,SIGNAL(toelectricalautomation(QString)),electricalautomation,SLOT(comeStudentManage(QString)));
    connect(ui->elecautobtn,SIGNAL(clicked()),this,SLOT(elecautobtnSlot()));
    //创建电子信息与技术窗口
    electronictechnology = new ElectronicTechnology;
//    ui->studentstack->addWidget(electronictechnology);
    electronictechnology->hide();
    connect(this,SIGNAL(toelectonictechnology(QString)),electronictechnology,SLOT(comeStudentManage(QString)));
    connect(ui->elecbtn,SIGNAL(clicked()),this,SLOT(elecbtnSlot()));
    //创建信息工程窗口
    information = new Information;
//    ui->studentstack->addWidget(information);
    information->hide();
    connect(this,SIGNAL(toinfomation(QString)),information,SLOT(comeStudentManage(QString)));
    connect(ui->inforbtn,SIGNAL(clicked()),this,SLOT(inforbtnSlot()));
    //个人信息管理
    //创建密码修改窗口
    stupassword=new StuPassWord;
//    ui->studentstack->addWidget(stupassword);
    stupassword->hide();    
    connect(this,SIGNAL(tostupassword(QString)),stupassword,SLOT(comeStudentManage(QString)));
    connect(ui->passwordbtn,SIGNAL(clicked()),this,SLOT(passwordbtnSlot()));
    //退出系统按钮信号与槽连接
    connect(ui->exitbtn,SIGNAL(clicked()),this,SLOT(exitbtnSlot()));
    //注销用户按钮信号与槽连接
    connect(ui->returnbtn,SIGNAL(clicked()),this,SLOT(returnbtnSlot()));

    //各个功能窗口与studentmanage窗口的信号与槽连接
    connect(automation,SIGNAL(EmitToStuManage()),this,SLOT(setbtnEnable()));
    connect(communication,SIGNAL(EmitToStuManage()),this,SLOT(setbtnEnable()));
    connect(electricalautomation,SIGNAL(EmitToStuManage()),this,SLOT(setbtnEnable()));
    connect(electronictechnology,SIGNAL(EmitToStuManage()),this,SLOT(setbtnEnable()));
    connect(information,SIGNAL(EmitToStuManage()),this,SLOT(setbtnEnable()));
    connect(stupassword,SIGNAL(EmitToStuManage()),this,SLOT(setbtnEnable()));

}

StudentManage::~StudentManage()
{
    delete stupassword;
    delete automation;
    delete communication;
    delete electricalautomation;
    delete electronictechnology;
    delete information;
    delete ui;
}

void StudentManage::comeLoginDialog(QString name,QString num)
{
    studentname = name;
    id = num;
    ui->studentnameline->setText(studentname);
}

void StudentManage::settimeline()
{
    QDateTime time=QDateTime::currentDateTime();
    QString str=time.toString("yyyy-MM-dd hh:mm:ss ddd");
    ui->timeline->setText(str);
}

void StudentManage::exitbtnSlot()
{
    if(QMessageBox::question(this,"提示","是否退出系统?",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
    {
    this->close();
    delete this;
    }
}
void StudentManage::btnsetfalse()
{
    ui->autobtn->setEnabled(false);
    ui->combtn->setEnabled(false);
    ui->inforbtn->setEnabled(false);
    ui->elecautobtn->setEnabled(false);
    ui->elecbtn->setEnabled(false);

    ui->passwordbtn->setEnabled(false);
    ui->exitbtn->setEnabled(false);
    ui->returnbtn->setEnabled(false);
}
void StudentManage::btnsettrue()
{
    ui->autobtn->setEnabled(true);
    ui->combtn->setEnabled(true);
    ui->inforbtn->setEnabled(true);
    ui->elecautobtn->setEnabled(true);
    ui->elecbtn->setEnabled(true);

    ui->exitbtn->setEnabled(true);
    ui->passwordbtn->setEnabled(true);
    ui->returnbtn->setEnabled(true);
}
void StudentManage::setbtnEnable()
{
 this->btnsettrue();
}

void StudentManage::returnbtnSlot()
{
    if(QMessageBox::question(this,"提示","是否注销用户?",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
    {
    emit toLoginDialog();
    delete this;
    }
}

void StudentManage::autoSlot()
{
    automation->show();
//    ui->studentstack->setCurrentIndex(0);
    emit toautomation(id);
    this->btnsetfalse();
}
void StudentManage::combtnSlot()
{
    this->btnsetfalse();
    communication->show();
//    ui->studentstack->setCurrentIndex(2);
    emit tocommunication(id);

}
void StudentManage::elecautobtnSlot()
{
    this->btnsetfalse();
    electricalautomation->show();
//   ui->studentstack->setCurrentIndex(1);
    emit toelectricalautomation(id);

}
void StudentManage::elecbtnSlot()
{
    this->btnsetfalse();
    electronictechnology->show();
//    ui->studentstack->setCurrentIndex(3);
    emit toelectonictechnology(id);

}

void StudentManage::inforbtnSlot()
{
    this->btnsetfalse();
    information->show();
//    ui->studentstack->setCurrentIndex(4);
    emit toinfomation(id);

}

void StudentManage::passwordbtnSlot()
{
    this->btnsetfalse();
    stupassword->show();
//    ui->studentstack->setCurrentIndex(5);
    emit tostupassword(id);

}
