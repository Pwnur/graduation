#include "TInformation.h"
#include "ui_TInformation.h"

TInformation::TInformation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TInformation)
{
    ui->setupUi(this);

    //设置界面背景
    QPalette p;
    p.setBrush(QPalette::Background,QBrush(QPixmap(":/loginbk1.jpg").scaled(this->size())));
    this->setPalette(p);

    //创建model实现与数据库的交互
    model = new QSqlTableModel(this);
    model->setTable("automation");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setHeaderData(0,Qt::Horizontal,tr("编号"));
    model->setHeaderData(1,Qt::Horizontal,tr("书名"));
    model->setHeaderData(2,Qt::Horizontal,tr("数量"));
    model->setHeaderData(3,Qt::Horizontal,tr("链接地址"));
    model->setHeaderData(4,Qt::Horizontal,tr("备注"));
    model->removeColumns(5,5);

    //设置view列宽适应单元格内容
    ui->automationview->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    //创建_model实现查询功能
    _model=new QSqlTableModel(this);
    _model->setTable("automation");
    _model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    _model->setHeaderData(0,Qt::Horizontal,"编号");
    _model->setHeaderData(1,Qt::Horizontal,"书名");
    _model->setHeaderData(2,Qt::Horizontal,"数量");
    _model->setHeaderData(3,Qt::Horizontal,"链接地址");
    model->setHeaderData(4,Qt::Horizontal,tr("备注"));
    _model->removeColumns(5,5);

    //鼠标信号
    connect(ui->automationview,SIGNAL(clicked(QModelIndex)),this,SLOT(ShowSupplyclick()));
}

TInformation::~TInformation()
{
    delete ui;
}

bool TInformation::judgeEmpty()
{
    if(ui->idline->text().isEmpty())
    {
        QMessageBox::warning(this,"警告","编号不能为空",QMessageBox::Yes);
        return false;
    }
    else if(ui->nameline->text().isEmpty())
    {
        QMessageBox::warning(this,"警告","书名不能为空",QMessageBox::Yes);
        return false;
    }
    else if(ui->numberline->text().isEmpty())
    {
        QMessageBox::warning(this,"警告","数量不能为空",QMessageBox::Yes);
        return false;
    }
    else
        return true;
}

void TInformation::ShowSupplyclick()
{
    static QSqlQueryModel supplymodel(ui->automationview);
    supplymodel.setQuery(QString("select * from automation;"));
    int row = ui->automationview->currentIndex().row();
    QSqlRecord record = supplymodel.record(row);
    ui->idline->setText(record.value(0).toString());
    ui->nameline->setText(record.value(1).toString());
    ui->numberline->setText(record.value(2).toString());
    ui->adressline->setText(record.value(3).toString());
    ui->remarkline->setText(record.value(4).toString());
}

void TInformation::comeTeacherManage(QString num)
{

    model->select();
    if(model->data(model->index(0,0)).toString().isEmpty())
    {
        QMessageBox::information(this,"提示","该专业暂无教学资料",QMessageBox::Yes);
        this->hide();
        return;
    }
    ui->automationview->setModel(model);
}

void TInformation::on_searchbtn_clicked()
{
    if(ui->idline->text().isEmpty()!= 1)
    {
        _model->setFilter("id='"+ui->idline->text()+"'");
        _model->select();
        if(_model->data(model->index(0,0)).toString().isEmpty())
        {
            QMessageBox::warning(this,"警告","请去确认编号是否正确");
            ui->automationview->setModel(model);
            return;
        }
        ui->automationview->setModel(_model);
    }
    else if(ui->nameline->text().isEmpty()!= 1)
    {
        _model->setFilter("name='"+ui->nameline->text()+"'");
        _model->select();
        if(_model->data(model->index(0,0)).toString().isEmpty())
        {
            QMessageBox::warning(this,"警告","请去确认书名是否正确");
            ui->automationview->setModel(model);
            return;
        }
        ui->automationview->setModel(_model);
    }
    else if((ui->nameline->text().isEmpty()!= 1) && (ui->idline->text().isEmpty()!= 1))
    {
        _model->setFilter("name='"+ui->nameline->text()+"id='"+ui->idline->text()+"'");
        _model->select();
        if(_model->data(model->index(0,0)).toString().isEmpty())
        {
            QMessageBox::warning(this,"警告","请去确认编号和书名是否正确");
            ui->automationview->setModel(model);
            return;
        }
        ui->automationview->setModel(_model);
    }
    else
    {
        model->select();
        if(model->data(model->index(0,0)).toString().isEmpty())
        {
            QMessageBox::information(this,"提示","该专业暂无教学资料",QMessageBox::Yes);
            this->hide();
            return;
        }
        ui->automationview->setModel(model);
     }
}

void TInformation::on_addbtn_clicked()
{
    if(!this->judgeEmpty())
        return;
    _model->select();
    int i;
    for(i=0;i<_model->rowCount();i++)
    {
        if(_model->data(_model->index(i,0)).toString()==ui->idline->text())
        {
            break;
        }
    }
    if(i!=_model->rowCount())
    {
        QMessageBox::information(this,"提示","该资料已经存在",QMessageBox::Yes);
        return;
    }
    QSqlRecord record=_model->record();
    record.setValue("id",ui->idline->text());
    record.setValue("name",ui->nameline->text());
    record.setValue("num",ui->numberline->text().toFloat());
    record.setValue("adress",ui->adressline->text().toFloat());
    record.setValue("remake",ui->remarkline->text().toFloat());
    _model->insertRecord(-1,record);
    if(_model->submitAll())
    {
        QMessageBox::information(this,"提示","教学资料添加成功",QMessageBox::Yes);
    }

    model->select();
    if(model->data(model->index(0,0)).toString().isEmpty())
    {
        QMessageBox::information(this,"提示","该专业暂无教学资料",QMessageBox::Yes);
        this->hide();
        return;
    }
    ui->automationview->setModel(model);
}

void TInformation::on_changebtn_clicked()
{
    if(model->submitAll())
        QMessageBox::information(this,"提示","修改成功",QMessageBox::Yes);
    else
    {
        QMessageBox::information(this,"提示","修改失败",QMessageBox::Yes);
        model->revertAll();
    }

    model->select();
    if(model->data(model->index(0,0)).toString().isEmpty())
    {
        QMessageBox::information(this,"提示","该专业暂无教学资料",QMessageBox::Yes);
        this->hide();
        return;
    }
    ui->automationview->setModel(model);
}

void TInformation::on_deletebtn_clicked()
{
    if((ui->idline->text().isEmpty())&&(ui->nameline->text().isEmpty()))
    {
        QMessageBox::warning(this,"警告","请输入编号和书名不能同时为空");
        return;
    }

    if(ui->idline->text().isEmpty()!= 1)
    {
        _model->select();
        int i;
        for(i=0;i<_model->rowCount();i++)
        {
            if(_model->data(_model->index(i,0)).toString()==ui->idline->text())
            {
                if(QMessageBox::question(this,"提示","确定要删除吗？",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
                {
                    _model->removeRow(i);
                    _model->submitAll();
                    return ;
                }
                else
                    return ;
            }
        }
        QMessageBox::information(this,"提示","教学资料不存在，删除失败!");
    }
    else if(ui->nameline->text().isEmpty()!= 1)
    {
        _model->select();
        int i;
        for(i=0;i<_model->rowCount();i++)
        {
            if(_model->data(_model->index(i,1)).toString()==ui->nameline->text())
            {
                if(QMessageBox::question(this,"提示","确定要删除吗？",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
                {
                    model->removeRow(i);
                    model->submitAll();
                    return;
                }
                else
                    return;
            }
        }
        QMessageBox::information(this,"提示","教学资料不存在，删除失败!");
    }
}

void TInformation::on_returnbtn_clicked()
{
    this->hide();
    emit EmitToTeaManage();
}
