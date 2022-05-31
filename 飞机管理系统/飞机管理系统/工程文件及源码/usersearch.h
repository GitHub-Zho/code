#ifndef USERSEARCH_H
#define USERSEARCH_H
#include"userinfo.h"
#include"userticket.h"
#include"seattable.h"
#include <QWidget>
#include<QSqlDatabase>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QSqlRecord>
#include<QMessageBox>
#include<QDebug>

namespace Ui {
class UserSearch;
}

class UserSearch : public QWidget
{
    Q_OBJECT

public:
    explicit UserSearch(QWidget *parent = nullptr);
    ~UserSearch();
    void thisShow();
    void initialize();
    void infoRefresh();
    void getSeat(QString seatGet);

    QString id;
    QString date;
    QString company;
    QString planeType;
    QString seatType;
    QString startPlace;
    QString endPlace;
    QString startTime;
    QString startDate;
    QString endTime;
    QString flightId;
    QString sql;
    QString seatRest;
    QString seatName;
    QString buyerName;
    QString seatId;
    QString seat;

    QMessageBox box;

    QSqlDatabase db;
    QSqlQueryModel *qModel;
    QSqlQuery query;
    QSqlRecord curRec;

    int seatPrice;
    int seatIndex;

    bool search =false;
    bool seatChoose = false;

private:
    Ui::UserSearch *ui;
    UserInfo userInfo;
    UserTicket userTicket;
    SeatTable seatTable;

signals:
    void userSearchClose();

private slots:
    void on_userSearchReturn_clicked();
    void on_userInfo_clicked();
    void on_userSearch_clicked();
    void on_add_clicked();
    void on_userSearchBuy_clicked();
    void on_seatType_currentIndexChanged(int index);
    void on_flightTimeSort_clicked();

    void on_flightPriceSort_clicked();
//    void on_seatTable_clicked();
};

#endif // USERSEARCH_H
