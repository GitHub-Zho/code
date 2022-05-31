#ifndef DATABASE_H
#define DATABASE_H

#include <QWidget>


namespace Ui {
class Database;
}

class Database : public QWidget
{
    Q_OBJECT

public:
    explicit Database(QWidget *parent = nullptr);
    ~Database();

private:
    Ui::Database *ui;

signals:
    void getBase(QString Id,QString password,QString name);
private slots:
    void on_databaseReturn_clicked();
    void on_databaseConnect_clicked();
};

#endif // DATABASE_H
