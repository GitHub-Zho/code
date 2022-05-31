#include "managerinfo.h"
#include "ui_managerinfo.h"


ManagerInfo::ManagerInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManagerInfo)
{
    ui->setupUi(this);
    this->setWindowTitle("管理员信息(managerinfo)");
    db = QSqlDatabase::database("mybase");
}

ManagerInfo::~ManagerInfo()
{
    delete ui;
}


//界面初始化
void ManagerInfo::initialize()
{
    this->resize( QSize( 1000, 800));

    //设置只读选项
    ui->idEdit->setReadOnly(true);
    ui->companyEdit->setReadOnly(true);
    ui->nameEdit->setReadOnly(true);

    //数据库获取参数
    QSqlQuery query(db);
    QString sql = QString("select * from managers where id = '%1'").arg(id);
    query.exec(sql);
    query.first();

    //显示信息
    ui->idEdit->setText(query.value(0).toString()) ;
    ui->companyEdit->setText(query.value(1).toString());
    ui->nameEdit->setText(query.value(2).toString());
    ui->mailEdit->setText(query.value(3).toString());
    ui->passwordEdit->setText(query.value(4).toString());
}


//修改信息
void ManagerInfo::on_managerInfoChange_clicked()
{
    QSqlQuery query(db);
    QString mail=ui->mailEdit->text();
    QString password=ui->passwordEdit->text();

    //正则表达式匹配邮箱
    QRegExp rx("^[a-z0-9]+([._-]*[a-z0-9])*@([a-z0-9]+[-a-z0-9]*[a-z0-9]+.){1,63}[a-z0-9]+$");
    if(rx.exactMatch(mail)){
        QString sql = QString("update managers set mailbox = '%1' , password = '%2' where id = '%3'")\
                .arg(mail).arg(password).arg(id);
        if(query.exec(sql)) box.information(this,"infor","修改成功");
        else box.information(this,"infor","修改失败");
    }
    else box.information(this,"infor","邮箱格式有误");
}


//返回上一级
void ManagerInfo::on_managerInfoReturn_clicked()
{
    this->hide();
    emit managerInfoClose();
}
