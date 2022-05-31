#include "userinfo.h"
#include "ui_userinfo.h"

UserInfo::UserInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserInfo)
{
    ui->setupUi(this);
    this->setWindowTitle("用户信息(userinfo)");

}

UserInfo::~UserInfo()
{
    delete ui;

}

//用户信息界面初始化
void UserInfo::initialize()
{
    this->resize( QSize( 1000, 800));
    db = QSqlDatabase::database("mybase");

    //设置只读不可修改项
    ui->idEdit_2->setReadOnly(true);
    ui->sexEdit->setReadOnly(true);
    ui->nameEdit_2->setReadOnly(true);
    ui->phoneEdit->setReadOnly(true);

    //数据库获取参数
    QSqlQuery query(db);
    QString sql = QString("select * from users where id = '%1'").arg(id);
    qDebug()<< id  <<"userinfoini"<< sql;
    query.exec(sql);
    query.first();

    //显示用户信息
    ui->idEdit_2->setText(query.value(0).toString()) ;
    ui->nameEdit_2->setText(query.value(1).toString());
    ui->sexEdit->setText(query.value(2).toString());
    ui->phoneEdit->setText(query.value(3).toString());
    ui->passwordEdit_2->setText(query.value(4).toString());
    ui->mailEdit_2->setText(query.value(5).toString());

}


//按下修改按钮进行用户信息修改
void UserInfo::on_userInfoChange_clicked()
{
    QSqlQuery query(db);

    //正则表达式匹配邮箱，若符合格式则进行修改保存
    QString password=ui->passwordEdit_2->text();
    QString mail=ui->mailEdit_2->text();
    QRegExp rx("^[a-z0-9]+([._-]*[a-z0-9])*@([a-z0-9]+[-a-z0-9]*[a-z0-9]+.){1,63}[a-z0-9]+$");
    if(rx.exactMatch(mail))
    {
        QString sql = QString("update users set mailbox = '%1' , password = '%2' where id = '%3'")\
                .arg(mail).arg(password).arg(id);

        //告知用户是否成功修改
        if(query.exec(sql)) box.information(this,"infor","修改成功");
        else box.information(this,"infor","修改失败");
    }
    else box.information(this,"infor","邮箱格式有误");
}


//返回上一级页面，发送关闭信号
void UserInfo::on_userInfoReturn_clicked()
{
    this->hide();
    emit userInfoClose();
}

