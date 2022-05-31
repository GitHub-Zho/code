#ifndef USERTICKET_H
#define USERTICKET_H

#include"pay.h"

#include <QWidget>
#include<QSqlDatabase>
#include<QSqlQueryModel>
#include<QItemSelectionModel>
#include<QSqlQuery>
#include<QMessageBox>
#include<QSqlRecord>
#include<QDate>
#include<QDebug>

namespace Ui {
class UserTicket;
}

class UserTicket : public QWidget
{
    Q_OBJECT

public:
    explicit UserTicket(QWidget *parent = nullptr);
    ~UserTicket();

    QDate date;
    QString id;
    QString sql;
    QString buyerName;
    QString flight;
    QString seatType;
    QString seatTypeIndex;
    QString seatPrice;
    QString seat;

    QMessageBox box;

    QSqlDatabase db;
    QSqlQueryModel *qModel;
    QItemSelectionModel *sModel;
    QModelIndexList list;
    QSqlRecord curRec;

    int restTicket;

    bool seatChoose = false;

    void initialize();
    void finishPay();
    void canclePay();
    void thisShow();



private:
    Ui::UserTicket *ui;
    Pay pay;


signals:
    void userTicketClose();

private slots:   
    void on_history_clicked();
    void on_unPay_clicked();
    void on_buy_clicked();
    void on_userTicketSearch_clicked();
    void on_userTicketReturn_clicked();
};

#endif // USERTICKET_H
