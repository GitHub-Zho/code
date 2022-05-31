#include "pay.h"
#include "ui_pay.h"

Pay::Pay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Pay)
{
    ui->setupUi(this);
    this->setWindowTitle("支付(pay)");

    //设置窗口位置居中
    QDesktopWidget *desktop = QApplication::desktop();
}

Pay::~Pay()
{
    delete ui;
}



//返回上一级
void Pay::on_payReturn_clicked()
{
    this->hide();
    emit payClose();

}


//发送完成支付信号给上一级
void Pay::on_pay_clicked()
{
    this->hide();
    emit payFinish();
}


//发送不支付，取消订单信号给上一级
void Pay::on_cancle_clicked()
{
    this->hide();
    emit payCancle();
}
