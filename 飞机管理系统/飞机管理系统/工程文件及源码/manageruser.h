#ifndef MANAGERUSER_H
#define MANAGERUSER_H

#include <QWidget>
#include<QDateTime>
#include<QSqlDatabase>
#include<QSqlTableModel>
#include<QDebug>

namespace Ui {
class ManagerUser;
}

class ManagerUser : public QWidget
{
    Q_OBJECT

public:
    explicit ManagerUser(QWidget *parent = nullptr);
    ~ManagerUser();

    QString id;
    QString company;

private slots:
    void on_managerUserTicket_clicked();

    void on_managerUserReturn_clicked();

    void on_managerUserOff_clicked();

    void on_managerUserSet_clicked();

    void on_managerUserPrice_clicked();

private:
    Ui::ManagerUser *ui;
    QSqlDatabase db;
    QSqlTableModel *model;
    QSqlQueryModel *query;
    QDateTime curDateTime;

signals:
    void managerUserClose();
};

#endif // MANAGERUSER_H
