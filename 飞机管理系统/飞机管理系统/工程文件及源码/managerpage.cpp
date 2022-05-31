#include "managerpage.h"
#include "ui_managerpage.h"


ManagerPage::ManagerPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManagerPage)
{
    ui->setupUi(this);
    this->setWindowTitle("管理员界面(managerpage)");
    this->resize( QSize( 1000, 800));

    //连接信号与槽
    connect(&managerUser,&ManagerUser::managerUserClose,this,&ManagerPage::thisShow);
    connect(&managerFlights,&ManagerFlights::managerFlightsClose,this,&ManagerPage::thisShow);
    connect(&managerInfo,&ManagerInfo::managerInfoClose,this,&ManagerPage::thisShow);
}

ManagerPage::~ManagerPage()
{
    delete ui;
}



//打开订单管理界面
void ManagerPage::on_managerPageUser_clicked()
{
    this->hide();

    //传入管理员信息
    managerUser.id=id;
    managerUser.company=company;
    managerUser.show();
}


//打开航班管理界面
void ManagerPage::on_managerPageFlight_clicked()
{
    this->hide();

    //传入管理员信息
    managerFlights.company = company;
    managerFlights.initialize();
    managerFlights.show();
}


//打开管理员信息界面
void ManagerPage::on_managerPageInfo_clicked()
{
    this->hide();

    //传入管理员信息
    managerInfo.id=id;
    managerInfo.initialize();
    managerInfo.show();
}


//显示该界面
void ManagerPage::thisShow(){
    this->show();
}


//返回上一级
void ManagerPage::on_managerPageReturn_clicked()
{
    this->hide();
    emit closeManagerPage();
}
