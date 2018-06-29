#include "TeacherManage.h"
#include "ui_TeacherManage.h"

TeacherManage::TeacherManage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TeacherManage)
{
    ui->setupUi(this);

    //设置教师管理界面背景
    QPalette p;
    p.setBrush(QPalette::Background,QBrush(QPixmap(":/loginbk1.jpg").scaled(this->size())));
    this->setPalette(p);

    //设置教师管理界面为固定大小
    this->setMaximumSize(822,583);
    this->setMinimumSize(822,583);

    //设置教师界面的标题
    this->setWindowTitle("教师界面");


    //设置工具栏名称
    ui->teachertool->setItemText(0,"教学资料");
    ui->teachertool->setItemText(1,"个人中心");

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
    automation = new TAutomation;
    automation->hide();
    connect(this,SIGNAL(toautomation(QString)),automation,SLOT(comeToTeacherManage(QString)));

    //创建通信窗口
    communication = new TCommunication;
    communication->hide();
    connect(this,SIGNAL(tocommunication(QString)),communication,SLOT(comeToTeacherManage(QString)));

    //创建电气工程及其自动化窗口
    electricalautomation = new TElectricalAutomation;
    electricalautomation->hide();
    connect(this,SIGNAL(toelectricalautomation(QString)),electricalautomation,SLOT(comeToTeacherManage(QString)));

    //创建电子信息与技术窗口
    electronictechnology = new TElectronicTechnology;
    electronictechnology->hide();
    connect(this,SIGNAL(toelectonictechnology(QString)),electronictechnology,SLOT(comeToTeacherManage(QString)));

    //创建信息工程窗口
    information = new TInformation;

    information->hide();
    connect(this,SIGNAL(toinfomation(QString)),information,SLOT(comeToTeacherManage(QString)));

    //个人信息管理
    //创建密码修改窗口
    teapassword=new TeaPassWord;
    teapassword->hide();
    connect(this,SIGNAL(tostupassword(QString)),teapassword,SLOT(comeTeacherManage(QString)));

    //各个功能窗口与studentmanage窗口的信号与槽连接
    connect(automation,SIGNAL(EmitToTeaManage()),this,SLOT(setbtnEnable()));
    connect(communication,SIGNAL(EmitToTeaManage()),this,SLOT(setbtnEnable()));
    connect(electricalautomation,SIGNAL(EmitToTeaManage()),this,SLOT(setbtnEnable()));
    connect(electronictechnology,SIGNAL(EmitToTeaManage()),this,SLOT(setbtnEnable()));
    connect(information,SIGNAL(EmitToTeaManage()),this,SLOT(setbtnEnable()));
    connect(teapassword,SIGNAL(EmitToTeaManage()),this,SLOT(setbtnEnable()));
}

TeacherManage::~TeacherManage()
{

    delete teapassword;
    delete automation;
    delete communication;
    delete electricalautomation;
    delete electronictechnology;
    delete information;
    delete ui;
}
void TeacherManage::btnsetfalse()
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

void TeacherManage::btnsettrue()
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

void TeacherManage::setbtnEnable()
{
    this->btnsettrue();
}

void TeacherManage::comeLoginDialog(QString name,QString num)
{
    teachername = name;
    id = num;
    ui->teachernameline->setText(teachername);
}

void TeacherManage::settimeline()
{
    QDateTime time=QDateTime::currentDateTime();
    QString str=time.toString("yyyy-MM-dd hh:mm:ss ddd");
    ui->timeline->setText(str);
}

void TeacherManage::on_autobtn_clicked()
{
    automation->show();
    emit toautomation(id);
    this->btnsetfalse();
}

void TeacherManage::on_elecautobtn_clicked()
{
    this->btnsetfalse();
    electricalautomation->show();
    emit toelectricalautomation(id);
}

void TeacherManage::on_inforbtn_clicked()
{
    this->btnsetfalse();
    information->show();
    emit toinfomation(id);
}

void TeacherManage::on_combtn_clicked()
{
    this->btnsetfalse();
    communication->show();
    emit tocommunication(id);
}

void TeacherManage::on_elecbtn_clicked()
{
    this->btnsetfalse();
    electronictechnology->show();
    emit toelectonictechnology(id);
}

void TeacherManage::on_passwordbtn_clicked()
{
    this->btnsetfalse();
    teapassword->show();
    emit tostupassword(id);
}

void TeacherManage::on_returnbtn_clicked()
{
    if(QMessageBox::question(this,"提示","是否注销用户?",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
    {
        emit toLoginDialog();
        delete this;
    }
}

void TeacherManage::on_exitbtn_clicked()
{
    if(QMessageBox::question(this,"提示","是否退出系统?",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
    {
        this->close();
        delete this;
    }
}
