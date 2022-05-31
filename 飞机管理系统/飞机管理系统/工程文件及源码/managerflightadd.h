#ifndef MANAGERFLIGHTADD_H
#define MANAGERFLIGHTADD_H

#include <QWidget>
#include<QSqlDatabase>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QDateTime>
#include<QMessageBox>

namespace Ui {
class ManagerFlightAdd;
}

class ManagerFlightAdd : public QWidget
{
    Q_OBJECT

public:
    explicit ManagerFlightAdd(QWidget *parent = nullptr);
    ~ManagerFlightAdd();
    bool politsearch(QString polit);
    QString company;
    QString id;
    QString startPlace;
    QString endPlace;
    QString polit1;
    QString polit2;
    QString startTime;
    QString endTime;
    QString sql;
    QMessageBox box;



private:
    Ui::ManagerFlightAdd *ui;
    QSqlDatabase db;

signals:
    void managerFlightAddClose();
    void addFlight();

private slots:

    void on_return_2_clicked();
    void on_search_clicked();
};

#endif // MANAGERFLIGHTADD_H
