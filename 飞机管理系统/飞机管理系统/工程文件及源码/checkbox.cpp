#include "checkbox.h"
#include "ui_checkbox.h"

QSqlDatabase db;
CheckBox::CheckBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CheckBox)
{
    ui->setupUi(this);
    this->setWindowTitle("登录(checkbox)");
    db = QSqlDatabase::database("mybase");
    qDebug()<<"okcon";

}

CheckBox::~CheckBox()
{
    delete ui;
}

//判断用户名密码是否匹配
void CheckBox::on_admitButton_clicked()
{

    QSqlQuery query(db);
    QString id = ui->idEdit->toPlainText();
    QString password = ui->passwordEdit->toPlainText();

    //判断是用户登录还是管理员登录
    QString typeThis ="users";
    if(type){
        typeThis= "managers";
    }

    //获取数据库信息
    QString sql = QString("select * from %1 where id = '%2'").arg(typeThis).arg(id);
    qDebug() << sql;
    query.exec(sql);
    query.first();

    //判断账号密码是否正确
    if(query.value(4).toString() == password)
    {
        if(type)
            emit successManager(query.value(0).toString(),query.value(1).toString());
        else
            emit successUser(query.value(0).toString(),query.value(1).toString());
    }
    else QMessageBox::information(this,"infor","用户名或密码错误\n请重新输入");

}

//关闭消息框
void CheckBox::on_returnButton_clicked()
{
    this->hide();
}
