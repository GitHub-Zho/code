#include "userticket.h"
#include "ui_userticket.h"

UserTicket::UserTicket(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserTicket)
{
    ui->setupUi(this);

    this->setWindowTitle("用户订单管理(userticket)");

    connect(&pay,&Pay::payCancle,this,&UserTicket::canclePay);
    connect(&pay,&Pay::payFinish,this,&UserTicket::finishPay);
    connect(&pay,&Pay::payClose,this,&UserTicket::thisShow);


}

UserTicket::~UserTicket()
{
    delete ui;
}

//显示该界面
void UserTicket::thisShow()
{
    this->show();
    sql = QString("select * from ticketselled where buyer = '%1' and pay ='Yes'").arg(id);
    qModel->setQuery(sql,db);

    //移除不可看信息
    qModel->removeColumn(2);
}


//界面初始化，显示数据
void UserTicket::initialize()
{
    this->resize( QSize( 1000, 800));
    db = QSqlDatabase::database("mybase");
    qModel = new QSqlQueryModel(ui->tableView);
    ui->tableView->setModel(qModel);

    sql = QString("select * from ticketselled where buyer = '%1' and pay ='Yes'").arg(id);
    qModel->setQuery(sql,db);

    //移除不可看信息
    qModel->removeColumn(2);


}


//返回上一级界面
void UserTicket::on_userTicketReturn_clicked()
{
    this->hide();
    emit userTicketClose();
}


//查看历史订单
void UserTicket::on_history_clicked()
{
    sql = QString("select * from ticketselled where buyer = '%1' and pay ='Yes'").arg(id);
    qModel->setQuery(sql,db);

    //移除不可看信息
    qModel->removeColumn(2);

}


//搜索对应航班号订单
void UserTicket::on_userTicketSearch_clicked()
{
    sql = QString("select * from ticketselled where buyer = '%1' and num ='%2' and pay = 'Yes'")\
            .arg(id).arg(ui->userTicketFlight->text());
    qModel->setQuery(sql,db);
}


//查看未支付订单
void UserTicket::on_unPay_clicked()
{
    sql = QString("select * from ticketselled where buyer = '%1' and pay ='No'").arg(id);
    qModel->setQuery(sql,db);

    //移除不可看信息
    qModel->removeColumn(2);
    qModel->removeColumn(3);
    qModel->removeColumn(3);
}


//选择未支付订单并进入支付界面
void UserTicket::on_buy_clicked()
{

    QSqlQuery query(db);
    //获取今日购票信息
    sql = QString("select * from ticketselled where pay = 'Yes' and buydate = '%1' and buyer = '%2' ")\
            .arg(date.currentDate().toString("yyyy-MM-dd")).arg(id);
    query.exec(sql);
    restTicket = 5-query.size();

    sModel = ui->tableView->selectionModel();
    list = sModel->selectedRows();

    //提示可一单多选
    box.information(this,"infor",QString("今日购票数剩余%1\n此单所选机票数为%2\n(请点击最左端序号选择一整栏,\n可按住Ctri多选)").arg(restTicket).arg(list.size()));

    //获取选中订单
    if(list.size() == 0)
    {
        box.information(this,"infor","请选择所需支付订单\n(请点击最左端序号选择一整栏,\n可按住Ctri多选)");
    }
    else
    {
        //每一条信息获取
        for(int i=0;i<list.size();i++)
        {
            curRec = qModel->record(list.at(i).row());
            qDebug()<<list<<curRec;

            if(curRec.value(4).toString()=="Yes")
            {
                box.information(this,"infor","请选择未支付订单支付");
                return;
            }
            else
            {
                pay.show();
//                传参进入支付界面
//                pay.initialize(flight,query.value(3).toString(),query.value(4).toString(),\
//                               query.value(5).toDateTime().toString("yyyy-MM-dd hh:mm:ss"),\
//                               query.value(6).toDateTime().toString("yyyy-MM-dd hh:mm:ss"),seatPrice,buyerName);


            }
        }
    }

}

//完成支付将状态设为支付并将机票价格增加对应票价
void UserTicket::finishPay()
{
    QSqlQuery query(db);

    if(list.size()>restTicket)
    {
        //判断是否超过五张
        box.information(this,"infor","超出今日限购");
        return;
    }

    for(int i=0;i<list.size();i++)
    {

        curRec = qModel->record(list.at(i).row());

        //获取所需参数
        flight=curRec.value(0).toString();
        seatType =curRec.value(3).toString();
        seatPrice = curRec.value(4).toString();
        buyerName =curRec.value(5).toString();
        if(seatType =="头等舱") seatTypeIndex ="1";
        else if(seatType =="经济舱") seatTypeIndex ="3";
        else seatTypeIndex ="2";

    //    sql = QString("select * from flight where number ='%1'").arg(flight);
    //    query.exec(sql);
    //    query.first();

        //购买成功更新数据库
        sql = QString("update ticketselled set pay = 'Yes', buydate = '%1' \
                where buyer = '%2' and pay ='No' and num='%3' and seattype ='%4' and buyername ='%5'")\
                .arg(date.currentDate().toString("yyyy-MM-dd")).arg(id).arg(flight).arg(seatType).arg(buyerName);
        query.exec(sql);

        sql = QString("update flight set sumprice = sumprice + %1 where number ='%2'").arg(seatPrice).arg(flight);
        query.exec(sql);
    }
    //显示更新后数据库
    sql = QString("select * from ticketselled where buyer = '%1' and pay ='Yes'").arg(id);
    qModel->setQuery(sql,db);

    box.information(this,"infor","购买成功");

//    //判断一日购买不超过5
//    sql = QString("select * from ticketselled where pay = 'Yes' and buydate = '%1' and buyer = '%2' ")\
//            .arg(date.currentDate().toString("yyyy-MM-dd")).arg(id);
//    query.exec(sql);
//    if(query.size() >5)
//    {
//        //若超过5不允许购买
//        box.information(this,"infor","超过5张机票购买上限\n无法继续购买");
//        //更新数据库
//        sql = QString("update ticketselled set pay = 'No', buydate = '%1' \
//                where buyer = '%2' and pay ='Yes' and num='%3' and seattype ='%4'")\
//                .arg(date.currentDate().toString("yyyy-MM-dd")).arg(id).arg(flight).arg(seatType);
//        query.exec(sql);

//    }
//    else
//    {


//    }
}


//删除未支付订单并将对应舱位数+1,总售票-1
void UserTicket::canclePay()
{
    QSqlQuery query(db);

    for(int i=0;i<list.size();i++)
    {
        curRec = qModel->record(list.at(i).row());

        //获取所需参数
        flight=curRec.value(0).toString();
        seatType =curRec.value(3).toString();
        seatPrice = curRec.value(4).toString();
        buyerName =curRec.value(5).toString();
        if(seatType =="头等舱") seatTypeIndex ="1";
        else if(seatType =="经济舱") seatTypeIndex ="3";
        else seatTypeIndex ="2";

    //    sql = QString("select * from flight where number ='%1'").arg(flight);
    //    query.exec(sql);
    //    query.first();

        sql = QString("delete from ticketselled where buyer = '%1'\
                      and pay ='No' and num='%2' and seattype ='%3' and buyername ='%4'")\
                .arg(id).arg(flight).arg(seatType).arg(buyerName);
        query.exec(sql);

        sql = QString("update flight set %1 = %1 + 1 , ticketselled = ticketselled - 1,\
                      onseatrate = ticketselled/(seat1+seat2+seat3) where number ='%2'")\
                .arg("seat"+seatTypeIndex+"rest").arg(flight);
        query.exec(sql);
    }

    //显示更新后数据库
    sql = QString("select * from ticketselled where buyer = '%1' and pay ='No'").arg(id);
    qModel->setQuery(sql,db);

    //移除不可看信息
    qModel->removeColumn(2);
    qModel->removeColumn(3);
    qModel->removeColumn(3);

    box.information(this,"infor","删除订单成功");
}


