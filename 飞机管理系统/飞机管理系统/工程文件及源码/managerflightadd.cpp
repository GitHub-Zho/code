#include "managerflightadd.h"
#include "ui_managerflightadd.h"
#include<QDebug>



ManagerFlightAdd::ManagerFlightAdd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManagerFlightAdd)
{
    ui->setupUi(this);
    db = QSqlDatabase::database("mybase");
}

ManagerFlightAdd::~ManagerFlightAdd()
{
    delete ui;
}


void ManagerFlightAdd::on_return_2_clicked()
{
    this->hide();
    emit managerFlightAddClose();
}

