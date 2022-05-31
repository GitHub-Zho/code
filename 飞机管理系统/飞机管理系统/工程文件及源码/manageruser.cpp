#include "manageruser.h"
#include "ui_manageruser.h"

ManagerUser::ManagerUser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManagerUser)
{
    ui->setupUi(this);
    this->setWindowTitle("订单管理(manageruser)");
    this->resize( QSize( 1000, 800));

    //连接数据库并设置只读和修改两种表
    db = QSqlDatabase::database("mybase");
    model =new QSqlTableModel(this,db);
    query = new QSqlQueryModel(ui->tableView);

    //显示只读已飞航班
    ui->tableView->setModel(query);

    //获取当日时间，用于判断飞机是否起飞
    curDateTime =QDateTime::currentDateTime();   
}

ManagerUser::~ManagerUser()
{
    delete ui;
}


//显示该公司所有订单
void ManagerUser::on_managerUserTicket_clicked()
{
    QString sql = QString("select * from ticketselled where company = '%1'").arg(company);
    query->setQuery(sql,db);
}


//显示未飞航班
void ManagerUser::on_managerUserSet_clicked()
{
    //获取当日时间，用于判断飞机是否起飞
    QString curtime= QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

    QString sql = QString("select * from flight where company = '%1' and starttime > '%2' order by ticketselled desc")\
            .arg(company).arg(curtime);
    query->setQuery(sql,db);
}


//已起飞航班按上座率排序
void ManagerUser::on_managerUserOff_clicked()
{
    //获取当日时间，用于判断飞机是否起飞
    QString curtime= QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

    QString sql = QString("select * from flight where  starttime < '%1' order by onseatrate desc").arg(curtime);
    query->setQuery(sql,db);
}


//已飞航班进行总售价排序
void ManagerUser::on_managerUserPrice_clicked()
{
    //获取当日时间，用于判断飞机是否起飞
    QString curtime= QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

    QString sql = QString("select * from flight where starttime < '%1' order by sumprice desc").arg(curtime);
    query->setQuery(sql,db);
}


//返回上一级
void ManagerUser::on_managerUserReturn_clicked()
{
    this->hide();
    emit managerUserClose();
}
