#ifndef MANAGERPAGE_H
#define MANAGERPAGE_H

#include <QWidget>
#include"manageruser.h"
#include"managerflights.h"
#include"managerinfo.h"

namespace Ui {
class ManagerPage;
}

class ManagerPage : public QWidget
{
    Q_OBJECT

public:
    explicit ManagerPage(QWidget *parent = nullptr);
    ~ManagerPage();
    QString id;
    QString company;
    void thisShow();


private slots:
    void on_managerPageReturn_clicked();

    void on_managerPageUser_clicked();

    void on_managerPageFlight_clicked();

    void on_managerPageInfo_clicked();

private:
    Ui::ManagerPage *ui;
    ManagerUser managerUser;
    ManagerFlights managerFlights;
    ManagerInfo managerInfo;

signals:
    void closeManagerPage();
};

#endif // MANAGERPAGE_H
