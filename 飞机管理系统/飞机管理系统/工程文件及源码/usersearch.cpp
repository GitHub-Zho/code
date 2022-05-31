#include "usersearch.h"
#include "ui_usersearch.h"

UserSearch::UserSearch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserSearch)
{
    ui->setupUi(this);

    this->setWindowTitle("用户界面(usersearch)");

    connect(&userTicket,&UserTicket::userTicketClose,this,&UserSearch::thisShow);
    connect(&userInfo,&UserInfo::userInfoClose,this,&UserSearch::thisShow);
    connect(&seatTable,&SeatTable::chooseSeat,this,&UserSearch::getSeat);
    connect(&seatTable,&SeatTable::seatTableClose,this,&UserSearch::thisShow);

    //    ui->tableView->setModel(model);


}
UserSearch::~UserSearch()
{
    delete ui;
}


//显示这个界面
void UserSearch::thisShow()
{
    this->show();
}


//初始化界面，显示所需信息
void UserSearch::initialize()
{
    this->resize( QSize( 1000, 800));

    //连接数据库并显示初始数据
    db = QSqlDatabase::database("mybase");
    query = QSqlQuery(db);
    qModel = new QSqlQueryModel(ui->tableView);
    ui->tableView->setModel(qModel);
    QString sql = QString("select * from flight where setoff = 'true'");
    qModel->setQuery(sql,db);
    qModel->removeColumn(23);

    //设置初始选择为经济舱
    seatRest = "seat3rest";
    seatName = "经济舱";
    seatIndex=19;
}


//进入用户信息界面
void UserSearch::on_userInfo_clicked()
{
    this->hide();
    userInfo.id=id;
    userInfo.initialize();
    userInfo.show();
}


//用户界面中根据输入条件查询
void UserSearch::on_userSearch_clicked()
{
    buyerName = ui->buyer->text();
    if(buyerName == NULL){
        box.information(this,"infor","请输入乘机人姓名");
        return;
    }

    //获取所有搜索栏信息
    search =true;
    flightId = ui->id->text();
    startPlace=ui->startPlace->text();
    endPlace=ui->endPlace->text();
    startDate = ui->startTime->date().toString("yyyy-MM-dd");
    company=ui->company->text();
    planeType=ui->type->text();
    seatType=ui->seatType->currentIndex();
    startTime = startDate+" 00:00:00";
    endTime = startDate+" 23:59:59";

    //若某一搜索栏非空则加入对应搜索条件
    sql="select * from flight where setoff = 'true' ";

    if(flightId.isEmpty() == false)
    {
        sql +=QString("and number = '%1' ").arg(flightId);
        qDebug() << flightId;
    }

    if(company.isEmpty() == false)
    {
        sql +=QString("and company = '%1' ").arg(company);
        qDebug() << ui->company->text();
    }

    if(planeType.isEmpty() == false)
    {
        sql +=QString("and planetype = '%1' ").arg(planeType);
        qDebug() << planeType;
    }

    if(startPlace.isEmpty() == false)
    {
        sql += QString("and startplace = '%1' ").arg(startPlace);
        qDebug() << ui->startPlace->text();
    }

    if(endPlace.isEmpty() == false)
    {
        sql +=QString("and endplace = '%1' ").arg(endPlace);
        qDebug() << ui->endPlace->text();
    }

    //获取所选舱位信息
    if(seatType =="\u0002") sql +=QString("and seat1rest > 0 ");
    else if(seatType =="\u0001") sql +=QString("and seat2rest > 0 ");
    else sql +=QString("and seat3rest > 0 ");

    //若未改变信息，则不当为搜索条件
    if(startDate!="2000-01-01")
    {
        sql +=QString("and starttime > '%1' and starttime < '%2' ").arg(startTime).arg(endTime);     
    }

    query.exec(sql);

    //若搜索成功更新界面
    if(query.first())
    {
        qModel->setQuery(sql,db);
        qModel->removeColumn(23);
        flightId=ui->id->text();

        //  更新成员变量航班信息
        infoRefresh();
        if(query.next() == false) box.information(this,"infor","该航班可以购买");
    }
    else box.information(this,"infor","无符合条件航班或座位售空");
}


//将索引中的航班加入订单，判断是否可行
//若可行则记录买票相关信息
//将航班中对应舱位-1，总售票+1
void UserSearch::on_add_clicked()
{

    buyerName = ui->buyer->text();
    if(buyerName.isEmpty()){
        box.information(this,"infor","请输入乘机人姓名");
        return;
    }

    //判断是否有选中航班号
    if(ui->tableView->currentIndex().row() == -1)
    {
        box.information(this,"infor","请先选择航班\n(点击右侧表格内航班进行选取)");
        return;
    }

    //获取对应航班信息
    curRec = qModel->record(ui->tableView->currentIndex().row());

    //查询是否存在对应舱位
    if(curRec.value(seatIndex-1).toInt() > 0)
    {
        //存在则获取对应参数

        flightId = curRec.value(0).toString();
        company = curRec.value(1).toString();
        startPlace = curRec.value(3).toString();
        endPlace = curRec.value(4).toString();
        startTime = curRec.value(5).toDateTime().toString("yyyy-MM-dd hh:mm:ss");
        endTime = curRec.value(6).toDateTime().toString("yyyy-MM-dd hh:mm:ss");
        seatPrice = curRec.value(seatIndex).toInt();

        //判断是否存在相同订单
        sql=QString("select * from ticketselled where num ='%1' and buyer ='%2' and seattype ='%3' and buyername ='%4'")\
                .arg(flightId).arg(id).arg(seatName).arg(buyerName);
        query.exec(sql);
        if(query.first()) box.information(this,"infor","已存在相同未支付订单");
        else
        {
            //清空座位表
            sql=QString("update seattable set selled ='No'");
            query.exec(sql);
            qDebug()<<sql;

            //查找已选位置
            sql=QString("select * from ticketselled where num ='%1' and seattype ='%3'")
                    .arg(flightId).arg(seatName);
            query.exec(sql);

            //将已选位置排除
            QVector<QString> seatList;
            query.first();

            //存入已选位置
            for(int i =0;i<query.size();i++)
            {
                seatList.push_back(query.value(3).toString());
                query.next();
            }

            //从表中去除
            for(auto i:seatList)
            {
                sql=QString("update seattable set selled ='Yes' where seat ='%1'").arg(i);
                query.exec(sql);
                qDebug()<<sql << i;
            }

//            if(query.first())
//            {
//                sql=QString("update seattable set selled ='Yes' where seat ='%1'")
//                        .arg(query.value(3).toString());
//                query.exec(sql);
//                qDebug()<<sql << query.value(3).toString();

//                while(query.next())
//                {
//                    sql=QString("update seattable set selled ='Yes' where seat ='%1'")
//                            .arg(query.value(3).toString());
//                    query.exec(sql);
//                    qDebug()<<sql<< query.value(3).toString();
//                }


//            }
            //进行选座
            this->hide();
            seatTable.initialize();
            seatTable.show();

        }
    }
    else box.information(this,"infor","该航班无对应座位");

}


//打开订单界面
void UserSearch::on_userSearchBuy_clicked()
{
    this->hide();
    userTicket.id = id;
    userTicket.buyerName = buyerName;
    userTicket.initialize();
    userTicket.show();
}


//更新信息
void::UserSearch::infoRefresh()
{
    flightId=query.value(0).toString();
    company=query.value(1).toString();
}


//判断舱位信息
void UserSearch::on_seatType_currentIndexChanged(int index)
{
    if(index == 2)
    {
        seatRest = "seat1rest";
        seatName = "头等舱";
        seatIndex = 13;
    }
    else if(index == 1)
    {
        seatRest = "seat2rest";
        seatName = "商务舱";
        seatIndex = 16;
    }
    else{
        seatRest = "seat3rest";
        seatName = "经济舱";
        seatIndex = 19;
    }
}


//返回上一界面，发送此界面关闭信号
void UserSearch::on_userSearchReturn_clicked()
{
    this->hide();
    emit userSearchClose();
}

//未起飞飞机按飞机起飞时间排序
void UserSearch::on_flightTimeSort_clicked()
{
    QString curtime= QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    QString sql = QString("select * from flight where starttime > '%1' order by starttime asc").arg(curtime);
    qModel->setQuery(sql,db);
}

//未起飞飞机按飞机座位票价排序
void UserSearch::on_flightPriceSort_clicked()
{
    QString curtime= QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    QString sql = QString("select * from flight where starttime > '%1' order by seatprice3 asc").arg(curtime);
    qDebug()<<sql;
    qModel->setQuery(sql,db);
}

////进入座位选择
//void UserSearch::on_seatTable_clicked()
//{
//    //获取当前所选航班信息
//    curRec = qModel->record(ui->tableView->currentIndex().row());


//    //提示
//    box.information(this,"infor",QString("所选航班为%1").arg());

//    seatTable.initialize();
//    this->hide();
//    seatTable.show();
//}

void UserSearch::getSeat(QString seatGet)
{
    this->show();
    seat=seatGet;

    //信息加入数据库订单中
    sql = QString("insert into ticketselled (num,company,buyer,seat,seattype,\
                  seatprice,buyername,startplace,endplace,starttime,endtime)\
                  values('%1','%2','%3','%4','%5',%6,'%7','%8','%9','%10','%11')")\
                  .arg(flightId).arg(company).arg(id).arg(seat).arg(seatName).arg(seatPrice)\
                  .arg(buyerName).arg(startPlace).arg(endPlace).arg(startTime).arg(endTime);
            qDebug()<<sql<<buyerName;
    query.exec(sql);

    //将航班票减去1
    sql = QString("update flight set %1 = %1 -1 , ticketselled = ticketselled + 1,\
                  onseatrate = ticketselled/(seat1+seat2+seat3) where number = '%2'")\
            .arg(seatRest).arg(flightId);
    qDebug()<<sql;
    query.exec(sql);
    box.information(this,"infor","成功加入订单");
}
