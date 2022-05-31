#ifndef MANAGERINFO_H
#define MANAGERINFO_H

#include <QWidget>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QDebug>
#include<QMessageBox>

namespace Ui {
class ManagerInfo;
}

class ManagerInfo : public QWidget
{
    Q_OBJECT

public:
    explicit ManagerInfo(QWidget *parent = nullptr);
    ~ManagerInfo();

    void initialize();

    QString id; 

private slots:
    void on_managerInfoReturn_clicked();

    void on_managerInfoChange_clicked();

private:
    Ui::ManagerInfo *ui;
    QSqlDatabase db;
    QMessageBox box;


signals:
    void managerInfoClose();
};

#endif // MANAGERINFO_H
