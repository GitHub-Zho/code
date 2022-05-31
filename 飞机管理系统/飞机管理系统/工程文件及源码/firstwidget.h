#ifndef FIRSTWIDGET_H
#define FIRSTWIDGET_H

#include <QWidget>
#include <QDesktopWidget>
#include"database.h"
#include"checkbox.h"
#include"managerpage.h"
#include"usersearch.h"


QT_BEGIN_NAMESPACE
namespace Ui { class FirstWidget; }
QT_END_NAMESPACE

class FirstWidget : public QWidget
{
    Q_OBJECT

public:
    FirstWidget(QWidget *parent = nullptr);
    ~FirstWidget();

    void initialize();
    void databaseCheck(QString Id,QString password,QString name);

    QString id;

    QSqlDatabase db;

    //判断是否连接数据库
    bool dbConnect = false;

private slots:
    void on_managerLogin_clicked();

    void thisShow();

    void managerLogin(QString id,QString company);

    void userLogin(QString id);

    void on_userLogin_clicked();

    void on_database_clicked();

private:
    Ui::FirstWidget *ui;
    Database database;
    CheckBox checkBox;
    ManagerPage managerpage;
    UserSearch userSearch;

};
#endif // FIRSTWIDGET_H
