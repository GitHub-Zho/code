#include "managerflights.h"
#include "ui_managerflights.h"

ManagerFlights::ManagerFlights(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManagerFlights)
{
    ui->setupUi(this); 
    this->setWindowTitle("航班管理(managerflights)");
}

ManagerFlights::~ManagerFlights()
{
    delete ui;
}

//界面初始化
void ManagerFlights::initialize()
{
    this->resize( QSize( 1000, 800));

    //连接数据库并显示航班
    db = QSqlDatabase::database("mybase");

    //连接数据库数据与窗口
    tModel =new QSqlTableModel(this,db);
    tModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    qModel = new QSqlQueryModel(ui->tableView);

    //显示数据库显示模式为不可修改
    ui->tableView->setModel(qModel);

    //模式为不可修改
    change = false;

    sql = QString("select * from flight where company = '%1' and setoff = 'true'").arg(company);
    qModel->setQuery(sql,db);
}


//显示所有该公司已飞航班
void ManagerFlights::on_flightAlready_clicked()
{
    //模式为不可修改
    change =false;
    ui->tableView->setModel(qModel);

    sql = QString("select * from flight where company = '%1' and setoff = 'true'").arg(company);
    qModel->setQuery(sql,db);
}


//显示该公司所有未发布航班
void ManagerFlights::on_flightReady_clicked()
{
    //模式为可修改（未发布航班）
    change =true;

    tModel->setTable("flight");
    QString sql =QString("company ='%1' and setoff = 'false'").arg(company);
    tModel->setFilter(sql);
    ui->tableView->setModel(tModel);

    //删去数据库中不可修改项
    tModel->removeColumn(10);
    tModel->removeColumn(11);
    tModel->removeColumn(13);
    tModel->removeColumn(15);
    tModel->removeColumn(16);
    tModel->removeColumn(17);
    tModel->removeColumn(17);
    tModel->select();

}


//增加数据库记录用于添加未发布航班
void ManagerFlights::on_managerFlightAdd_clicked()
{
    if(change){
        row=tModel->rowCount();
        curRec =tModel->record();
        curRec.setValue(1,company);
        tModel->insertRecord(row,curRec);
    }
    else
        box.information(this,"infor","请选择未发布航班");
}


//删除添加航班
void ManagerFlights::on_managerFlightDelete_clicked()
{
    if(change)
        tModel->removeRow(ui->tableView->currentIndex().row());
    else
        box.information(this,"infor","请选择未发布航班");
}


//撤销修改航班
void ManagerFlights::on_managerFlightRevert_clicked()
{
    tModel->revertAll();
}


//保存修改航班
void ManagerFlights::on_managerFlightPreserve_clicked()
{
    if(tModel->submitAll())
        box.information(this,"infor","成功保存");
    else
        box.information(this,"infor","请输入正确航班号");
}


//发布所选航班
void ManagerFlights::on_managerFlightSubmit_clicked()
{
    //获取当前点击选中航班索引
    curRec = tModel->record(ui->tableView->currentIndex().row());

    //判断是否有选中航班，若有则获得选中航班信息
    if(ui->tableView->currentIndex().row()==-1)
        box.information(this,"infor","请选择未发布航班");
    else if(inforCheck(curRec)){
        //传入该航班所有信息给inforCheck函数，用于判断是否全部填写
        //及判断航班号是否合理、飞行员时间地点是否冲突、数据格式是否正确


        //若返回true数据无问题发布航班
        QSqlQuery query(db);
        sql=QString("update flight set seat1rest = seat1,seat2rest = seat2,seat3rest = seat3,\
                    setoff = 'true' where number ='%1'").arg(info[0]);
        if(query.exec(sql))
            box.information(this,"infor","发布成功");
        else
            box.information(this,"infor","发布失败");

        //更新飞行员信息，增添新加航班项
        sql=QString("insert into polit (id,startplace,endplace,starttime,endtime) values('%1','%2','%3','%4','%5')")\
                .arg(info[8]).arg(info[3]).arg(info[4]).arg(info[5]).arg(info[6]);
        query.exec(sql);

        sql=QString("insert into polit (id,startplace,endplace,starttime,endtime) values('%1','%2','%3','%4','%5')")\
                .arg(info[9]).arg(info[3]).arg(info[4]).arg(info[5]).arg(info[6]);
        query.exec(sql);

    }
}


//传入该航班所有信息给inforCheck函数，用于判断是否全部填写
//及判断航班号是否合理、飞行员时间地点是否冲突、数据格式是否正确
bool ManagerFlights::inforCheck(QSqlRecord curRec)
{

    //读入所有信息
    for(int num =0;num<17;num++)
    {
        qDebug()<<curRec.value(num);
        if(curRec.value(num).isNull())
        {
            box.information(this,"infor","请填入必要信息");
            return false;
        }

    }

    //清空上一次数据
    info.clear();

    //读入数据
    for(int num =0;num<5;num++)
    {
        info.push_back(curRec.value(num).toString());
    }

    //日期特殊处理
    for(int num =5;num<7;num++)
    {
        info.push_back(curRec.value(num).toDateTime().toString("yyyy-MM-dd hh:mm:ss"));
        qDebug() <<curRec.value(num).toDateTime().toString("yyyy-MM-dd hh:mm:ss");
    }

    for(int num =7;num<17;num++)
    {
        info.push_back(curRec.value(num).toString());
    }

    //正则匹配航班格式
    QRegExp rx("[A-Z]{2}[0-9]{4}");
    if(rx.exactMatch(info[0])==false)
    {
        box.information(this,"infor","航班格式错误");
        return false;
    }

    //判断飞行员是否重复
    if(info[8] == info[9])
    {
        qDebug()<<info[8]<<info[9]<<info[6]<<info[7]<<"1231";
        box.information(this,"infor","飞行员重复");
        return false;
    }

    //传信息进入politsearch判断飞行员时间地点是否冲突
    if( (politsearch(info[8],info[5],info[6]) && politsearch(info[9],info[5],info[6]) ) ==false)
    {
        return false;
    }

    //判断准点率格式是否正确
    if(info[16].endsWith('%') ==false)
    {
        box.information(this,"infor","准点率格式错误");
        return false;
    }

    return true;
}


//判断改飞行员的时间地点是否冲突
bool ManagerFlights::politsearch(QString polit,QString startTime,QString endTime)
{
    QSqlQuery query(db);
    sql = QString("select * from polit where id ='%1' and endtime < '%2' order by endtime desc ")\
            .arg(polit).arg(endTime);
    query.exec(sql);

//    取飞行结束时间早于此次飞行结束时间的最晚的一次
//    判断此次飞行开始时间是否晚于该次飞行结束时间，若冲突则返回false
    if(query.first())
    {
        if(query.value(4)>startTime)
        {
            box.information(this,"infor",QString("飞行员'%1'有之后航班,冲突").arg(polit));
            return false;
        }
    }

    sql = QString("select * from polit where id ='%1' and starttime > '%2' order by starttime asc ")\
            .arg(polit).arg(startTime);
    query.exec(sql);

//    取飞行开始时间晚于此次飞行开始时间的最早的一次
//    判断此次飞行结束时间是否早于该次飞行开始时间，若冲突则返回false
    if(query.first())
    {
        if(query.value(3)<endTime)
        {
            box.information(this,"infor",QString("飞行员'%1'有之前航班,冲突").arg(polit));
            return false;
        }
    }
    return true;
}

//返回上一级
void ManagerFlights::on_managerFlightReturn_clicked()
{
    this->hide();
    emit managerFlightsClose();
}

//void ManagerFlightAdd::on_search_clicked()
//{

//    QSqlQuery query(db);

//    if(id.isEmpty() || startPlace.isEmpty() || endPlace.isEmpty() || polit1.isEmpty() || polit2.isEmpty()){
//        box.information(this,"infor","请填入必要信息");
//    }
//    else{
//        sql =QString("select * from flight where id ='%1'").arg(id);
//        query.exec(sql);
//        if(query.first()){
//            box.information(this,"infor","航班号已存在");
//        }
//        else{
//            //若两飞行员不冲突则添加允许添加飞行
//            if(politsearch(polit1) && politsearch(polit2)){
//                //发送信号添加进预备发布
//                emit addFlight();
//            }
//        }

//    }
    /*QString sql = QString("select * from managers where id = '%1'").arg(id);
    query.exec(sql);
    query.first();
    qDebug()<< query.value(4).toString() << password;
    if(query.value(4).toString() == password){
        emit success(query.value(0).toString(),query.value(1).toString());
    }*/
//}

//    else  box.information(this,"infor","该订单已支付");
//    else{
//        QSqlQuery query(db);
//        flight=curRec.value(0).toString();
//        seatType =curRec.value(3).toString();
//        seatPrice = curRec.value(4).toString();
//        if(seatType =="头等舱") seatTypeIndex ="1";
//        else if(seatType =="经济舱") seatTypeIndex ="3";
//        else seatTypeIndex ="2";
//        sql = QString("select * from flight where number ='%1'").arg(flight);
//        query.exec(sql);
//        query.first();
//        qDebug()<<flight<<query.value(3).toString()<<query.value(5).toString()<<query.value(4).toString()<<query.value(6).toString()<<seatPrice;
//        pay.initialize(flight,query.value(3).toString(),query.value(4).toString(),query.value(5).toDateTime().toString("yyyy-MM-dd hh:mm:ss"),query.value(6).toDateTime().toString("yyyy-MM-dd hh:mm:ss"),seatPrice);
//        pay.show();
//        this->hide();
//    }


