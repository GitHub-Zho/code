#include "managerflight.h"
#include "ui_managerflight.h"
#include<QSqlQuery>

ManagerFlight::ManagerFlight(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManagerFlight)
{
    ui->setupUi(this);
    this->resize( QSize( 1000, 800));
    connect(&managerFlightAdd,&ManagerFlightAdd::managerFlightAddClose,this,&ManagerFlight::thisShow);
}

ManagerFlight::~ManagerFlight()
{
    delete ui;
}

//void ManagerFlight::managerFlightClose(){

//}

void ManagerFlight::thisShow(){
    this->show();
}



void ManagerFlight::on_managerFlightReturn_clicked()
{
    this->hide();
    emit managerFlightClose();
}
void ManagerFlight::getFlight(QSqlQuery query){

}

void ManagerFlight::on_flightAlready_clicked()
{

}

void ManagerFlight::on_managerFlightFind_clicked()
{

}

void ManagerFlight::on_managerFlightDelete_clicked()
{

}
