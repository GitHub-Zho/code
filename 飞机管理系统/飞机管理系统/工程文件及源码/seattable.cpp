#include "seattable.h"
#include "ui_seattable.h"

SeatTable::SeatTable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SeatTable)
{
    ui->setupUi(this);
    this->setWindowTitle("座位表(seattable)");
    qModel = new QSqlQueryModel(ui->tableView);
}

SeatTable::~SeatTable()
{
    delete ui;
}


void SeatTable::initialize(){
    //连接数据库
    db = QSqlDatabase::database("mybase");

    //显示可选位置
    ui->tableView->setModel(qModel);
    sql=("select * from seattable where selled = 'No' ");
    qModel->setQuery(sql,db);

    //删去不可修改项
    qModel->removeColumn(1);
}


//获取所选座位
void SeatTable::on_seatTableChoose_clicked()
{

    //判断是否有进行选座
    if(ui->tableView->currentIndex().row() == -1)
    {
        QMessageBox::information(this,"infor","请选择座位");
    }
    else
    {
        curRec = qModel->record(ui->tableView->currentIndex().row());
        seat = curRec.value(0).toString();
        this->hide();
        emit chooseSeat(seat);
    }


}

//返回上一级
void SeatTable::on_seatTableReturn_clicked()
{
    this->hide();
    emit seatTableClose();
}
