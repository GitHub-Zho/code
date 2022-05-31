#ifndef USERINFO_H
#define USERINFO_H

#include <QWidget>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QMessageBox>
#include<QDebug>


namespace Ui {
class UserInfo;
}

class UserInfo : public QWidget
{
    Q_OBJECT

public:
    explicit UserInfo(QWidget *parent = nullptr);
    ~UserInfo();
    void initialize();

    QString id;

    QSqlDatabase db;
    QMessageBox box;

private:
    Ui::UserInfo *ui;

signals:
    void userInfoClose();

private slots:
    void on_userInfoReturn_clicked();
    void on_userInfoChange_clicked();
};

#endif // USERINFO_H
