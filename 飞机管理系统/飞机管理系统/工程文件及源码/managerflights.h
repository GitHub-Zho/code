#ifndef MANAGERFLIGHTS_H
#define MANAGERFLIGHTS_H

#include <QWidget>
#include <QSqlDatabase>
#include<QSqlTableModel>
#include<QSqlQueryModel>
#include<QSqlRecord>
#include <QSqlQuery>
#include <QDateTime>
#include<QMessageBox>
#include<QDebug>

namespace Ui {
class ManagerFlights;
}

class ManagerFlights : public QWidget
{
    Q_OBJECT

public:
    explicit ManagerFlights(QWidget *parent = nullptr);
    ~ManagerFlights();

    int row;
    bool change;

    QString company;
    QString sql;

    //用于存储用户信息
    QVector<QString> info;

    QMessageBox box;

    QSqlDatabase db;
    QSqlRecord curRec;
    QSqlTableModel *tModel;
    QSqlQueryModel *qModel;

    void initialize();
    void getFlight(QSqlQuery query);

    bool inforCheck(QSqlRecord curRec);
    bool politsearch(QString polit,QString startTime,QString endTime);

private:
    Ui::ManagerFlights *ui;

signals:
    void managerFlightsClose();

private slots:
    void on_flightAlready_clicked();
    void on_flightReady_clicked();
    void on_managerFlightAdd_clicked();
    void on_managerFlightDelete_clicked();
    void on_managerFlightSubmit_clicked();
    void on_managerFlightRevert_clicked();
    void on_managerFlightPreserve_clicked();
    void on_managerFlightReturn_clicked();
};

#endif // MANAGERFLIGHTS_H
