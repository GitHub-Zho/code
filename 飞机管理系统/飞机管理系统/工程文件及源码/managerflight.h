#ifndef MANAGERFLIGHT_H
#define MANAGERFLIGHT_H

#include <QWidget>
#include "managerflightadd.h"

namespace Ui {
class ManagerFlight;
}

class ManagerFlight : public QWidget
{
    Q_OBJECT

public:
    explicit ManagerFlight(QWidget *parent = nullptr);
    ~ManagerFlight();
    QString company;
    void thisShow();

private:
    Ui::ManagerFlight *ui;
    ManagerFlightAdd managerFlightAdd;
signals:
    void managerFlightClose();


private slots:
    void on_ManagerFlightReturn_clicked();
    void on_ManagerFlightFind_clicked();
    void on_managerFlightReturn_clicked();
    void getFlight(QSqlQuery query);
    void on_flightAlready_clicked();
    void on_managerFlightFind_clicked();
    void on_managerFlightDelete_clicked();
};

#endif // MANAGERFLIGHT_H
